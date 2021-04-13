//
// Created by txy on 2021/2/27.
//
#include "CacheItem.h"
#include "Buffer.h"
#include "functional"

//CacheItem::CacheItem(std::string key, uint32_t flags, int expires, int valueLen, uint64_t cas):
//            keyLen_(static_cast<int>(key.size())), flags_(flags), expires_(expires), valueLen_(valueLen),
//            receiveBytes_(0), cas_(cas){
//    hash_ = h(key);
//    append(key.data(), keyLen_);
//}
CacheItem::CacheItem(const string& key, const string& value, int expires):
        keyLen_(static_cast<int>(key.size())), expires_(expires),
        valueLen_(static_cast<int>(value.size())), receiveBytes_(0), data_(static_cast<char*>(::malloc(totalLen()))) {
    hash_ = h(key);
    data_ = key + value;
}

//void CacheItem::append(const char *data, size_t len) {
//    memcpy(data_ + receiveBytes_, data, len); // 将 data 数据拷贝值 data_ 所指向的内存空间
//    receiveBytes_ += static_cast<int>(len);
//    assert(receiveBytes_ <= totalLen());
//}

void CacheItem::output(Buffer *out, bool needCas) const {
    out->append(value());
    out->append("\r\n");
}

void CacheItem::resetKey(const string& k) {
    keyLen_ = k.size();
    receiveBytes_ = 0;
    data_ = k;
    hash_ = h(k);
}


