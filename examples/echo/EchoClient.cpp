//
// Created by txy on 2021/3/30.
//

#include "EchoClient.h"


EchoClient::EchoClient(EventLoop *loop) : TcpClient(loop) {
    setConnectStatusCallback(bind(&EchoClient::onConnect, this, placeholders::_1));
    setMessageCallback(bind(&EchoClient::onMessageCallback, this, placeholders::_1, placeholders::_2));
}

void EchoClient::connectToServer(InetAddress &addr) {
    sockAddrPtr_ = make_shared<InetAddress>(addr);
    connect(addr);
}

void EchoClient::reConnect() {

}

void EchoClient::onConnect(ConnectionStatus status) {
    // TcpClient::onConnect 中 runConnectCallback(ConnectionStatus::Success) 执行的回调函数
    if (status == ConnectionStatus::Success){
        string str = "connect to " + sockAddrPtr_->toIpPort() + " success";
        LogWriter::Instance()->info(str);
//        write("" , 1);
        Packet packet;
        char data[1024] = "xxx";
        packet.pack(data, sizeof(data));
        write(packet.Buffer().c_str(), packet.PacketSize()); // 写包数据
    } else if (status == ConnectionStatus::Fail){
        LogWriter::Instance()->info("connect fail");
    }
}

// 回调无法触发
void EchoClient::onMessageCallback(const char* buf, ssize_t size) {
    if (size != 0)
        cout << string(buf,0, size) << endl;
    Packet packet;
    packet.pack(buf, sizeof(buf));
    write(packet.getData(), packet.PacketSize());
}
