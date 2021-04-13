//
// Created by txy on 2021/3/9.
//
#include "CacheSegments.h"

CacheSegments::CacheSegments() {

}

CacheSegments::~CacheSegments() {

}

bool CacheSegments::storeItem(const CacheItemPtr &item, CacheItem::UpdatePolicy policy, bool *exits) {
    ItemMap& items = shards_[item->hash() % kShards].map_;
    mutex& mut = shards_[item->hash() % kShards].mutex_;
    lock_guard<mutex> lck(mut);
    auto it = items.find(item);
    *exits = it != items.end();
    if (policy == CacheItem::kSet){
        if (*exits){
            items.erase(it);
        }
        items.insert(item);
    }
    return true;
}

CacheItemPtr CacheSegments::getItem(const CacheItemPtr &key) {
    ItemMap& items = shards_[key->hash() % kShards].map_;
    mutex& mut = shards_[key->hash() % kShards].mutex_;
    lock_guard<mutex> lck(mut);
    auto it = items.find(key);
    return it == items.end() ? CacheItemPtr() : *it;
}

bool CacheSegments::deleteItem(const CacheItemPtr &key) {
    ItemMap& items = shards_[key->hash() % kShards].map_;
    mutex& mut = shards_[key->hash() % kShards].mutex_;
    lock_guard<mutex> lck(mut);
    auto it = items.find(key);
    if (it == items.end()){
        return false;
    }
    items.erase(key);
    return true;
}



