//
// Created by txy on 2021/4/8.
//

#include "Response.h"

#include <utility>

Response::Response() {

}

Response::Response(HttpVersion version, StatusCode code): version_(version), statusCode_(code) {

}

Response::~Response() {

}

void Response::setVersion(HttpVersion version) {
    version_ = version;
}

void Response::setStatus(StatusCode code, string info) {
    statusCode_ = code;
    statusInfo_ = move(info);
}

HttpVersion Response::getVersion() {
    return version_;
}

StatusCode Response::getStatusCode() {
    return statusCode_;
}

string Response::getStatusInfo() {
    return statusInfo_;
}

string Response::getContent() {
    return content_;
}

string Response::getHead(string &key) {
    if (!heads_.count(key)){
        return "";
    }
    return heads_[key];
}

void Response::appendHead(string &key, string &value) {
    heads_[key] = value;
}

void Response::appendHead(string &&key, string &&value) {
    appendHead(key,value);
}

void Response::swapContent(string &body) {
    content_.swap(body);
}

int Response::pack(string &data) {
    data.clear();
    data += HttpVersionToStr(version_);
    data += " ";
    data += to_string(statusCode_);
    data += " ";
    data += statusInfo_;
    data += CRLF;
    for (auto& kv: heads_){
        data += kv.first;
        data += ": ";
        data += kv.second;
        data += CRLF;
    }
    data += CRLF;
    data += content_;
    return 0;
}

ParseResult Response::unpack(string &data) {
    vector<string> headList;
    SplitHttpOfCRLF(data, headList);
    if (headList.empty()){
        return ParseResult::Fail;
    }
    if (parseStatus(headList[0]) < 0){
        return ParseResult::Fail;
    }
    if (headList.size() > 1){
        for (int i = 1; i < headList.size(); ++i) {
            if (headList[i].empty())
                break;
            if (AppendHead(headList[i], heads_) < 0){
                return ParseResult::Error;
            }
        }
    }
    content_ = headList[headList.size() - 1];
    return ParseResult::Success;
}

ParseResult Response::unpackAndCompleted(string &data) {
    return Fail;
}

// TODO http 传输编码相关
ParseResult Response::isCompleteChunked() {
    return Fail;
}

int Response::parseStatus(string &data) {
    vector<string> statusList;
    SplitStrOfSpace(data, statusList);
    if (statusList.size() != 3){
        return -1;
    }
    // 简单解析 异常问题
    version_ = GetHttpVersion(statusList[0]);
    try {
        statusCode_ = (StatusCode)stoi(statusList[1]);
        statusInfo_ = statusList[2];
    }catch (...){
        return -1;
    }

    return 0;
}

