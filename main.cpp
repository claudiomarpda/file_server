#include <iostream>
#include <thread>

#include "lib/netry/include/ServerSocket.h"
#include "include/ServerPool.h"

using namespace netry;
using namespace std;

void run(const ServerPool &serverPool) {
    cout << "Server on" << endl;
    serverPool.start();
}

int main() {
    ServerPool serverPool;

    thread t(run, serverPool);
    t.detach();

    string input;

    do {
        cin >> input;
    } while (input != "exit");

    return 0;
}