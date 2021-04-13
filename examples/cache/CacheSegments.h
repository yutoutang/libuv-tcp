//
// Created by txy on 2021/3/9.
// 分段锁设计
// 服务端操作这个类

#ifndef UV_TCP_CACHESEGMENTS_H
#define UV_TCP_CACHESEGMENTS_H
#include "CacheItem.h"
#include "thread"
#include "unordered_set"
#include "array"

class CacheSegments {
public:
    CacheSegments();
    ~CacheSegments();

    // CacheItemPtr shared_ptr 管理
    // item 中用 key 作为 hash，存入 item 时存的时 key + data 减少内存空间
    bool storeItem(const CacheItemPtr& item, CacheItem::UpdatePolicy, bool *exits);
    CacheItemPtr getItem(const CacheItemPtr& key);
    bool deleteItem(const CacheItemPtr& key);
private:
    mutex mutex_;
    struct Hash{
        size_t operator()(const ConstCacheItemPtr& x) const {
            return x->hash();
        }
    };

    // Equal 底层也是重载小括号
    struct Equal{
        bool operator()(const ConstCacheItemPtr& x, const ConstCacheItemPtr& y) const {
            return x->key() == y->key();
        }
    };
    typedef unordered_set<CacheItemPtr, Hash, Equal> ItemMap;

    // 分段锁
    struct MapWithLock{
        ItemMap map_;
        mutable mutex mutex_; // 可以调用
    };

    static const int kShards = 4096;
    array<MapWithLock, kShards> shards_;
};


#endif //CACHE_TEST_CACHESEGMENTS_H
