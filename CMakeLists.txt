cmake_minimum_required(VERSION 3.6)
project(RemoteLog)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMakeModules")
FIND_PACKAGE(ZMQ)

add_subdirectory(client)
add_subdirectory(server)


