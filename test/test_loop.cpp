//
// Created by txy on 2021/3/23.
//
#include "../src/EventLoop.h"
#include "iostream"
#include "unistd.h"

using namespace std;

void my_callback(){
    printf("i am callback\n");
}

void thread_work(EventLoop* loop){
    loop->runInThisLoop(my_callback);
}

int main(){
    EventLoop* loop = new EventLoop();
    loop->runInThisLoop(
            []()
            {
                cout << "run function in loop thread one." << endl;
            });
    loop->runInThisLoop(my_callback);
    loop->run();
//    sleep(10);
}
