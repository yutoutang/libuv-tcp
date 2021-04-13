//
// Created by txy on 2021/4/1.
//
#include "../src/http/Request.h"
#include "iostream"

using namespace std;

int main(){
    Request r;
    string s = "";
    string k = "age", k1 = "id";
    string key("Content-Length");
    string ss = "GET / HTTP/1.1\r\n"
                "Content-Length: 1024\r\n\r\n"
                "content";
    r.unpack(ss);
    cout << r.getHttpVersion() << endl;
    cout << r.getContent() << endl;
    cout << r.getHead(key) << endl;
}
