//
// Created by txy on 2021/4/9.
// 前缀树 存放路由

#ifndef UV_TCP_RADIXTREE_H
#define UV_TCP_RADIXTREE_H
#include "HttpCommon.h"

template<typename T>
struct RadixTreeNode{
    bool isEmpty;
    string key;
    T value;
    shared_ptr<RadixTreeNode<T>> child;
    shared_ptr<RadixTreeNode<T>> next;
    RadixTreeNode(bool isEmpty,
                  string key,
                  T value,
                  shared_ptr<RadixTreeNode<T>> child,
                  shared_ptr<RadixTreeNode<T>> next
                  ): isEmpty(isEmpty), key(key), value(value), child(child), next(next){}
};

// typedef 不支持模版，using 支持模版
template<typename T>
using RadixTreeNodePtr = shared_ptr<RadixTreeNode<T>>;

template<typename T>
class RadixTree{
public:
    RadixTree(){};

    void set(const string& key, T& value);
    bool get(const string& key, T& value);

    static char wildCard; // 通配符
private:
    void setNode(RadixTreeNodePtr<T>& node, const string& key, T& value);
    bool getNode(RadixTreeNodePtr<T>& node, const string& key, T& value);

    RadixTreeNodePtr<T> root_;
};

template<typename T>
void RadixTree<T>::set(const string &key, T &value) {
    if (root_ == nullptr){
        root_ = make_shared<RadixTreeNode<T>>(false, key, value, nullptr, nullptr);
    } else {
        setNode(root_, key, value);
    }
}

template<typename T>
bool RadixTree<T>::get(const string &key, T &value) {
    return getNode(root_, key, value);
}

template<typename T>
char RadixTree<T>::wildCard = '*';

template<typename T>
void RadixTree<T>::setNode(RadixTreeNodePtr<T> &node, const string &key, T &value) {
    if (node == nullptr){
        return;
    }
    auto commonLength = GetCommonStringLen(key, node->key);
    // node->key 和 key 完全不相同
    if (commonLength == 0){
        if (node->next == nullptr){
            RadixTreeNodePtr<T> n_node = make_shared<RadixTreeNode<T>>(false, key, value, nullptr, nullptr);
            node->next = n_node;
            return;
        } else {
            setNode(node->next, key, value);
        }
    } else if (commonLength < node->key.size()){ // node->key 和 key 有相同前缀
        string key_same = string(node->key, 0, commonLength); // key value
        string key_diff = string(node->key, commonLength, node->key.size() - commonLength); // 改造 node->key node->value
        // 构造孩子节点 父节点不存 value
        RadixTreeNodePtr<T> childNode = make_shared<RadixTreeNode<T>>(node->isEmpty, key_diff, node->value, node->child, nullptr);
        node->key.swap(key_same);
        node->isEmpty = true;
        node->child = childNode;
        if (key.size() == commonLength){ // key 是 node->key 的前缀 key -> value
            node->value = value; // node 变为 key；原来的 key 的 value 在 node->child 中
            node->isEmpty = false;
            return;
        } else {
            // key_same -> value 部分为 node 的孩子节点
            string key_diff_2 = string(key, commonLength, key.size() - commonLength);
            RadixTreeNodePtr<T> otherChildNode = make_shared<RadixTreeNode<T>>(false, key_diff_2, value, nullptr, nullptr);
            childNode->next = otherChildNode;
        }
    } else { // commonLength >= node->key.size() node->key 是 key 的前缀
        if (key.size() == commonLength){
            node->value = value;
            node->isEmpty = false;
            return;
        }
        else {
            string key_diff = string(key, commonLength, key.size() - commonLength);
            if (node->child == nullptr){
                RadixTreeNodePtr<T> childNode = make_shared<RadixTreeNode<T>>(false, key_diff, value, nullptr, nullptr);
                node->next = childNode;
            } else {
                setNode(node->child, key_diff, value);
            }
        }
    }
}

template<typename T>
bool RadixTree<T>::getNode(RadixTreeNodePtr<T> &node, const string &key, T &value) {
    auto commonLength = GetCommonStringLen(node->key, key);
    // * 比对判定
    if (node->key.size() != 1 and commonLength == node->key.size() - 1){
        if (node->key.back() == wildCard){
            value = node->value;
            return true;
        }
        return getNode(node->next, key, value);
    }
    // node->key 和 key 完全不同
    if (commonLength == 0){
        if (node->next == nullptr){
            return false;
        }
        return getNode(node->next, key, value);
    } else if (commonLength < node->key.size()){
        return false;
    } else {
        if (commonLength == key.size()){
            if (!node->isEmpty){
                value = node->value;
                return true;
            }
            return false;
        } else {
            if (node->child == nullptr){
                return false;
            } else {
                string key_diff(key, commonLength, key.size() - commonLength);
                return getNode(node->child, key_diff, value);
            }
        }
    }
}

#endif //UV_TCP_RADIXTREE_H
