//
// Created by txy on 2021/3/12.
//

#ifndef YM_SERVER_2_0_TCPSERVER_H
#define YM_SERVER_2_0_TCPSERVER_H
#include "functional"
#include "memory"
#include "set"
#include "map"

#include "TcpAcceptor.h"
#include "TimerWheel.h"
#include "TcpConnection.h"
#include "LogWriter.h"

typedef function<void(weak_ptr<TcpConnection>)> OnConnectionStatusCallback;

class TcpServer {
public:
    TcpServer(EventLoop* loop);
    virtual ~TcpServer();
    int bindAndListen(InetAddress& addr);
    void close(const DefaultCallback& callback);

    TcpConnectionPtr getConnection(const string& name);
    void closeConnection(string& name);

    void setNewConnectionCallback(OnConnectionStatusCallback callback);
    void setConnectionCloseCallback(OnConnectionStatusCallback callback);

    void setMessageCallback(OnMessageCallback callback);

    void write(const TcpConnectionPtr& connection, const char* buf, unsigned int size, AfterWriteCallback callback = nullptr);
    void write(string& name, const char* buf, unsigned int size, AfterWriteCallback callback = nullptr);
    void writeInLoop(const TcpConnectionPtr& connection, const char* buf, unsigned int size, AfterWriteCallback callback);
    void writeInLoop(string& name, const char* buf, unsigned int size, AfterWriteCallback callback);

    void setTimeout(unsigned int timeout);

private:
    void onAccept(EventLoop* loop, const TcpPtr& client);
    void removeConnection(string& name);
    void onMessage(const TcpConnectionPtr& connection, const char* buf, ssize_t size);

protected:
    EventLoop* loop_;
private:
    shared_ptr<TcpAcceptor> acceptor_;
    map<string, TcpConnectionPtr> connections_;

    OnMessageCallback onMessageCallback_;
    OnConnectionStatusCallback onNewConnectionCallback_;
    OnConnectionStatusCallback onCloseConnectionCallback_;

    TimeWheel<ConnectionWrapper> timeWheel_;
};


#endif //YM_SERVER_2_0_TCPSERVER_H
