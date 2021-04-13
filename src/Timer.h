//
// Created by txy on 2021/3/26.
//

#ifndef UV_TCP_TIMER_H
#define UV_TCP_TIMER_H
#include "mutex"
#include "functional"
#include "EventLoop.h"

class Timer {
public:
    typedef function<void(Timer*)> TimerCallback;
    typedef function<void(Timer*)> TimerCloseComplete;

    Timer(EventLoop* loop, uint64_t timeout, uint64_t repeat, TimerCallback callback);
    virtual ~Timer();

    void start();
    void close(TimerCloseComplete callback);

private:
    void onTimeout();
    void closeComplete();

    static void process(uv_timer_t* handle);
private:
    bool started_;
    uv_timer_t* handle_;
    uint64_t timeout_;
    uint64_t repeat_;
    TimerCallback callback_;

    TimerCloseComplete closeComplete_;
};


#endif //UV_TCP_TIMER_H
