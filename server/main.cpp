#include <zmq.hpp>

#include <iostream>
#include <thread>
#include <sstream>
#include "../message/Message.h"

int main (void)
{
    std::cout << "Starting Server" << std::endl;

    //  Prepare our context and socket
    zmq::context_t context (1);
    zmq::socket_t socket (context, ZMQ_PULL);
    socket.bind ("ipc:///tmp/shared");
    int lastPid = -1;
    while (true) {
//        std::cout << "Server waiting for message" << std::endl;
        char buf[500] = {0};
       const auto received = socket.recv ((void*)buf, 500, 0);
        if (received == 0) continue;
        std::string msg(buf);
        const auto message = Message::deserialise(msg);
        if (lastPid != message.getPid())
        {
            std::cout << "\033[0;34m" << message.getPid();
        } else
        {
            std::cout << "\033[0;34m     ";
        }
        lastPid = message.getPid();
        std::cout << " \033[37;40m " << message.getMessage() << std::endl;

    }




//    unsigned int current = 1;
//    std::stringstream input;
//    while (input << std::cin) {
//        std::cout << "Client Sending" << std::endl;
//        char buf[100] = {0};
//        std::string text;
//        input >> text;
//        socket.send(text.data(), text.size());
//
//
//        //  Do some 'work'
//        sleep(1);
//    }

}


