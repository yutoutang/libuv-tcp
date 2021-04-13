//
// Created by txy on 2021/4/10.
//
#include "../src/http/RadixTree.h"
#include "random"
#include "vector"
#include "iostream"

using namespace std;

template<typename T>
struct KV{
    string key;
    T value;
};

template<typename T>
bool testInsert(RadixTree<T>& tree, uint64_t cnt){
    vector<KV<T>> kvs;
    for (uint64_t i = 1; i < cnt; ++i) {
        KV<T> kv = {to_string(i), i};
        kvs.push_back(kv);
    }

    map<string, T> map;
    default_random_engine random; // 伪随机 编译一次 随机分布就确定了
    uniform_int_distribution<int> dis(0, int(cnt)); // 随机分布
    while (!kvs.empty()){
        int index = dis(random) % kvs.size();
        auto kv = kvs[index];
        tree.set(kv.key, kv.value);
        kvs[index] = kvs.back(); // 当前位置插入数组最后一个元素
        kvs.pop_back(); // 抛出
        map[kv.key] = kv.value;
    }
    cout << "set over" << endl;
    for (auto kv1: map){
        T v;
        string key = kv1.first;

        if (!tree.get(key, v)){
            cout << "not find key " << key << endl;
        }
        else if (v != kv1.second){
            cout << "find error key " << key << endl;
        } else{
            cout << "find success " << key << endl;
        }
    }
    return true;
}

int main(){

    int cnt = 100;
    RadixTree<uint64_t> tree;
    if (testInsert(tree, cnt)){
        cout << "success " << cnt << endl;
    }

//    vector<int> test_v;
//    for (int i = 0; i < 10; ++i) {
//        test_v.push_back(i);
//    }
//    default_random_engine random;
//    uniform_int_distribution<int> dis(0, 10);
//    while (!test_v.empty()){
//        int index = dis(random) % test_v.size();
//        cout << test_v[index] << endl;
//        test_v[index] = test_v.back();
//        test_v.pop_back();
//    }
}
