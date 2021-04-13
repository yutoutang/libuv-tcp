//
// Created by txy on 2021/4/7.
// 双向链表 buffer 抽象接口
#ifndef UV_TCP_LISTBUFFER_H
#define UV_TCP_LISTBUFFER_H
#include "PacketBuffer.h"
#include "list"

class ListBuffer: public PacketBuffer {
public:
    ListBuffer(){}
    ~ListBuffer();

    int append(const char* data, uint64_t size) override;
    int readBufferN(string& data, uint64_t N) override;
    uint64_t readSize() override;
    int clearBufferN(uint64_t N) override;
    int clear() override;

private:
    list<uint64_t> buffer_;
};


#endif //UV_TCP_LISTBUFFER_H
