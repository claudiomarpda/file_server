//
// Created by mz on 18/11/17.
//
#include "../include/Client.h"

Client::Client(const Socket &socket) : socket(socket), stream(socket) {}

const Socket &Client::getSocket() const {
    return socket;
}

const NetStream &Client::getStream() const {
    return stream;
}
