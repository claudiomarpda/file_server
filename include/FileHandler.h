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

   const string kFilesDirectory = "resources/";

    /**
    * Read the name of all files in the given directory
    * @see http://pubs.opengroup.org/onlinepubs/7908799/xsh/dirent.h.html
    *
    * @return a vector with all names
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

    /**
     * @see http://www.cplusplus.com/reference/cstdio/fopen/
     *
     * @return a pointer to a file
     */
    FILE *openFile(const string &name, const string &type) throw(InfraException) {
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

    /**
     * Open a file for writing
     */
    FILE *openOutputFile(const string &name) throw(InfraException) {
        return openFile(name, "wb");
    }

    /**
     * Open a file for reading
     */
    FILE *openInputFile(const string &name) throw(InfraException) {
        return openFile(name, "rb");
    }
}

#endif //FILE_SERVER_FILEHANDLER_H
