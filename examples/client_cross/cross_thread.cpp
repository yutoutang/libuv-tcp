//
// Created by txy on 2021/4/1.
// 客户端跨线程通信
#include "Client.h"

#include "iostream"
#include "thread"
#include "memory"
#include "mutex"
#include "condition_variable"

#include "Client.h"

typedef shared_ptr<Client> ClientPtr;

struct Clients{
    vector<ClientPtr> clients;
    mutex mutex;
    condition_variable cond;
    bool inited;
};

// thread 1
void runClients(int count, InetAddress& server, Clients& clients){
    EventLoop loop;
    {
        lock_guard<mutex> lck(clients.mutex);
        for (int i = 0; i < count; ++i) {
            auto client = make_shared<Client>(&loop);
            client->connect(server);
            clients.clients.push_back(client);
        }
        clients.inited = true;
    }
    clients.cond.notify_one();
    loop.run();
}

// thread 2
void runClientsCrossThread(Clients &clients){
    {
        unique_lock<mutex> lck(clients.mutex);
        clients.cond.wait(lck, [&clients]{
           return clients.inited;
        });
    }
    EventLoop loop;
    string data = "test";
    Timer timer(&loop, 1000, 10, [&clients, data](Timer *){
        for (auto client: clients.clients){
            client->writeInLoop(data.data(), data.size(), nullptr);
        }
    });
    timer.start();
    loop.run();
}

int main(){
    InetAddress addr("127.0.0.1", 9000);
    struct Clients clients;
    clients.inited = false;
    // 1000 个客户端
    thread t1(bind(&runClients, 1000, addr, ref(clients))); // ref 回调函数引用
    // 跨线程发消息
    thread t2(bind(&runClientsCrossThread, ref(clients)));
    t1.join();
    t2.join();
    return 0;
}


