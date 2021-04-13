//
// Created by txy on 2021/4/6.
// 二进制字节流

#ifndef UV_TCP_PACKETBUFFER_H
#define UV_TCP_PACKETBUFFER_H
#include "string"
#include "functional"
#include "memory"

using namespace std;

class Packet;
class PacketBuffer{
public:
    PacketBuffer() {}
    virtual ~PacketBuffer(){}

    virtual int append(const char* data, uint64_t size) = 0;
    virtual int readBufferN(string& data, uint64_t N) = 0;
    virtual int clearBufferN(uint64_t N) = 0;
    virtual int clear() = 0;
    virtual uint64_t readSize() = 0;
};

typedef shared_ptr<PacketBuffer> PacketBufferPtr;

#endif //UV_TCP_PACKETBUFFER_H
