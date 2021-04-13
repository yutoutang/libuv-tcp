//
// Created by txy on 2021/4/1.
//

#ifndef UV_TCP_CLIENT_H
#define UV_TCP_CLIENT_H
#include "../../src/TcpClient.h"

class Client: public TcpClient {
public:
    Client(EventLoop* loop): TcpClient(loop) {
        setConnectStatusCallback(bind(&Client::onConnect, this, placeholders::_1));
        setMessageCallback(bind(&Client::onMessageCallback, this, placeholders::_1, placeholders::_2));
    };

    void connectToServer(InetAddress& addr){
       sockAddrPtr_ = make_shared<InetAddress>(addr);
       connect(addr);
    };

    void reConnect(){
        Timer* timer = new Timer(loop_, 500, 0, [this](Timer* ptr){
           connect(*(sockAddrPtr_.get()));
           ptr->close([](Timer* ptr){
               delete ptr;
           });
        });
        timer->start();
    }

    void onConnect(ConnectionStatus status){
        if (status != ConnectionStatus::Success){
            reConnect();
        } else {
            string data = "test1111";
            write(data.data(), data.size());
        }
    }

    void onMessageCallback(const char* buf, ssize_t size){
        write(buf, size, nullptr);
    }
private:
    shared_ptr<InetAddress> sockAddrPtr_;
};


#endif //UV_TCP_CLIENT_H
