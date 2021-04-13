//
// Created by txy on 2020/12/18.
//

#include "Buffer.h"

#include "errno.h"
#include "memory.h"
#include "sys/uio.h"


ssize_t Buffer::readFd(int fd, int *saveErrno) {
    char extrabuf[65535];
    struct iovec vec[2];
    const size_t writable = writableBytes();
    vec[0].iov_base = begin() + writerIndex_;
    vec[0].iov_len = writable;
    vec[1].iov_base = extrabuf;
    vec[1].iov_len = sizeof extrabuf;
    const ssize_t n = readv(fd, vec, 2);
    if (n < 0){
        *saveErrno = errno;
    } else if (n <= writable){
        writerIndex_ += n;
    } else {
        writerIndex_ = buffer_.size();
        append(extrabuf, n - writable);
    }
    return n;
}