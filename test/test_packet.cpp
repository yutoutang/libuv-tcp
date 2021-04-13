//
// Created by txy on 2021/4/6.
//
#include "../src/Packet.h"
#include "../src/ListBuffer.h"
#include "iostream"

using namespace std;

int main(){
    Packet p;
    PacketBuffer* b = new ListBuffer();
    char data[4000] = "hello";
    p.pack(data, sizeof(data));
    b->append(p.Buffer().c_str(), p.PacketSize());
    p.readFromBuffer(b, p);
    cout << p.getData() << endl;
    return 0;
}