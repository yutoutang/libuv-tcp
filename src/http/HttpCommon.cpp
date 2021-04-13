//
// Created by txy on 2021/4/1.
//
#include "HttpCommon.h"

string HttpVersionToStr(HttpVersion version){
    if (version == HttpVersion::Http1_0){
        return "HTTP/1.0";
    } else if (version == HttpVersion::Http1_1){
        return "HTTP/1.1";
    }
    return "";
}

HttpVersion GetHttpVersion(const string& str){
    if (str == "HTTP/1.0"){
        return HttpVersion::Http1_0;
    } else if (str == "HTTP/1.1"){
        return HttpVersion::Http1_1;
    }
    return HttpVersion::Unknown;
}

void split(string line, regex& reg, vector<string>& out){
    auto begin = sregex_token_iterator(line.begin(), line.end(), reg, -1);
    auto end = sregex_token_iterator();
    out = vector<string>(begin, end);
}


int SplitHttpOfCRLF(const string& str, vector<string>& out){
    regex reg("\r\n");
    split(str, reg, out);
    return 0;
}


int SplitStrOfSpace(const string& str, vector<string>& out){
    regex reg(" ");
    split(str, reg, out);
    return 0;
}

// TODO ?
uint64_t GetCommonStringLen(const string& str1, const string& str2){
    uint64_t i = 0;
    if (str1.empty()){
        return i;
    }
    while (i < str1.size() and  i < str2.size()){
        if (str1[i] != str2[i]){
            break;
        }
        ++i;
    }
    return i;
}

// 拼接请求头
int AppendHead(const string& str, map<string, string>& heads){
    int pos = str.find(":");
    if (pos == -1){
        return -1;
    }
    string key = string(str, 0, pos);
    string value = string(str, pos + 2);
    heads[key] = value;
    return 0;
}