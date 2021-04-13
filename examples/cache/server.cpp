//
// Created by txy on 2021/4/12.
//
#include "CacheServer.h"

using namespace std;

int main(){
    EventLoop* loop = EventLoop::DefaultLoop();
    CacheServer server(loop);

    InetAddress address(9000);
    server.bindAndListen(address);

    loop->run();
}
