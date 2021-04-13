//
// Created by txy on 2021/3/30.
//

#include "Request.h"

Request::Request(): version_(Http1_1), method_(GET) {

}

Request::Request(HttpVersion version, Method method): version_(version), method_(method) {

}

void Request::setVersion(HttpVersion version) {
    version_ = version;
}

void Request::setMethod(Method method) {
    method_ = method;
}

HttpVersion Request::getHttpVersion() {
    return version_;
}

Method Request::getMethod() {
    return method_;
}

void Request::swapContent(string &str) {
    content_.swap(str);
}

string Request::getContent() {
    return content_;
}

// 请求头
void Request::appendHead(string &key, string &value) {
    heads_[key] = value;
}

string Request::getHead(string &key) {
    return heads_[key];
}

// 请求参数列表
void Request::appendUrlParam(string &key, string &value) {
    urlParams_[key] = value;
}

//
string Request::getUrlParam(string &key) {
    return urlParams_[key];
}

string Request::getUrlParam(string &&key) {
    return getUrlParam(key);
}

void Request::setPath(string &path) {
    path_ = path;
}

string Request::getPath() {
    return path_;
}

string Request::getValue() {
    return value_;
}

// 请求头拼接 GET / HTTP/1.1
int Request::pack(string &data) {
    data += MethodToStr(method_);
    if (path_.empty()){
        data += " / ";
    } else {
        data += " " + path_ + " ";
    }
    data += HttpVersionToStr(version_);
    data += "\r\n";
    for (auto& item: heads_){
        data += item.first;
        data += ": ";
        data += item.second;
        data += "\r\n";
    }
    data += "\r\n";
    data += content_; // 请求体
    return 0;
}

// 请求头解析
// Method + 请求资源 + HTTP 版本
// 请求头参数
// content
ParseResult Request::unpack(string &data) {
    vector<string> out;
    SplitHttpOfCRLF(data, out);
    if (out.empty()){
        return ParseResult::Fail;
    }
    unpackUrl(out[0]);
    if (out.size() > 1){
        for (int i = 1; i < out.size(); ++i) {
            if (out[i].empty())
                break;
            if (AppendHead(out[i], heads_) < 0){
                return ParseResult::Error;
            }
        }
    }
    // content ?
    content_ = out[out.size() - 1];
    return ParseResult::Success;
}

// TODO unpack
// 检验 content-length == content.length
ParseResult Request::unpackAndCompleted(string &data) {
    auto rst = unpack(data);
    return rst;
}

// path 和 param 拼接
void Request::packPathParam(string &path) {
    if (path_.empty() || path_[0] != '/'){
        path += "/";
    }
    path += path_;
    if (!urlParams_.empty()){
        path += "?";
        for (auto item: urlParams_){
            path += item.first;
            path += "=";
            path += item.second;
            path += "&";
        }
        path.pop_back();
    }
}

// 解析请求头
// GET / HTTP/1.1
int Request::unpackUrl(string &str) {
    vector<string> out;
    SplitStrOfSpace(str, out);
    if (out.size() != 3){
        return -1;
    }
    method_ = StrToMethod(out[0]);
    if (unpackPath(out[1]) < 0){
        return -1;
    }
    version_ = GetHttpVersion(out[2]);
    return 0;
}

// 解析请求路径
// /path?age=1&id=2
int Request::unpackPath(string &str) {
    if (str.find('?') > 0){
        vector<string> out;
        int index = str.find('?');
        path_ = string(str, 0, index);
        string temp = string(str, index + 1, str.size());
        regex reg("&");
        split(temp, reg, out);
        string key;
        string value;
        for (auto item: out){
            index = item.find('=');
            if (index < 0){
                continue;
            }
            key = string(item, 0 ,index);
            value = string(item, index + 1, item.size());
            appendUrlParam(key, value);
        }
    } else {
        path_ = str;
    }
    return 0;
}

string Request::MethodToStr(Method method) {
    if (method == GET){
        return "GET";
    } else if (method == POST){
        return "POST";
    } else if (method == PUT){
        return "PUT";
    } else if (method == DELETE){
        return "DELETE";
    }
    return "";
}

Method Request::StrToMethod(string &str) {
    if (str == "GET"){
        return GET;
    } else if (str == "POST"){
        return POST;
    } else if (str == "PUT"){
        return PUT;
    } else if (str == "DELETE"){
        return DELETE;
    }
    return Valid;
}
