//
// Created by txy on 2021/4/8.
//

#include "HttpServer.h"

HttpServer::HttpServer(EventLoop *loop): TcpServer(loop){
    setMessageCallback(bind(&HttpServer::onMessage, this, placeholders::_1, placeholders::_2, placeholders::_3));
}

void HttpServer::Get(const string &path, OnHttpReqCallback callback) {
    route_[Method::GET].emplace_back(path, callback);
}

void HttpServer::onMessage(TcpConnectionPtr conn, const char *buf, ssize_t size) {
    PacketBufferPtr packBuf = conn->getBuffer();
    if (packBuf == nullptr){
        return;
    }
    // buf ?
    packBuf->append(buf, size);
    string out;
    packBuf->readBufferN(out, packBuf->readSize());
    Request req;
    OnHttpReqCallback callback = nullptr;
    auto rst = req.unpack(out);
    if (rst == ParseResult::Success){
        for (auto item: route_[Method::GET]){
//            cout << item.path << " " << req.getPath() << endl;
            if (item.path == req.getPath())
                callback = item.callback;
        }
        if (callback != nullptr){
            Response resp;
            callback(req, &resp);
            string respData;
            resp.pack(respData);
            string name = conn->getName();
            conn->write(respData.c_str(), respData.size(), [this, &name](WriteInfo&){
                closeConnection(name);
            });
        }
    }
}
