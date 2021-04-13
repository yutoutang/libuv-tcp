//
// Created by txy on 2021/3/27.
//
#include "../src/Timer.h"
#include "iostream"

int main(){
    EventLoop* loop = new EventLoop();
    Timer timer(loop, 1000, 1000, [](Timer*){
        cout << "timer callback test" << endl;
    });
    timer.start();

    // 定时器只运行一次释放，用于 tcp 重连
    Timer* pTimer = new Timer(loop, 1000, 0, [](Timer *handle){
       cout << "timer callback run once" << endl;
       handle->close([](Timer* ptr){
          cout << "release timer ptr" << endl;
          delete ptr;
       });
    });
    pTimer->start();

    loop->run();
}
