//
// Created by txy on 2021/4/8.
//

#ifndef UV_TCP_RESPONSE_H
#define UV_TCP_RESPONSE_H
#include "map"
#include "HttpCommon.h"

class Response {
public:
    Response();
    explicit Response(HttpVersion version, StatusCode code);
    ~Response();

    void setVersion(HttpVersion version);
    void setStatus(StatusCode code, string info);
    HttpVersion getVersion();
    StatusCode getStatusCode();
    string getStatusInfo();
    string getContent();
    string getHead(string& key);

    void appendHead(string& key, string& value);
    void appendHead(string&& key, string&& value);
    void swapContent(string& body);

    int pack(string& data);
    ParseResult unpack(string& data);
    ParseResult unpackAndCompleted(string& data);
    ParseResult isCompleteChunked();

private:
    int parseStatus(string& data);

    HttpVersion version_;
    StatusCode statusCode_;
    string statusInfo_;
    map<string, string> heads_;
    string content_;
};


#endif //UV_TCP_RESPONSE_H
