//
// Created by txy on 2021/3/30.
//

#ifndef UV_TCP_REQUEST_H
#define UV_TCP_REQUEST_H
#include "HttpCommon.h"

class Request {
public:
    Request();
    Request(HttpVersion version, Method method);

    void setVersion(HttpVersion version);
    void setMethod(Method method);
    HttpVersion getHttpVersion();
    Method getMethod();

    void swapContent(string& str);
    string getContent();
    void appendHead(string& key, string& value);
    string getHead(string& key);
    void appendUrlParam(string& key, string& value);
    string getUrlParam(string& key);
    string getUrlParam(string&& key);

    void setPath(string& path);
    string getPath();
    string getValue();

    int pack(string& data);
    ParseResult unpack(string& data);
    ParseResult unpackAndCompleted(string& data);

    static string MethodToStr(Method method);
    static Method StrToMethod(string& str);

    void packPathParam(string& path);
    int unpackUrl(string& str);
    int unpackPath(string& str);
private:


    HttpVersion version_;
    Method method_;
    string path_;
    string value_;
    map<string, string> urlParams_; // 请求参数 列表
    map<string, string> heads_;     // 请求头
    string content_;
};


#endif //UV_TCP_REQUEST_H
