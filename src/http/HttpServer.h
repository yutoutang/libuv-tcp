//
// Created by txy on 2021/4/8.
//

#ifndef UV_TCP_HTTPSERVER_H
#define UV_TCP_HTTPSERVER_H
#include <utility>
#include "../TcpServer.h"
#include "Request.h"
#include "Response.h"
#include "RadixTree.h"
#include "map"
#include "functional"

using namespace std;

typedef function<void(Request&, Response*)> OnHttpReqCallback;

class HttpServer: public TcpServer {
public:
    explicit HttpServer(EventLoop* loop);
    void Get(const string& path, OnHttpReqCallback callback);
private:
    void onMessage(TcpConnectionPtr conn, const char* buf, ssize_t size);
    void onNewConnection(weak_ptr<TcpConnection> connection);
    void onCloseConnection(weak_ptr<TcpConnection> connection);

    RadixTree<OnHttpReqCallback> route_[Method::Valid]; // 根据请求 method -> (path, 回调函数)
    int count_;
};


#endif //UV_TCP_HTTPSERVER_H
