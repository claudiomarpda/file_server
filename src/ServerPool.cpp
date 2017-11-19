//
// Created by mz on 18/11/17.
//
#include "../lib/netry/include/ServerSocket.h"
#include <iostream>
#include <thread>
#include "../include/ServerPool.h"
#include "../include/Client.h"
#include "../include/Server.h"

using namespace netry;

bool ServerPool::serverOn = true;

void ServerPool::run() const {

    ServerSocket ss(kPortNumber);

    while (serverOn) {
        cout << "Waiting... " << endl;
        Socket sk = ss.accept();

        Client c(sk);
        Server s(c);
        s.start();

        cout << "Client connected" << endl;
    }
}

/**
 * Starts a thread to keep listening for client connections
 */
void ServerPool::start() const {
    thread t(&ServerPool::run, this);
    t.join();
}

bool ServerPool::isServerOn() {
    return serverOn;
}

void ServerPool::setServerOn(bool serverOn) {
    ServerPool::serverOn = serverOn;
}

