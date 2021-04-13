//
// Created by txy on 2021/3/12.
//

#ifndef YM_SERVER_2_0_ASYNC_H
#define YM_SERVER_2_0_ASYNC_H
#include "EventLoop.h"
#include "memory"
#include "functional"
#include "queue"
#include "mutex"

class Async : public enable_shared_from_this<Async> {
public:
    typedef function<void(Async*)> OnCloseCompleteCallback; // 异步完成后的回调
    Async(EventLoop *loop);
    void init();
    virtual ~Async();

    void runInThisLoop(DefaultCallback callback);

    void close(OnCloseCompleteCallback callback);
    EventLoop *Loop();
private:
    void process();
    static void Callback(uv_async_t* handle);
    void onCloseCompleted();

    EventLoop *loop_;
    mutex mutex_;
    uv_async_t *handle_;
    queue<DefaultCallback> callbacks_;
    OnCloseCompleteCallback onCloseCompleteCallback_;

};


#endif //YM_SERVER_2_0_ASYNC_H
