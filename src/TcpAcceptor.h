//
// Created by txy on 2021/3/12.
//

#ifndef YM_SERVER_2_0_TCPACCPTER_H
#define YM_SERVER_2_0_TCPACCPTER_H
#include "functional"
#include "EventLoop.h"
#include "InetAddress.h"


typedef function<void(EventLoop*, TcpPtr)> NewConnectionCallback;

class TcpAcceptor {
public:
    explicit TcpAcceptor(EventLoop* loop);

    virtual ~TcpAcceptor();

    int bind(InetAddress& addr);
    int listen();
    void close(DefaultCallback callback);
    void setNewConnectionCallback(NewConnectionCallback callback);

    EventLoop* loop();
private:
    void onNewConnect(TcpPtr client);
    void onCloseComplete();

    bool listened_;
    EventLoop* loop_;
    NewConnectionCallback callback_;
    DefaultCallback onCloseCompleteCallback_;
    uv_tcp_t server_;
};


#endif //YM_SERVER_2_0_TCPACCPTER_H
