//
// Created by mz on 18/11/17.
//
#ifndef FILE_SERVER_CLIENT_H
#define FILE_SERVER_CLIENT_H

#include "../lib/netry/include/Socket.h"
#include "../lib/netry/include/NetStream.h"

using namespace netry;

class Client {

private:
    Socket socket;
    NetStream stream;

public:
    // Marked as explicit to avoid unintentional implicit conversions
    explicit Client(const Socket &socket);

    const Socket &getSocket() const;

    const NetStream &getStream() const;
};


#endif //FILE_SERVER_CLIENT_H
