
//
// Created by txy on 2021/4/6.
// 封装包
// 数据传输效率更高
#ifndef UV_TCP_PACKET_H
#define UV_TCP_PACKET_H
#include "PacketBuffer.h"
#include "iostream"

// head  size  data  end
//  1     2     N     1

class Packet {
public:
    Packet();
    ~Packet();

    void pack(const char* data, uint16_t size);
    const char* getData();
    uint16_t DataSize(); // uint16_t short
    const string& Buffer();
    uint32_t PacketSize(); // uint32_t int; uint64_t long long

    void swap(string& str);

    static int readFromBuffer(PacketBuffer*, Packet&);

    template<typename NumType>
    static void UnpackNum(const uint8_t* data, NumType& num);

    template<typename NumType>
    static void PackNum(char* data, NumType num);

    static uint32_t PacketMinSize();

public:
    // 大端、小端
    enum DataMode{
        BigEndian,
        LittleEndian
    };

    static uint8_t HeadByte; // 1 个字节
    static uint8_t EndByte;  // 1 个字节
    static DataMode Mode;

protected:
    string buffer_;     // n 个字节
    uint16_t dataSize_; // 2 个字节 2^16 = 65536
};


// 解 size
template<typename NumType>
void Packet::UnpackNum(const uint8_t *data, NumType &num) {
    num = 0; // 数据包中存储数据大小
    int size = static_cast<int>(sizeof(NumType)); // 2个字节
    if (Packet::DataMode::BigEndian == Packet::Mode){
        for (int i = 0; i < size; ++i) {
            num <<= 8;
            num |= data[i];
        }
    } else {
        for (int i = size - 1; i >= 0; --i) {
            num <<= 8;
            num |= data[i];
        }
    }
    // '\0xa0\0xf' -> '0xa0' -> '0xfa0' -> 4000
}

// 填充 size
template<typename NumType>
void Packet::PackNum(char *data, NumType num) {
    int size = static_cast<int>(sizeof(NumType)); // num = 4096 -> size = 2
    if (Packet::DataMode::BigEndian == Packet::Mode){
        for (int i = size - 1; i >= 0; --i) {
            data[i] = num & 0xff;
            num >>= 8;
        }
    } else {
        for (int i = 0; i < size; ++i) {
            data[i] = num & 0xff; // 截断高 8 位
            num >>= 8; // 右移 8 位
        }
    }
    // data 中存放num对应的16进制字符 4000 -> '0xfa0' -> '?\x0f' -> '\0xa0\0xf'(小端)
}




#endif //UV_TCP_PACKET_H
