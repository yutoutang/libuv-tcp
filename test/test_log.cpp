//
// Created by txy on 2021/3/22.
//
#include "../src/Logger.h"
#include "chrono"
#include "vector"

// 当前时间 毫秒
uint64_t timestamp_now()
{
    return std::chrono::high_resolution_clock::now().time_since_epoch() / std::chrono::microseconds(1);
}

void logger_benchmark(){
    const int iterations = 10;
    const char* benchmark = "benchmark";
    uint64_t begin = timestamp_now();
    for (int i = 0; i < iterations; ++i)
        InfoL << "Logging" << benchmark << i;
    uint64_t end = timestamp_now();
    long int avg_latency = (end - begin) * 1000 / iterations;
    printf("Average NanoLog Latency = %ld nanoseconds\n", avg_latency);
}

template <typename F>
void run_benchmark(F&& f, int thread_count){
    printf("thread count: %d", thread_count);
    vector<thread> threads;
    for (int i = 0; i < thread_count; ++i) {
        threads.template emplace_back(f);
    }
    for (int i = 0; i < thread_count; ++i) {
        threads[i].join();
    }
}

int main(){
    Logger::Instance().add(make_shared<ConsoleChannel>());
    Logger::Instance().setLogWriter(make_shared<AsyncLogWriter>());

    run_benchmark(logger_benchmark, 1);
}
