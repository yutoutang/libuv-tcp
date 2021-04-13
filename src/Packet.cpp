//
// Created by txy on 2021/4/6.
//

#include "Packet.h"

uint8_t Packet::HeadByte = 0x7e;
uint8_t Packet::EndByte = 0xe7;
Packet::DataMode Packet::Mode = Packet::DataMode::LittleEndian;

Packet::Packet(): buffer_(""), dataSize_(0) {

}

Packet::~Packet() {

}

void Packet::pack(const char *data, uint16_t size) {
    dataSize_ = size;
    buffer_.resize(size + PacketMinSize());

    buffer_[0] = HeadByte;
    PackNum(&buffer_[1], size);
    copy(data, data + size, &buffer_[sizeof(HeadByte) + sizeof(dataSize_)]); // 拷贝 data 中的字符串至 buffer 中的数据区
    buffer_.back() = EndByte;
}

const char *Packet::getData() {
    return buffer_.c_str() + sizeof(HeadByte) + sizeof(dataSize_);
}

uint16_t Packet::DataSize() {
    return dataSize_;
}

// 对外访问
const string &Packet::Buffer() {
    return buffer_;
}

uint32_t Packet::PacketSize() {
    return buffer_.size();
}

void Packet::swap(string &str) {
    buffer_.swap(str);
    dataSize_ = buffer_.size() - PacketMinSize();
}

// PacketBuffer 提供一种 buffer 的数据结构
int Packet::readFromBuffer(PacketBuffer* packBuf, Packet& out) {
    string data = "";
    while (true){
        auto size = packBuf->readSize(); // 可读大小
        if (size < PacketMinSize()){
            return -1;
        }
        uint16_t dataSize;
        packBuf->readBufferN(data, 1 + sizeof(dataSize)); // 读一个字节 head + dataSize字节的size
        // 找到包头部
        if ((uint8_t)data[0] != HeadByte){
            data.clear();
            packBuf->clearBufferN(1);
            continue;
        }
        // 确定包头后，找 size
        UnpackNum((uint8_t*)data.c_str() + 1, dataSize);
        uint16_t msg = dataSize + PacketMinSize();
        // 包不完整
        if (msg < size){
            return -1;
        }
        packBuf->clearBufferN(sizeof(dataSize) + 1); // 清除
        packBuf->readBufferN(data, dataSize + 1);
        // 检查包尾
        if ((uint8_t)data.back() != EndByte){
            break;
        }
    }
    out.swap(data);
    return 0;
}

uint32_t Packet::PacketMinSize() {
    return 4; // 1 + 2 + 1
}