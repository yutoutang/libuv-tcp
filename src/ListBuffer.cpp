//
// Created by txy on 2021/4/7.
//

#include "ListBuffer.h"

ListBuffer::~ListBuffer() {

}

int ListBuffer::append(const char *data, uint64_t size) {
    for (int i = 0; i < size; ++i) {
        buffer_.push_back(data[i]);
    }
    return 0;
}

int ListBuffer::readBufferN(string &data, uint64_t N) {
    if (N > buffer_.size()){
        return -1;
    }
    auto it = buffer_.begin();
    for (int i = 0; i < N; ++i) {
        data.push_back(*(it));
        it++;
    }
    return 0;
}

uint64_t ListBuffer::readSize() {
    return buffer_.size();
}

int ListBuffer::clearBufferN(uint64_t N) {
    for (int i = 0; i < N; ++i) {
        if (buffer_.empty())
            break;
        buffer_.pop_front();
    }
    return 0;
}

int ListBuffer::clear() {
    buffer_.clear();
    return 0;
}
