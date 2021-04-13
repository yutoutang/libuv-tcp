//
// Created by txy on 2021/3/26.
//

#ifndef UV_TCP_TIMERWHEEL_H
#define UV_TCP_TIMERWHEEL_H
#include "EventLoop.h"
#include "vector"
#include "set"
#include "Timer.h"

template<typename T>
class TimeWheel{
public:
    TimeWheel(EventLoop* loop);
    explicit TimeWheel(EventLoop* loop, unsigned int timeout);
    void setTimeout(unsigned int timeout);
    int getTimeout();
    void start();
    void insert(shared_ptr<T> type);

private:
    void wheelCallback();
private:
    unsigned int index_;
    unsigned int timeoutSec_;
    Timer timer_;

    vector<set<shared_ptr<T>>> wheel_;

};

template<typename T>
TimeWheel<T>::TimeWheel(EventLoop *loop): TimeWheel(loop, 0){

}


template<typename T>
TimeWheel<T>::TimeWheel(EventLoop *loop, unsigned int timeout):index_(0) ,
                            timeoutSec_(timeout),
                            // 每 1 秒触发 1 一次 wheelCallback
                            timer_(loop, 1000, 1000, bind(&TimeWheel::wheelCallback, this))  {

}

template<typename T>
void TimeWheel<T>::setTimeout(unsigned int timeout) {
    timeoutSec_ = timeout;
}

template<typename T>
int TimeWheel<T>::getTimeout() {
    return timeoutSec_;
}

template<typename T>
void TimeWheel<T>::start() {
    if (timeoutSec_){
        wheel_.resize(timeoutSec_); // 每秒一个槽
    }
}

template<typename T>
void TimeWheel<T>::insert(shared_ptr<T> v) {
    if (timeoutSec_ > 0 and v != nullptr){
        wheel_[index_].insert(v);
    }
}

//
template<typename T>
void TimeWheel<T>::wheelCallback() {
    if (!timeoutSec_){
        return;
    }
    if (++index_ == timeoutSec_)
        index_ = 0;
    wheel_[index_].clear();
}




#endif //UV_TCP_TIMERWHEEL_H
