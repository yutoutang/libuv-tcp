//
// Created by txy on 2021/3/29.
//

#include "TcpClient.h"

TcpClient::TcpClient(EventLoop *loop): loop_(loop),
                    connect_(new uv_connect_t),
                    connection_(nullptr),
                    connectStatusCallback_(nullptr), onMessageCallback_(nullptr){
    connect_->data = static_cast<void*>(this);
}

TcpClient::~TcpClient() {
    delete connect_;
}

void TcpClient::connect(InetAddress &addr) {
    update(); // socket
    uv_tcp_connect(connect_, socket_.get(), addr.get_sockaddr(), [](uv_connect_t* req, int status){
        auto connect = static_cast<TcpClient*>(req->data);
        if (status != 0){
            connect->onConnect(false);
            return;
        }
        connect->onConnect(true);
    });
}

void TcpClient::write(const char *buf, unsigned int size, AfterWriteCallback callback) {
    if (connection_){
        connection_->write(buf, size, callback);
    }else {
        // log warn
    }
}

void TcpClient::writeInLoop(const char *buf, unsigned int size, AfterWriteCallback callback) {
    if (connection_){
        connection_->writeInLoop(buf, size, callback);
    } else {
        // log warn
    }
}

void TcpClient::setConnectStatusCallback(ConnectStatusCallback callback) {
    connectStatusCallback_ = callback;
}

void TcpClient::setMessageCallback(NewMessageCallback callback) {
    onMessageCallback_ = callback;
}

EventLoop *TcpClient::Loop() {
    return loop_;
}

void TcpClient::close(ConnectCloseCallback callback) {
    if (connection_){
        connection_->close([this, callback](string& name){
            if (callback){
                callback(this);
            }
        });
    } else if (callback){
        callback(this); // ?
    }
}

void TcpClient::onConnect(bool flag) {
    if (flag){
        // tcp 连接是双工的 连接成功
        InetAddress addr(socket_.get());
        connection_ = make_shared<TcpConnection>(loop_, addr.toIpPort(), socket_);
        connection_->setMessageCallback(bind(&TcpClient::onMessage, this, placeholders::_1, placeholders::_2, placeholders::_3));
        connection_->setConnectCloseCallback(bind(&TcpClient::onConnectClose, this, placeholders::_1));
        runConnectCallback(ConnectionStatus::Success);
    } else {
        auto ptr = socket_.get();
        if (uv_is_active((uv_handle_t*)ptr)){
            uv_read_stop((uv_stream_t*)ptr);
        }
        if (uv_is_closing((uv_handle_t*)ptr) == 0){
            socket_->data = static_cast<void*>(this);
            uv_close((uv_handle_t*)ptr, [](uv_handle_t* handle){
               auto client = static_cast<TcpClient*>(handle->data);
               client->afterConnectFail();
            });
        }
    }
}

void TcpClient::onConnectClose(const string &name) {
    if (connection_){
        connection_->close(bind(&TcpClient::onClose, this ,placeholders::_1));
    }
}

void TcpClient::onMessage(TcpConnectionPtr conn, const char *buf, ssize_t size) {
    if (onMessageCallback_){
        onMessageCallback_(buf, size);
    }
}

void TcpClient::afterConnectFail() {
    runConnectCallback(ConnectionStatus::Fail);
}

void TcpClient::update() {
    socket_ = make_shared<uv_tcp_t>(); // socket
    uv_tcp_init(loop_->handle(), socket_.get());
    uv_tcp_nodelay(socket_.get(), 1);
}

void TcpClient::runConnectCallback(ConnectionStatus status) {
    if (connectStatusCallback_){
        connectStatusCallback_(status); // 成功
    }
}

void TcpClient::onClose(const string &name) {
    if (connectStatusCallback_){
        connectStatusCallback_(ConnectionStatus::Close);
    }
}
