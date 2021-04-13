//
// Created by txy on 2021/3/12.
//
#include "EventLoop.h"
#include "Async.h"

EventLoop::EventLoop(): EventLoop(EventLoop::Mode::New){

}

EventLoop::EventLoop(EventLoop::Mode mode): loop_(nullptr), async_(nullptr), status_(NotRun) {
    if (mode == Mode::New){
        loop_ = new uv_loop_t;
        uv_loop_init(loop_);
    } else {
        loop_ = uv_default_loop();
    }
    async_ = new Async(this);
}

EventLoop::~EventLoop() {
    if (loop_ != uv_default_loop()){
        uv_loop_close(loop_);
        delete loop_;
        delete async_;
    }
}

EventLoop *EventLoop::DefaultLoop() {
    static EventLoop loop(EventLoop::Mode::Default);
    return &loop;
}

int EventLoop::run() {
    if (loop_ and status_ == NotRun){
        async_->init();
        loopThread_ = this_thread::get_id();
        status_ = Runed;
        int ret = uv_run(loop_, UV_RUN_DEFAULT); // loop 中是否有活跃的 handle 和 request 阻塞
        status_ = Stop;
        return ret;
    }
    return -1;
}

int EventLoop::runNoWait() {
    return 0;
}

int EventLoop::stop() {
    return 0;
}

bool EventLoop::isStop() {
    return status_ == Stop;
}

EventLoop::Status EventLoop::getStatus() {
    return status_;
}

uv_loop_t *EventLoop::handle() {
    return loop_;
}

const char *EventLoop::GetErrorMessage(int status) {
    return nullptr;
}

bool EventLoop::isRunInLoopThread() {
    if (status_ == Runed){
        return this_thread::get_id() == loopThread_;
    }
    return false;
}

void EventLoop::runInThisLoop(const DefaultCallback callback) {
    if (isRunInLoopThread() || isStop()){
        callback();
    }
    async_->runInThisLoop(callback);
}


