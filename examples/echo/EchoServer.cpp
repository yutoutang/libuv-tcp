//
// Created by txy on 2021/3/29.
//
#include "EchoServer.h"

EchoServer::EchoServer(EventLoop *loop) : TcpServer(loop), count_(0) {
    setMessageCallback(bind(&EchoServer::newMessage, this, placeholders::_1, placeholders::_2, placeholders::_3));
    setNewConnectionCallback(bind(&EchoServer::newConnection, this, placeholders::_1));
    setConnectionCloseCallback(bind(&EchoServer::connectClose, this, placeholders::_1));
}

void EchoServer::newMessage(TcpConnectionPtr connection, const char *buf, ssize_t size) {
//    char *data = new char [size]();
//    memcpy(data, buf, size); // bug
//    connection->write(data, size, [](WriteInfo& info){
//        if (0 != info.status){
//            cout << "err" << endl;
//        }
//        delete[] info.buf;
//    });
    LogWriter::Instance()->info(connection->getName() + " send msg " + string(buf,0, size));
    Packet packet;
    PacketBufferPtr packBuff = connection->getBuffer(); // buffer 是公用的，packet 是每进行一次数据传输
    packBuff->append(buf, size);
    packet.readFromBuffer(packBuff.get(), packet);
    connection->write(packet.getData(), packet.PacketSize(), nullptr);
}

void EchoServer::newConnection(weak_ptr<TcpConnection> connection) {
    if (connection.lock()){
        count_++;
        LogWriter::Instance()->info(connection.lock()->getName() + " is connecting");
        LogWriter::Instance()->info("connections number is " + to_string(count_));
    }
}

void EchoServer::connectClose(weak_ptr<TcpConnection> connection) {
    if (connection.lock()){
        count_--;
        LogWriter::Instance()->info(connection.lock()->getName() + " is closed");
        LogWriter::Instance()->info("connections number is " + to_string(count_));
    }
}


