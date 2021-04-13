//
// Created by txy on 2021/3/24.
//
#include "cstdlib"
#include "uv.h"
#include "unistd.h"

using namespace std;

void signal_handler(uv_signal_t *handle, int signum){
    printf("signal received: %d\n", signum);
    uv_signal_stop(handle);
}

void thread1_entry(void *userp){
    sleep(2); // 等待 SIGUSR1 信号，被处理然后退出
    kill(0 ,SIGUSR1);
}

void thread2_entry(void *userp){
    uv_signal_t signal;

    uv_signal_init(uv_default_loop(), &signal);
    uv_signal_start(&signal, signal_handler, SIGUSR1); // 发送 SIGUSR1 信号，并处理

    uv_run(uv_default_loop(), UV_RUN_DEFAULT);
}

int main(){
    uv_thread_t thread1, thread2;

    uv_thread_create(&thread1, thread1_entry, nullptr);
    uv_thread_create(&thread2, thread2_entry, nullptr);

    uv_thread_join(&thread1);
    uv_thread_join(&thread2);
}
