//
// Created by txy on 2021/3/30.
//

#ifndef UV_TCP_ECHOCLIENT_H
#define UV_TCP_ECHOCLIENT_H
#include "../../src/TcpClient.h"
#include "../../src/Packet.h"

class EchoClient: public TcpClient {
public:
    EchoClient(EventLoop* loop);

    void connectToServer(InetAddress& addr);

    void reConnect();
    void onConnect(ConnectionStatus status);
    void onMessageCallback(const char* buf, ssize_t data);
private:
    shared_ptr<InetAddress> sockAddrPtr_;
};


#endif //UV_TCP_ECHOCLIENT_H
