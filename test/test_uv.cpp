//
// Created by txy on 2021/3/23.
//
#include "cstdlib"
#include "uv.h"
#include "iostream"

using namespace std;

int main(){
    uv_loop_t *loop = new uv_loop_t ;
    uv_loop_init(loop); // 初始化 loop

    uv_run(loop, UV_RUN_DEFAULT); // 开启事件循环

    cout << "stop!" << endl;
    uv_loop_close(loop);
}