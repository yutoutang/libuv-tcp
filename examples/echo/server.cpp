//
// Created by txy on 2021/3/29.
//
#include "EchoServer.h"
#include "EchoClient.h"

int main(){
    EventLoop* loop = EventLoop::DefaultLoop();
    EchoServer server(loop);

    InetAddress addr(9000);
    server.bindAndListen(addr);

//    EchoClient client(loop);
//    client.connectToServer(addr);

    loop->run();
}
