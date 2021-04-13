//
// Created by txy on 2021/2/8.
//

#ifndef YM_SERVER_2_0_INETADDRESS_H
#define YM_SERVER_2_0_INETADDRESS_H
#include "Common.h"

#include "string"
#include "vector"

#include "netinet/in.h"

typedef shared_ptr<uv_tcp_t> TcpPtr; // 管理一个连接

class InetAddress {
public:
    InetAddress() { addr_.sin_family = AF_UNSPEC; }
    InetAddress(const string& ip, uint16_t port);
    InetAddress(uv_tcp_t *client);
    explicit InetAddress(uint16_t port, bool ipv6 = false);
    explicit InetAddress(struct sockaddr& saddr);

    sa_family_t family() const { return addr_.sin_family; }
    uint16_t port() const { return ntohs(addr_.sin_port); }
    void setPort(uint16_t port) { addr_.sin_port = port; }

    std::string toIp() const;
    std::string toIpPort() const;

    const struct sockaddr* get_sockaddr() const {
        switch (family()) {
            case AF_INET:
                return reinterpret_cast<const sockaddr*>(&addr_);
            case AF_INET6:
                return reinterpret_cast<const sockaddr*>(&addr6_);
        }
        return reinterpret_cast<const sockaddr*>(&addr_);
    }

    socklen_t length() const{
        switch (family()) {
            case AF_INET:
                return sizeof addr_;
            case AF_INET6:
                return sizeof addr6_;
        }
        return sizeof addr_;
    }

    bool operator==(const InetAddress& rhs) const;

    static bool resolve(const string &hostname, uint16_t port, InetAddress*);
    static std::vector<InetAddress> resolveAll(const string & hostname, uint16_t port = 0);

private:
    union {
        struct sockaddr_in addr_;
        struct sockaddr_in6 addr6_;
    };

};


#endif //SOCKET_LEARNING_INETADDRESS_H
