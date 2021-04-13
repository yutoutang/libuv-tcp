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

// 比较蠢的方法
struct RouteInfo{
    string path;
    OnHttpReqCallback callback;
    RouteInfo(string p, OnHttpReqCallback c): path(move(p)), callback(move(c)){};
};

class HttpServer: public TcpServer {
public:
    explicit HttpServer(EventLoop* loop);
    void Get(const string& path, OnHttpReqCallback callback);
private:
    void onMessage(TcpConnectionPtr conn, const char* buf, ssize_t size);

    map<Method, vector<RouteInfo>> route_; // 根据请求 method -> (path, 回调函数)
};


#endif //UV_TCP_HTTPSERVER_H
