//
// Created by mz on 18/11/17.
//
#ifndef FILE_SERVER_SERVER_H
#define FILE_SERVER_SERVER_H


#include "Client.h"

using namespace std;

class Server {

private:

    Client client;

    /**
    * Implements a protocol allowing clients to download files
    */
    void run() const;

public:

    // Explicit avoids implicit cast
    explicit Server(const Client &client);

    /**
     * Starts thread to attend a client
     */
    void start() const;

};


#endif //FILE_SERVER_SERVER_H
