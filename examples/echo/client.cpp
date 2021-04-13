//
// Created by txy on 2021/3/30.
//
#include "EchoClient.h"

using namespace std;

int main(){
    EventLoop* loop = EventLoop::DefaultLoop();
    EchoClient client(loop);
//
    InetAddress addr(9000);
    client.connectToServer(addr);


    loop->run();
}

