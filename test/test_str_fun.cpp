//
// Created by txy on 2021/3/30.
//
#include "../src/http/HttpCommon.h"
#include "iostream"
#include "unordered_map"

using namespace std;

int main(){
    string s = "Accept-Ranges: bytes\r\n"
              "Content-Encoding: gzip\r\n"
              "Content-Length: 1966\r\n\r\n";
    vector<string> res;
    SplitHttpOfCRLF(s, res);
    unordered_map<string, string> map;
    for (auto item : res){
        AppendHead(item, map);
    }
    for (auto item: map) {
        cout << item.first << " " << item.second << endl;
    }
}
