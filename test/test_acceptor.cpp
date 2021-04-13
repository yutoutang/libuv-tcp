//
// Created by txy on 2021/3/25.
//
#include "../src/InetAddress.h"
#include "../src/EventLoop.h"
#include "../src/TcpAcceptor.h"

int main(){
    InetAddress addr(9000);
    EventLoop* loop = EventLoop::DefaultLoop();
    TcpAcceptor acceptor(loop);
    acceptor.bind(addr);
    acceptor.listen();
    loop->run();
}
