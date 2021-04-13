//
// Created by txy on 2021/3/30.
//

#ifndef UV_TCP_HTTPCOMMON_H
#define UV_TCP_HTTPCOMMON_H
#include "vector"
#include "string"
#include "map"
#include "regex"

using namespace std;

enum ParseResult{
    Success,
    Fail,
    Error
};

enum HttpVersion{
    Http1_0,
    Http1_1,
    Unknown,
};

enum Method{
    GET,
    POST,
    PUT,
    DELETE,
    Valid,
};

enum StatusCode{
    OK = 200,
};

const string CRLF = "\r\n";
const string SPACE = " ";


extern string HttpVersionToStr(HttpVersion version);

extern HttpVersion GetHttpVersion(const string& str);

extern void split(string line, regex& reg, vector<string>& out);


extern int SplitHttpOfCRLF(const string& str, vector<string>& out);


extern int SplitStrOfSpace(const string& str, vector<string>& out);

// 在前缀树中比较 node->key 和 key 相同
extern uint64_t GetCommonStringLen(const string& str1, const string& str2);

// 拼接请求头
extern int AppendHead(const string& str, map<string, string>& heads);





#endif //UV_TCP_HTTPCOMMON_H
