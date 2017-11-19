#include <iostream>
#include <thread>
#include <vector>

#include "lib/netry/include/ServerSocket.h"
#include "include/Server.h"
#include "include/Consts.h"

using namespace netry;
using namespace std;

void run() {
    ServerSocket ss(5000);

    cout << "Server on waiting for connections" << endl;
    Socket sk = ss.accept();
    Client c(sk);
    Server s(c);
    s.start();

    sk.close();
    ss.close();
}

int main() {

    thread t(run);
    t.join();

/*    string str;
    do {
        cin >> str;
        cout << ": " << str << endl;
    } while (str != Consts::kExit);*/

    return 0;
}