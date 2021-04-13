//
// Created by txy on 2021/3/29.
//

#ifndef UV_TCP_ECHOSERVER_H
#define UV_TCP_ECHOSERVER_H
#include "../../src/TcpServer.h"
#include "../../src/Packet.h"

class EchoServer: public TcpServer {
public:
    EchoServer(EventLoop* loop);
private:
    void newMessage(TcpConnectionPtr connection, const char* buf, ssize_t size);
    void newConnection(weak_ptr<TcpConnection> connection);
    void connectClose(weak_ptr<TcpConnection> connection);
    int count_;
};


#endif //UV_TCP_ECHOSERVER_H
