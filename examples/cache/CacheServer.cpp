//
// Created by txy on 2021/4/12.
//
#include "CacheServer.h"

CacheServer::CacheServer(EventLoop *loop) : TcpServer(loop) {
    setMessageCallback(bind(&CacheServer::onMessage, this, placeholders::_1, placeholders::_2, placeholders::_3));
    setNewConnectionCallback(bind(&CacheServer::newConnection, this, placeholders::_1));
    setConnectionCloseCallback(bind(&CacheServer::connectClose, this, placeholders::_1));
    needle_ = CacheItem::makeItem("-1", "-1", 0);
    segments_ = new CacheSegments();
}

CacheServer::~CacheServer() {

}

void CacheServer::onMessage(TcpConnectionPtr connection, const char *buf, ssize_t size) {
    string data = makeResponse(buf);
    connection->write(data.c_str(), data.size(), nullptr);
}

void CacheServer::newConnection(weak_ptr<TcpConnection> connection) {
    if (connection.lock()){
        LogWriter::Instance()->info(connection.lock()->getName() + " is connecting");
    }
}

void CacheServer::connectClose(weak_ptr<TcpConnection> connection) {
    if (connection.lock()){
        LogWriter::Instance()->info(connection.lock()->getName() + " is close");
    }
}

string CacheServer::makeResponse(const string &data) {
    string resp, line;
    if (data.find("\r\n")){
       line = data.substr(0, data.find("\r\n"));
    } else {
        line = data;
    }
    vector<string> out = split(line, " ");
    command_ = out[0];
    if (command_.empty()){
        resp = "command is empty";
    }
    else if (command_ == "get"){
        doGet(out, resp);
    } else if (command_ == "set"){
        doUpdate(out, resp);
    } else if (command_ == "del"){
        doDelete(out, resp);
    } else {
        resp = "error command" + command_;
    }
    resp += "\r\n";
    return resp;
}

// 仅支持 telnet 为客户端
bool CacheServer::doUpdate(vector<string>& data, string& resp) {
    string key = data[1];
    string value = data[2];
    int expires = 0;
    if (data.size() > 3){
        expires = atoi(data[3].c_str());
    }
    curItem_ = CacheItem::makeItem(key, value, expires);
    bool exists = false; // 需要修改
    if (!segments_->storeItem(curItem_, CacheItem::kSet, &exists)){
        resp = "update failed"; // log
        return false;
    }
    resp = "update ok";
    return true;
}

bool CacheServer::doGet(vector<string>& data, string& resp) {
    string key = data[1];
    needle_->resetKey(key);
    ConstCacheItemPtr item = segments_->getItem(needle_);
    if (!item){
        resp = key + " is not exist";
        return false;
    }
    resp = item->value();
    return true;
}

bool CacheServer::doDelete(vector<string>& data, string& resp) {
    string key = data[1];
    needle_->resetKey(key);
    if (!segments_->deleteItem(needle_)){
        resp = "not del " + key;
        return false;
    }
    resp = "delete ok";
    return true;
}

vector<string> CacheServer::split(string data, string token) {
    regex reg(token);
    auto begin = sregex_token_iterator(data.begin(), data.end(), reg, -1);
    auto end = sregex_token_iterator();
    return vector<string>(begin, end);
}



