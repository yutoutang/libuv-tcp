//
// Created by txy on 2021/4/8.
//
#include "../../src/http/HttpServer.h"

using namespace std;

void func1(Request& req, Response* resp){
    resp->setVersion(HttpVersion::Http1_1);
    resp->setStatus(StatusCode::OK, "OK");
    resp->appendHead("Server", "YM"); // && 右值引用，可以之间传变量
    string s = "hello world";
    resp->swapContent(s);
}

void func2(Request& req, Response* resp){
    resp->setVersion(HttpVersion::Http1_1);
    resp->setStatus(StatusCode::OK, "OK");
    string ss = req.getUrlParam("id") + " " + req.getUrlParam("age");
    resp->swapContent(ss);
}

int main(){
    EventLoop loop;
    HttpServer server(&loop);

    server.Get("/hello", bind(&func1 ,placeholders::_1, placeholders::_2));
    server.Get("/test", bind(&func2, placeholders::_1, placeholders::_2));

    InetAddress addr(9000);
    server.bindAndListen(addr);
    loop.run();
}
