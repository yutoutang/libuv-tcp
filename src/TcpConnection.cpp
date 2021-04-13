//
// Created by txy on 2021/3/12.
//

#include "TcpConnection.h"

struct WriteReq{
    uv_write_t write;
    uv_buf_t buf;
    AfterWriteCallback callback;
};

TcpConnection::TcpConnection(EventLoop *loop, const string &name, TcpPtr client, bool isConnected):
                            name_(name), connected_(isConnected), loop_(loop),  handle_(client),
                            onMessageCallback_(nullptr),
                            onCloseCallback_(nullptr),
                            closeCompleteCallback_(nullptr){
    handle_->data = static_cast<void *>(this); // 每个 client 携带一个 TcpPtr 连接
    uv_read_start((uv_stream_t*)(handle_.get()), [](uv_handle_t* handle, size_t size, uv_buf_t* buf){
        auto conn = static_cast<TcpConnection*>(handle->data);
        buf->base = conn->resizeData(size);
        buf->len = size;
    }, &TcpConnection::onMessageReceive);
    buffer_ = make_shared<ListBuffer>();
}

TcpConnection::~TcpConnection() {

}

void TcpConnection::onSocketClose() {
    if (onCloseCallback_){
        onCloseCallback_(name_);
    }
}

void TcpConnection::close(OnCloseCallback callback) {
    onMessageCallback_ = nullptr;
    onCloseCallback_  = nullptr;

    onCloseCallback_ = move(callback);
    // client 链接是否活跃
    auto ptr = handle_.get();
    if (uv_is_active((uv_handle_t*)ptr)){
        uv_read_stop((uv_stream_t*)ptr);
    }
    if (uv_is_closing((uv_handle_t*)ptr) == 0){
        uv_close((uv_handle_t*)ptr, [](uv_handle_t* handle){ // handle = connection
            auto conn = static_cast<TcpConnection*>(handle->data);
            conn->onSocketClose();
        });
    } else {
        closeComplete();
    }
}

int TcpConnection::write(const char *buf, ssize_t size, AfterWriteCallback callback) {
    int ret = -1;
    if (connected_){
        WriteReq* req = new WriteReq;
        req->buf = uv_buf_init(const_cast<char*>(buf), size); // 去掉 const
        req->callback = callback;
        auto ptr = handle_.get();
        ret = uv_write((uv_write_t*)req, (uv_stream_t*)ptr, &req->buf, 1, [](uv_write_t *req, int status){
            // 写完执行的回调函数
            WriteReq* req1 = (WriteReq*)req;
            if (req1->callback != nullptr){
                WriteInfo info;
                info.buf = const_cast<char*>(req1->buf.base);
                info.status = status;
                info.size = req1->buf.len;
                req1->callback(info); // 这里执行写后回调函数
            }
        });
    } else {
        // 连接失败
    }
    return ret;
}

// 封装一层 write
void TcpConnection::writeInLoop(const char *buf, ssize_t size, AfterWriteCallback callback) {
    weak_ptr<TcpConnection> conn = shared_from_this(); // 防止同一个连接回调过程中的循环引用
    loop_->runInThisLoop([conn, buf, size, callback]{
        shared_ptr<TcpConnection> ptr = conn.lock();
        if (ptr != nullptr){
            ptr->write(buf, size, callback);
        } else if (callback != nullptr){
            struct WriteInfo info = {
                    WriteInfo::Disconnected,
                    const_cast<char *>(buf),
                    static_cast<unsigned long>(size),
            };
            callback(info);
        }
    });
}

void TcpConnection::setWrapper(shared_ptr<ConnectionWrapper> wrapper) {
    wrapper_ = wrapper;
}

shared_ptr<ConnectionWrapper> TcpConnection::getWrapper() {
    return wrapper_.lock();
}

void TcpConnection::setMessageCallback(OnMessageCallback callback) {
    if (callback){
        onMessageCallback_ = move(callback);
    }
}

void TcpConnection::setConnectCloseCallback(OnCloseCallback callback) {
    if (callback){
        onCloseCallback_ = move(callback);
    }
}

void TcpConnection::setConnectStatus(bool status) {
    connected_ = status;
}

const string &TcpConnection::getName() {
    return name_;
}

void TcpConnection::onMessage(const char *buf, ssize_t size) {
    if (onMessageCallback_){
        onMessageCallback_(shared_from_this(), buf, size);
    }
}

void TcpConnection::closeComplete() {
    if (closeCompleteCallback_){
        closeCompleteCallback_(name_);
    }
}

char *TcpConnection::resizeData(size_t size) {
    data_.resize(size);
    return const_cast<char *>(data_.c_str()); // 去掉 const
}

void TcpConnection::onMessageReceive(uv_stream_t *client, ssize_t nread, const uv_buf_t *buf) {
    auto conn = static_cast<TcpConnection*>(client->data);
    if (nread > 0){
        conn->onMessage(buf->base, nread);
    } else if (nread < 0){
        conn->setConnectStatus(false); // 关闭连接
        if (nread != UV_EOF){
            conn->onSocketClose(); // 读完
            return;
        }
        // 没读完 安全的关闭 tcp 连接
        // shutdown 指定一个方向上终止连接，比如终止写 SHUT_WR
        uv_shutdown_t* shutdown_req = new uv_shutdown_t;
        shutdown_req->data  = (void *)(conn);
        uv_shutdown(shutdown_req, (uv_stream_t*)client, [](uv_shutdown_t* req, int status){
            auto conn = static_cast<TcpConnection*>(req->data);
            conn->onSocketClose();
        });
    }
}

PacketBufferPtr TcpConnection::getBuffer() {
    return buffer_;
}
