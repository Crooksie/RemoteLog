#include <zmq.hpp>

#include <iostream>
#include <thread>
#include <sstream>
#include <unistd.h>
#include "../message/Message.h"

int main (void)
{
    std::cout << "Starting Client" << std::endl;
    zmq::context_t context (1);
    zmq::socket_t socket (context, ZMQ_PUSH);
    socket.connect ("ipc:///tmp/shared");

    std::string lineInput;
    while (getline(std::cin,lineInput)) {
        int  pid = getpid();
        Message message(pid, lineInput);
        std::cout << lineInput << std::endl;
        auto encodedMessage = message.serialise();
        socket.send(encodedMessage.data(), encodedMessage.size());
    }

    return 0;
}


