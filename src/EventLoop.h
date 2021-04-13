//
// Created by txy on 2021/3/12.
// 单例模式

#ifndef YM_SERVER_2_0_EVENTLOOP_H
#define YM_SERVER_2_0_EVENTLOOP_H
#include "uv.h"
#include "thread"
#include "atomic"
#include "functional"

using namespace std;

typedef function<void()> DefaultCallback;

class Async; // 异步回调
class EventLoop {
public:
    enum Mode{
        Default,
        New
    };
    enum Status{
        NotRun,
        Runed,
        Stop
    };
    EventLoop();
    ~EventLoop();

    static EventLoop* DefaultLoop();

    int run();
    int runNoWait();
    int stop();
    bool isStop();
    Status getStatus();
    bool isRunInLoopThread();
    void runInThisLoop(const DefaultCallback callback);
    uv_loop_t* handle();

    static const char* GetErrorMessage(int status);
private:
    EventLoop(Mode mode);

    thread::id loopThread_;
    uv_loop_t *loop_;
    Async* async_;
    atomic<Status> status_; // 状态 原子修改
};


#endif //YM_SERVER_2_0_EVENTLOOP_H
