cmake_minimum_required(VERSION 3.6)
project(RemoteLog)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}")
FIND_PACKAGE(ZMQ)

set(SOURCE_FILES
        main.cpp
        MessageClient.cpp
        MessageClient.h
        MessageServer.cpp
        MessageServer.h
        )


add_executable(RemoteLog ${SOURCE_FILES} ${ZMQ_LIBRARY})

include_directories(${ZMQ_INCLUDE_DIRS})

TARGET_LINK_LIBRARIES(RemoteLog ${ZMQ_LIBRARY})
