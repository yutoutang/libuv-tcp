//
// Created by txy on 2021/2/8.
//
#include "InetAddress.h"
#include "cassert"

#include "arpa/inet.h"
#include "netdb.h"

InetAddress::InetAddress(const string& ip, uint16_t port) {
    setPort(port);
    int res = 0;
    // strchr 匹配是否包含 : 字符
    // inet_pton 将字符串 ip 地址转换为 二进制字节序
    if (strchr(ip.c_str(), ':') == nullptr){
        res = ::inet_pton(AF_INET, ip.c_str(), &addr_.sin_addr);
    } else {
        res = ::inet_pton(AF_INET6, ip.c_str(), &addr_.sin_addr);
    }
    assert(res == 1);
}

InetAddress::InetAddress(uint16_t port, bool ipv6) {
    bool loopbackOnly = false;
    if (ipv6){
        memset(&addr6_, 0,sizeof addr6_);
        addr6_.sin6_family = AF_INET6;
        addr6_.sin6_port = htons(port);
        in6_addr ip = loopbackOnly ? in6addr_loopback : in6addr_any; // 本机 or 外部
        addr6_.sin6_addr = ip; // ipv6
    } else {
        memset(&addr_, 0, sizeof addr_);
        addr_.sin_family = AF_INET;
        addr_.sin_port = htons(port);
        in_addr_t ip = loopbackOnly ? INADDR_LOOPBACK : INADDR_ANY;
        addr_.sin_addr.s_addr = htonl(ip); // ipv4
    }
}

InetAddress::InetAddress(struct sockaddr& saddr) {
    // sockaddr 结构体中有 sa_family 和 sa_data（源地址 + 目标地址） 通用地址结构
    // sockaddr_in 网络地址结果
    if (saddr.sa_family == AF_INET){
        memcpy(&addr_, &saddr, sizeof addr_); // 拷贝
    } else if (saddr.sa_family == AF_INET6){
        memcpy(&addr6_, &saddr, sizeof addr6_);
    }
}



std::string InetAddress::toIp() const {
    char buf[64] = "";
    if (family() == AF_INET){
        ::inet_ntop(AF_INET, &addr_.sin_addr, buf, static_cast<socklen_t>(sizeof buf));
    } else if (family() == AF_INET6){
        ::inet_ntop(AF_INET6, &addr6_.sin6_addr, buf, static_cast<socklen_t>(sizeof buf));
    }
    return buf;
}

std::string InetAddress::toIpPort() const {
    char buf[32] = "";
    snprintf(buf, sizeof buf, ":%u", port()); // :port
    return toIp() + buf;
}

bool InetAddress::operator==(const InetAddress &rhs) const {
    if (family() == rhs.family()){
        if (family() == AF_INET){
            return addr_.sin_port == rhs.addr_.sin_port and addr_.sin_addr.s_addr == rhs.addr_.sin_addr.s_addr;
        } else if (family() == AF_INET6){
            return addr6_.sin6_port == rhs.addr6_.sin6_port and memcmp(&addr6_.sin6_addr, &rhs.addr6_.sin6_addr, sizeof addr6_.sin6_addr) == 0;
        }
    }
    return false;
}

bool InetAddress::resolve(const string& hostname, uint16_t port, InetAddress *out) {
    assert(out);
    std::vector<InetAddress> addrs = resolveAll(hostname, port);

    if (addrs.empty())
        return false;

    // 连接地址
    *out = addrs[0];

    return true;
}

std::vector<InetAddress> InetAddress::resolveAll(const string& hostname, uint16_t port) {
    std::vector<InetAddress> addrs;

    struct addrinfo* result = NULL;
    int error = getaddrinfo(hostname.c_str(), NULL, NULL, &result);
    if (error != 0)
    {
        if (error == EAI_SYSTEM)
        {
            perror("InetAddress::resolve");
        }
        else
        {
            fprintf(stderr, "InetAddress::resolve: %s\n", gai_strerror(error));
        }
        return addrs;
    }

    assert(result);
    std::unique_ptr<struct addrinfo, decltype(&freeaddrinfo)> freeResult(result, freeaddrinfo);

    for (struct addrinfo* ai = result; ai != NULL; ai = ai->ai_next)
    {
        InetAddress addr(*ai->ai_addr);
        addr.setPort(port);
        addrs.push_back(addr);
    }
    return addrs;
}


InetAddress::InetAddress(uv_tcp_t *client) {
    sockaddr addr{};
    int l = sizeof(addr);
    uv_tcp_getpeername(client, (sockaddr*)&addr, &l);
    if (addr.sa_family == AF_INET){
        memcpy(&addr_, &addr, sizeof addr_); // 拷贝
    } else if (addr.sa_family == AF_INET6){
        memcpy(&addr6_, &addr, sizeof addr6_);
    }
}
