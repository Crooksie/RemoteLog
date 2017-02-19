#include <zmq.hpp>

#include <iostream>
#include <thread>
#include <sstream>
#include <unistd.h>
#include "../message/Message.h"

int main (void)
{
    std::cout << "Starting Client" << std::endl;
    //  Prepare our context and socket
    zmq::context_t context (1);
    zmq::socket_t socket (context, ZMQ_PUSH);
    socket.connect ("ipc:///tmp/shared");

    std::string lineInput;
    while (getline(std::cin,lineInput)) {
        int  pid = getpid();

        Message message(pid, lineInput);
        std::cout << "Client Sending" << std::endl;
        auto encodedMessage = message.serialise();
        socket.send(encodedMessage.data(), encodedMessage.size());
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





    return 0;
}


