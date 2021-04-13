//
// Created by txy on 2021/3/12.
//

#include "TcpAcceptor.h"

#include <utility>

TcpAcceptor::TcpAcceptor(EventLoop *loop): listened_(false),
            loop_(loop), callback_(nullptr), onCloseCompleteCallback_(nullptr){
    uv_tcp_init(loop->handle(), &server_); // socket
    uv_tcp_nodelay(&server_, 1);
    server_.data = (void *)this;
}

TcpAcceptor::~TcpAcceptor() {

}

int TcpAcceptor::bind(InetAddress &addr) {
    return uv_tcp_bind(&server_, addr.get_sockaddr(), 0);
}

int TcpAcceptor::listen() {
    int ret = uv_listen((uv_stream_t *)&server_, 128, [](uv_stream_t* server, int status){
        if (status){
            printf("error");
        }
        auto acceptor = static_cast<TcpAcceptor*>(server->data);
        TcpPtr client = make_shared<uv_tcp_t>();
        uv_tcp_init(acceptor->loop()->handle(), client.get());
        uv_tcp_nodelay(client.get(), 1);

        if (uv_accept(server, (uv_stream_t*)client.get()) == 0){
            acceptor->onNewConnect(client);
        } else {
            uv_close((uv_handle_t *)(client.get()), nullptr);
        }
    });
    if (ret == 0){
        listened_ = true;
    }
    return ret;
}

void TcpAcceptor::close(DefaultCallback callback) {
    onCloseCompleteCallback_ = callback;
    auto ptr = &server_;
    // server 在读，将读停止
    if (uv_is_active((uv_handle_t *)ptr)){
        uv_read_stop((uv_stream_t *)ptr);
    }
    //
    if (uv_is_closing((uv_handle_t*)ptr) == 0){
        uv_close((uv_handle_t*)ptr, [](uv_handle_t* handle){
            auto accept = static_cast<TcpAcceptor*>(handle->data);
            accept->onCloseComplete();
        });
    } else {
        onCloseComplete();
    }
}

void TcpAcceptor::setNewConnectionCallback(NewConnectionCallback callback) {
    callback_ = move(callback); // TcpServer::bindAndListen 绑定回调函数
}

EventLoop *TcpAcceptor::loop() {
    return loop_;
}

void TcpAcceptor::onNewConnect(TcpPtr client) {
    if (callback_){
        callback_(loop_, client); // TcpServer::onAccept
    }
}

void TcpAcceptor::onCloseComplete() {
    if (onCloseCompleteCallback_){
        onCloseCompleteCallback_();
    }
}
