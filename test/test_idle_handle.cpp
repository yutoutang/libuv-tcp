//
// Created by txy on 2021/3/23.
// uv 中 idle/prepare/check handle 测试
// idle 空闲句柄 每次 loop 中都会执行一次回调 在阻塞之前(当 handle 队列中有活跃的 idle handle 时，执行完 idle 后再阻塞)
// 用来执行一些低优先级的任务
//
// prepare 准备句柄 在进入阻塞之前执行
// check 检查句柄 在进入阻塞后执行
#include "uv.h"
#include "cstdlib"
#include "iostream"

using namespace std;

uint64_t num = 0;

void my_callback_idle(uv_idle_t *handle){
    num++;
    if (num >= 5){
        cout << "idle stop num = " << num << endl;
        uv_stop(uv_default_loop());
    }
}

void my_callback_prepare(uv_prepare_t *handle){
    cout << "callback_prepare" << endl;
}

void my_callback_check(uv_check_t *handle){
    cout << "callback_check" << endl;
}

int main(){
    uv_idle_t idle;
    uv_prepare_t pre;
    uv_check_t check;

    uv_idle_init(uv_default_loop(), &idle);
    uv_check_init(uv_default_loop(), &check);
    uv_prepare_init(uv_default_loop(), &pre);

    cout << "idle start num = " << num << endl;

    uv_idle_start(&idle, my_callback_idle);
    uv_check_start(&check, my_callback_check);
    uv_prepare_start(&pre, my_callback_prepare);

    uv_run(uv_default_loop(), UV_RUN_DEFAULT);
}


