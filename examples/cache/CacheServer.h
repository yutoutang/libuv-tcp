//
// Created by txy on 2021/4/12.
//

#ifndef UV_TCP_CACHESERVER_H
#define UV_TCP_CACHESERVER_H
#include "../../src/TcpServer.h"
#include "CacheSegments.h"
#include "regex"

class CacheServer : public TcpServer{
public:
    CacheServer(EventLoop* loop);
    ~CacheServer();

    string makeResponse(const string& data);

    bool doUpdate(vector<string>& data, string& resp);
    bool doGet(vector<string>& data, string& resp);
    bool doDelete(vector<string>& data, string& resp);

    vector<string> split(string data, string token);
private:
    void onMessage(TcpConnectionPtr connection, const char* buf, ssize_t size);
    void newConnection(weak_ptr<TcpConnection> connection);
    void connectClose(weak_ptr<TcpConnection> connection);

private:
    CacheSegments* segments_;

    string command_;
    CacheItemPtr curItem_; // set
    CacheItemPtr needle_; // get
};


#endif //UV_TCP_CACHESERVER_H
