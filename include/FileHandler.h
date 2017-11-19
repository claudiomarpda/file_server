//
// Created by mz on 18/11/17.
//
#ifndef FILE_SERVER_FILEHANDLER_H
#define FILE_SERVER_FILEHANDLER_H

#include <string>
#include <vector>
#include <dirent.h>
#include "InfraException.h"

using namespace std;

namespace FileHandler {

    /**
    * @see http://pubs.opengroup.org/onlinepubs/7908799/xsh/dirent.h.html
    *
    * @param directoryName
    * @return
    */
    vector<string> readDirectoryFileNames(const string &directoryName) {

        // Converts string to const char *
        const char *c = directoryName.c_str();

        // A type representing a directory stream.
        DIR *directory = nullptr;

        struct dirent *ent;
        vector<string> filesNames;

        directory = opendir(c);

        if (directory == nullptr) {
            perror("error...");
            return filesNames;
        }


        while ((ent = readdir(directory)) != nullptr) {
            string s = ent->d_name;

            // Skip ".' and ".." names
            if (s == "." || s == "..") {
                continue;
            }
            filesNames.push_back(s);
        }
        closedir(directory);

        return filesNames;
    }

/*    FILE *openInputFile(const string &name) throw(InfraException) {

        const string kPath = "resources/";

        string strFullName = kPath + name;
        // Convert the string to const char
        const char *charFullName = strFullName.c_str();

        FILE *inFile = fopen(charFullName, "rb");

        if (!inFile) {
            throw InfraException("File could not be opened");
        }
        return inFile;
    }*/

    FILE* openFile(const string &name, const string &type) throw(InfraException) {
        const string kPath = "resources/";

        string strFullName = kPath + name;
        // Convert the string to const char
        const char *charFullName = strFullName.c_str();
        const char *charType = type.c_str();

        FILE *inFile = fopen(charFullName, charType);

        if (!inFile) {
            throw InfraException("File could not be opened");
        }
        return inFile;
    }

    FILE* openOutputFile(const string &name) throw(InfraException) {
        return openFile(name, "wb");
    }

    FILE* openInputFile(const string &name) throw(InfraException) {
        return openFile(name, "rb");
    }
}

#endif //FILE_SERVER_FILEHANDLER_H
