//
// Created by txy on 2021/3/12.
//

#include "Async.h"

Async::Async(EventLoop *loop): loop_(loop), handle_(nullptr), onCloseCompleteCallback_(nullptr) {

}

void Async::init() {
    if (handle_ == nullptr){
        handle_ = new uv_async_t;
        uv_async_init(loop_->handle(), handle_, Async::Callback); // Callback 执行 callbacks_ 中的回调函数
        handle_->data = static_cast<void *>(this);
        uv_async_send(handle_); // 唤醒
    }
}

Async::~Async() {

}

// 在 loop 中添加回调函数
void Async::runInThisLoop(DefaultCallback callback) {
    {
        lock_guard<mutex> lck(mutex_);
        callbacks_.push(callback);
    }
    if (handle_ != nullptr)
        uv_async_send(handle_); // 唤醒 handle
}

void Async::close(Async::OnCloseCompleteCallback callback) {
    if (uv_is_closing((uv_handle_t*)(handle_)) == 0){
        uv_close((uv_handle_t *)(handle_), [](uv_handle_t* handle){
            auto ptr = static_cast<Async*>(handle->data);
            ptr->onCloseCompleted();
            delete handle;
        });
    }
}

EventLoop *Async::Loop() {
    return loop_;
}

void Async::process() {
    queue<DefaultCallback> queue;
    {
        lock_guard<mutex> lck(mutex_);
        callbacks_.swap(queue);
    }
    while (!queue.empty()){
        auto f = queue.front();
        f();
        queue.pop();
    }
}

void Async::Callback(uv_async_t *handle) {
    auto async = static_cast<Async*>(handle->data);
    async->process();
}

void Async::onCloseCompleted() {
    if (onCloseCompleteCallback_ != nullptr){
        onCloseCompleteCallback_(this);
    }
}
