//
// Created by mz on 18/11/17.
//
#ifndef FILE_SERVER_SERVERPOOL_H
#define FILE_SERVER_SERVERPOOL_H


class ServerPool {

private:

    const int kPortNumber = 5000;

    static bool serverOn;

    /**
    * Listen client connections while server is on
    */
    void run() const;

public:

    /**
     * Starts thread to attend clients
     */
    void start() const;

    static bool isServerOn();

    static void setServerOn(bool serverOn);
};


#endif //FILE_SERVER_SERVERPOOL_H