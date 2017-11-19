cmake_minimum_required(VERSION 3.9)
project(file_server)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

set(SOURCE_FILES main.cpp
        lib/netry/include/SocketException.h lib/netry/include/ServerSocket.h lib/netry/include/NetStream.h lib/netry/include/Socket.h
        lib/netry/src/ServerSocket.cpp lib/netry/src/Socket.cpp lib/netry/src/NetStream.cpp
        src/Client.cpp include/Client.h src/Server.cpp include/Server.h include/Consts.h include/FileHandler.h include/InfraException.h include/InfraException.h)

add_executable(file_server ${SOURCE_FILES})