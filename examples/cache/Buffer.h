//
// Created by txy on 2020/12/18.
// muduo 中的 Buffer 缓冲
// 预留位置 + 可写位置 + 可读位置

#ifndef UV_TCP_BUFFER_H
#define UV_TCP_BUFFER_H

#include "algorithm"
#include "string"
#include "vector"

#include "cassert"


class Buffer {
public:
    static const size_t kCheapPrepend = 8; // 前面可以写 8 个字节
    static const size_t kInitialSize = 1024;

    Buffer(): buffer_(kCheapPrepend + kInitialSize), readerIndex_(kCheapPrepend), writerIndex_(kCheapPrepend) {
        assert(readableBytes() == 0);
        assert(writableBytes() == kInitialSize);
        assert(prependableBytes() == kCheapPrepend);
    }

    void swap(Buffer& temp){
        buffer_.swap(temp.buffer_);
        std::swap(readerIndex_, temp.readerIndex_);
        std::swap(writerIndex_, temp.writerIndex_);
    }

    size_t readableBytes() const { return writerIndex_ - readerIndex_; } // 可读长度
    size_t writableBytes() const { return buffer_.size() - writerIndex_; }
    size_t prependableBytes() const { return readerIndex_; }

    // 返回可读位置
    const char* peek() const{
        return begin() + readerIndex_;
    }

    // 删除 len 长度的可读区域
    void retrieve(size_t len){
        assert(len <= readableBytes());
        readerIndex_ += len;
    }

    // 删除到指定字符
    void retrieveUntil(const char* end){
        assert(peek() <= end);
        assert(end <= beginWrite());
        retrieve(end - peek());
    }

    void retrieveAll(){
        readerIndex_ = kCheapPrepend;
        writerIndex_ = kCheapPrepend;
    }

    std::string retrieveAsString(){
        std::string str(peek(), readableBytes());
        retrieveAll();
        return str;
    }

    void append(const std::string& str){
        append(str.data(), str.length()); // str.data -> char*
    }

    void append(const char* data, size_t len){
        enableWritableBytes(len);
        std::copy(data, data + len, beginWrite());
        hasWritten(len);
    }

    void append(const void* data, size_t len){
        append(static_cast<const char *>(data), len);
    }

    void enableWritableBytes(size_t len){
        if (writableBytes() < len){
            makeSpace(len);
        }
        assert(writableBytes() > len);
    }

    char* beginWrite(){
        return begin() + writerIndex_;
    }

    const char* beginWrite() const {
        return begin() + writerIndex_;
    }

    void hasWritten(size_t len){
        writerIndex_ += len; // 写完后 writeIndex 增加
    }

    void prepend(const void* data, size_t len){
        assert(len <= prependableBytes());
        readerIndex_ -= len;
        const char* d = static_cast<const char*>(data);
        std::copy(d, d+len, begin()+readerIndex_);
    }

    void shrink(size_t reserve){
        std::vector<char> buf(kCheapPrepend+readableBytes()+reserve);
        std::copy(peek(), peek()+readableBytes(), buf.begin()+kCheapPrepend);
        buf.swap(buffer_);
    }

    ssize_t readFd(int fd, int* saveErrno);
private:
    char* begin(){
        return buffer_.data();
    }

    const char* begin() const {
        return buffer_.data();
    }

    // 分配空间
    void makeSpace(size_t len){
        if (writableBytes() + prependableBytes() < len + kCheapPrepend){
            buffer_.resize(len + writerIndex_);
        } else{
            // 将可读部分的数据移到预留部分
            assert(kCheapPrepend < readerIndex_);
            size_t readable = readableBytes();
            std::copy(begin() + readerIndex_, begin() + writerIndex_, begin() + kCheapPrepend);
            readerIndex_ = kCheapPrepend;
            writerIndex_ = readerIndex_ + readable;
            assert(readable == readableBytes());
        }
    }

    std::vector<char> buffer_;
    size_t readerIndex_;
    size_t writerIndex_;
};




#endif //YM_STD_BUFFER_H
