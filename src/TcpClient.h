//
// Created by txy on 2021/3/29.
//

#ifndef UV_TCP_TCPCLIENT_H
#define UV_TCP_TCPCLIENT_H
#include "TcpConnection.h"
#include "LogWriter.h"
#include "Timer.h"

enum ConnectionStatus{
    Success,
    Fail,
    Close
};

typedef function<void(const char*, ssize_t)> NewMessageCallback;
typedef function<void(ConnectionStatus)> ConnectStatusCallback;


class TcpClient {
public:
    typedef function<void(TcpClient*)> ConnectCloseCallback;
    TcpClient(EventLoop* loop);
    virtual ~TcpClient();

    void connect(InetAddress& addr);
    void close(ConnectCloseCallback callback);

    void write(const char* buf, unsigned int size, AfterWriteCallback callback = nullptr);
    void writeInLoop(const char* buf, unsigned int size, AfterWriteCallback callback);

    void setConnectStatusCallback(ConnectStatusCallback callback);
    void setMessageCallback(NewMessageCallback callback);

    EventLoop* Loop();
protected:
    EventLoop* loop_;

    void onConnect(bool flag);
    void onConnectClose(const string& name);
    void onMessage(TcpConnectionPtr conn, const char* buf, ssize_t size);
    void afterConnectFail();
private:
    TcpPtr socket_;
    uv_connect_t *connect_;

    TcpConnectionPtr connection_;

    ConnectStatusCallback connectStatusCallback_;
    NewMessageCallback onMessageCallback_;

    void update();
    void runConnectCallback(ConnectionStatus status);
    void onClose(const string& name);
};

typedef shared_ptr<TcpClient> TcpClientPtr;

#endif //UV_TCP_TCPCLIENT_H
