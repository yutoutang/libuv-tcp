//
// Created by txy on 2021/3/12.
//

#include "TcpServer.h"

TcpServer::TcpServer(EventLoop *loop):
            loop_(loop), acceptor_(nullptr),
            onMessageCallback_(nullptr),
            onNewConnectionCallback_(nullptr), onCloseConnectionCallback_(nullptr), timeWheel_(loop){

}

TcpServer::~TcpServer() {

}

int TcpServer::bindAndListen(InetAddress &addr) {
    acceptor_ = make_shared<TcpAcceptor>(loop_);
    int ret = acceptor_->bind(addr);
    if (ret < 0){
        return -1;
    }
    //
    LogWriter::Instance()->info(addr.toIpPort() + " server start");
    acceptor_->setNewConnectionCallback(bind(&TcpServer::onAccept,this, placeholders::_1, placeholders::_2));
    timeWheel_.start();
    return acceptor_->listen();
}

void TcpServer::close(const DefaultCallback& callback) {
    if (acceptor_){
        acceptor_->close([this, callback](){
            for (auto conn: connections_){
                conn.second->onSocketClose();
            }
            callback(); // test
        });
    }
}

TcpConnectionPtr TcpServer::getConnection(const string &name) {
    auto it = connections_.find(name);
    if (it == connections_.end())
        return nullptr;
    return it->second;
}

void TcpServer::removeConnection(string &name) {
    connections_.erase(name);
}


void TcpServer::closeConnection(string &name) {
    auto conn = getConnection(name);
    LogWriter::Instance()->info(name + " is closed");
//    InfoL << name << "is closed";
    if (conn != nullptr){
        conn->close([this](string& name){
            auto conn = getConnection(name);
            if (onCloseConnectionCallback_){
                onCloseConnectionCallback_(conn); // conn 退出
            }
            removeConnection(name);
        });
    }
}

void TcpServer::write(const TcpConnectionPtr& connection, const char *buf, unsigned int size, AfterWriteCallback callback) {
    if (connection){
        connection->write(buf, size, move(callback));
    } else {
        // connection  不存在
    }
}

void TcpServer::write(string &name, const char *buf, unsigned int size, AfterWriteCallback callback) {
    auto conn = getConnection(name);
    write(conn, buf, size, callback);
}

void TcpServer::writeInLoop(const TcpConnectionPtr& connection, const char *buf, unsigned int size, AfterWriteCallback callback) {
    if (connection){
        connection->writeInLoop(buf, size, move(callback));
    } else {
        // connection 不存在
    }
}

void TcpServer::writeInLoop(string &name, const char *buf, unsigned int size, AfterWriteCallback callback) {
    auto conn = getConnection(name);
    writeInLoop(conn, buf ,size, callback);
}

void TcpServer::setTimeout(unsigned int timeout) {
    timeWheel_.setTimeout(timeout);
}

void TcpServer::onAccept(EventLoop *loop, const TcpPtr& client) {
    InetAddress addr(client.get());
    string key = addr.toIpPort();
    auto connection = make_shared<TcpConnection>(loop_, key, client, true);
    if (connection){
        connection->setMessageCallback(bind(&TcpServer::onMessage, this, placeholders::_1, placeholders::_2, placeholders::_3));
        connection->setConnectCloseCallback(bind(&TcpServer::closeConnection, this, placeholders::_1));
        connections_[key] = connection;
        if (timeWheel_.getTimeout() > 0){
            auto wrapper = make_shared<ConnectionWrapper>(connection);
            connection->setWrapper(wrapper);
            timeWheel_.insert(wrapper);
        }
        if (onNewConnectionCallback_){
            onNewConnectionCallback_(connection);
        }
    }
    // error
}

void TcpServer::onMessage(const TcpConnectionPtr& connection, const char *buf, ssize_t size) {
    if (onMessageCallback_){
        onMessageCallback_(connection, buf, size);
    }
    if (timeWheel_.getTimeout() > 0){
        timeWheel_.insert(connection->getWrapper());
    }
}

void TcpServer::setNewConnectionCallback(OnConnectionStatusCallback callback) {
    if (callback){
        onNewConnectionCallback_ = move(callback);
    }
}

void TcpServer::setConnectionCloseCallback(OnConnectionStatusCallback callback) {
    if (callback){
        onCloseConnectionCallback_ = move(callback);
    }
}

void TcpServer::setMessageCallback(OnMessageCallback callback) {
    if (callback){
        onMessageCallback_ = move(callback);
    }
}
