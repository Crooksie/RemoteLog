cmake_minimum_required(VERSION 3.6)
project(TerminalLog)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}")
FIND_PACKAGE(ZMQ)

set(SOURCE_FILES main.cpp MessageClient.cpp MessageClient.h MessageServer.cpp MessageServer.h)
add_executable(TerminalLog ${SOURCE_FILES} ${ZMQ_LIBRARY})
add_executable(TerminalLog2 syncsub.c ${ZMQ_LIBRARY})
include_directories(${ZMQ_INCLUDE_DIRS})


#FIND_LIBRARY(ZMQ_LIB libzmq)
TARGET_LINK_LIBRARIES(TerminalLog ${ZMQ_LIBRARY})
TARGET_LINK_LIBRARIES(TerminalLog2 ${ZMQ_LIBRARY})
