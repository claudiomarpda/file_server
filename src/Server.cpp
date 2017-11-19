//
// Created by mz on 18/11/17.
//
#include <iostream>
#include <thread>
#include "../include/Server.h"
#include "../include/FileHandler.h"

using namespace std;

Server::Server(const Client &client) : client(client) {}

void Server::run() const {

    vector<string> fileNames = FileHandler::readDirectoryFileNames(FileHandler::kFilesDirectory);

    // 01
    // Send the number of files
    client.getStream().writeString(to_string(fileNames.size()));

    // 02
    // Send the name of the files
    for (const auto &i : fileNames) {
        client.getStream().writeString(i);
    }

    // 03
    // Message before receiving the file number
    client.getStream().writeString("Enter a file number: ");

    // 04
    // Receive the file number
    int chosenFile = client.getStream().readInt();

    // 05
    // Send file confirmation
    client.getStream().writeString("You chose " + to_string(chosenFile) + ": ");
    client.getStream().writeString(fileNames[chosenFile]);

    try {

        // Open file
        FILE *pFile = FileHandler::openInputFile(fileNames[chosenFile]);
        fseek(pFile, 0, SEEK_END);
        // Read the number of bytes of the file
        int fileSize = (int) ftell(pFile);
        // Back to the beginning of the file
        rewind(pFile);

        // 06
        // Send the file size
        client.getStream().writeInt(fileSize);

        const size_t kBufferSize = 1024;
        char buffer[kBufferSize];

        while (!feof(pFile)) {
            // 07
            client.getStream().writeString("_continue");
            fread(buffer, sizeof(unsigned char), kBufferSize, pFile);

            // TODO: implement protocol for confirmation of bytes received by the client

            // 08
            // Send buffer to client
            client.getStream().writeBytes(buffer, kBufferSize);
        }

        client.getStream().writeString("_end_of_file");

    } catch (InfraException &e) {
        client.getStream().writeString("Something wrong happened.");
        cout << e.what() << endl;
    }

}

void Server::start() const {
    thread t(&Server::run, this);
    t.detach();
}
