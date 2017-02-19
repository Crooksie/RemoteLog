cmake_minimum_required(VERSION 3.6)
project(Server)

set(SOURCE_FILES
        main.cpp
        ../message/Message.cpp)

add_executable(Server ${SOURCE_FILES} ${ZMQ_LIBRARY})

include_directories(${ZMQ_INCLUDE_DIRS})

TARGET_LINK_LIBRARIES(Server ${ZMQ_LIBRARY})
