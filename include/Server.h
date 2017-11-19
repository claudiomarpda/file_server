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

    void run() const;

    void sendFile(const string &fileName) const;

public:

    explicit Server(const Client &client);

    void start();

};


#endif //FILE_SERVER_SERVER_H
