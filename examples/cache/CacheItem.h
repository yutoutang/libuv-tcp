//
// Created by txy on 2021/2/27.
//

#ifndef UV_TCP_CACHEITEM_H
#define UV_TCP_CACHEITEM_H

#include <string>
#include "memory"

using namespace std;

class CacheItem;
typedef shared_ptr<CacheItem> CacheItemPtr; // 利用 shared_ptr 节省拷贝开销 uniqued_ptr 试试
typedef shared_ptr<const CacheItem> ConstCacheItemPtr;

class Buffer;
class CacheItem {
public:
    enum UpdatePolicy {
        kSet,
        kAdd,
    };

//    CacheItem(std::string key, uint32_t flags, int expires, int valueLen, uint64_t cas);
    CacheItem(const string& key, const string& value, int expires);

    static CacheItemPtr makeItem(string key, string value, int expires){
        return make_shared<CacheItem>(key, value, expires); // 相当于 new 利用指针存储
    }

    ~CacheItem() {}

    void append(const char* data, size_t len);

    bool endsWithCRLF() const {
        return receiveBytes_ == totalLen() and data_[totalLen() - 2] == '\r' and data_[totalLen()-1] == '\n';
    }

    void output(Buffer *out, bool needCas = false) const;

    void resetKey(const string& k);

    int keyLen() { return keyLen_; }
    string key() const { return data_.substr(0, keyLen_);}
    string value() const { return data_.substr(keyLen_, valueLen_); }
    size_t hash() const { return hash_; } // 需要 const 修饰，才能被 constPtr 使用
    size_t neededBytes() const { return totalLen() - receiveBytes_;}

    void setCas(uint64_t cas) { cas_ = cas; }
private:
    int totalLen() const { return keyLen_ + valueLen_;}
    // 48
    int keyLen_; // key 和 value 进行拼接发送
    const int expires_; // 过期时间
    const int valueLen_;
    int receiveBytes_;
    uint64_t cas_;
    size_t hash_;
    string data_;

    std::hash<string> h;
};


#endif //CACHE_TEST_CACHEITEM_H
