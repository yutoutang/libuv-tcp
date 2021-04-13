//
// Created by txy on 2021/3/26.
//

#include "Timer.h"

#include <utility>

Timer::Timer(EventLoop *loop, uint64_t timeout, uint64_t repeat, TimerCallback callback):
                started_(false), handle_(new uv_timer_t), timeout_(timeout), repeat_(repeat),
                callback_(std::move(callback)), closeComplete_(nullptr){
    handle_->data = (void *)(this);
    uv_timer_init(loop->handle(), handle_);
}

Timer::~Timer() {

}

void Timer::start() {
    if (!started_){
        started_ = true;
        uv_timer_start(handle_, Timer::process, timeout_, repeat_); // handle 回调 延时 心跳 内部结构是最小堆
    }
}

void Timer::close(Timer::TimerCloseComplete callback) {
    closeComplete_ = callback;
    if (uv_is_active((uv_handle_t*)handle_))
    {
        uv_timer_stop(handle_);
    }
    if (uv_is_closing((uv_handle_t*)handle_) == 0)
    {
        ::uv_close((uv_handle_t*)handle_,
                   [](uv_handle_t* handle)
                   {
                       auto ptr = static_cast<Timer*>(handle->data);
                       ptr->closeComplete();
                       delete handle;
                   });
    }
    else
    {
        closeComplete();
    }
}

void Timer::onTimeout() {
    if (callback_){
        callback_(this);
    }
}

void Timer::closeComplete() {
    if (closeComplete_){
        closeComplete_(this);
    }
}

void Timer::process(uv_timer_t *handle) {
    auto ptr = static_cast<Timer*>(handle->data); // 执行回调函数
    ptr->onTimeout();
}
