//
// Created by txy on 2021/3/24.
//
#include "cstdio"
#include "unistd.h"
#include "uv.h"

void wake_entry(void* arg){
    sleep(5);
    printf("wake_entry running, wake async!\n");

    uv_async_send((uv_async_t*)(arg));

    uv_stop(uv_default_loop());
}

void my_async_callback(uv_async_t* handle){
    printf("my async running!\n");
}

int main(){
    uv_thread_t wake;
    uv_async_t async;

    uv_async_init(uv_default_loop(), &async, my_async_callback);

    uv_thread_create(&wake, wake_entry, &async);

    uv_run(uv_default_loop(), UV_RUN_DEFAULT);

    uv_thread_join(&wake);
}
