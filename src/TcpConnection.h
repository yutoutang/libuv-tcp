//
// Created by txy on 2021/3/12.
//

#ifndef YM_SERVER_2_0_TCPCONNECTION_H
#define YM_SERVER_2_0_TCPCONNECTION_H
#include "memory"
#include "chrono"
#include "functional"
#include "atomic"
#include "string"

#include "EventLoop.h"
#include "InetAddress.h"
#include "ListBuffer.h"

#include "sys/msg.h"

// 封装写对象
struct WriteInfo{
    static const int Disconnected = -1;
    int status;
    char* buf;
    unsigned long size;
};

class TcpConnection;
class TcpServer;
class ConnectionWrapper;

typedef shared_ptr<TcpConnection> TcpConnectionPtr;
typedef shared_ptr<ConnectionWrapper> ConnectionWrapperPtr;
typedef function<void(WriteInfo&)> AfterWriteCallback;
typedef function<void(TcpConnectionPtr, const char*, ssize_t)> OnMessageCallback; // TcpServer::OnMessage
typedef function<void(string&)> OnCloseCallback;
typedef function<void(string&)> CloseCompleteCallback;

class TcpConnection : public enable_shared_from_this<TcpConnection>{
public:
    TcpConnection(EventLoop *loop, const string& name, TcpPtr client, bool isConnected = true);
    virtual ~TcpConnection();

    void onSocketClose();
    void close(OnCloseCallback callback);

    int write(const char* buf, ssize_t size, AfterWriteCallback callback);
    void writeInLoop(const char* buf, ssize_t size, AfterWriteCallback callback);

    void setWrapper(shared_ptr<ConnectionWrapper> wrapper);
    shared_ptr<ConnectionWrapper> getWrapper();

    void setMessageCallback(OnMessageCallback callback);
    void setConnectCloseCallback(OnCloseCallback callback);

    void setConnectStatus(bool status);
    bool isConnected;

    const string& getName();
    PacketBufferPtr getBuffer();
private:
    void onMessage(const char* buf, ssize_t size);
    void closeComplete();
    char* resizeData(size_t size);
    static void onMessageReceive(uv_stream_t* client, ssize_t nread, const uv_buf_t* buf);

private:
    string name_;
    bool connected_;
    EventLoop* loop_;
    TcpPtr handle_;
    string data_;
    PacketBufferPtr buffer_;
    weak_ptr<ConnectionWrapper> wrapper_;

    OnMessageCallback onMessageCallback_;
    OnCloseCallback onCloseCallback_;
    CloseCompleteCallback closeCompleteCallback_;
};

class ConnectionWrapper : public enable_shared_from_this<ConnectionWrapper>{
public:
    ConnectionWrapper(TcpConnectionPtr connection) : connection_(connection){}
    ~ConnectionWrapper(){
        TcpConnectionPtr connection = connection_.lock();
        if (connection){
            connection->onSocketClose();
        }
    }
private:
    weak_ptr<TcpConnection> connection_;
};


#endif //YM_SERVER_2_0_TCPCONNECTION_H
