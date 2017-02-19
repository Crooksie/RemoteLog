#include <zmq.hpp>

#include <iostream>
#include <thread>

#include <unistd.h>


void server()
{
    std::cout << "Starting Server" << std::endl;

    //  Prepare our context and socket
    zmq::context_t context (1);
    zmq::socket_t socket (context, ZMQ_PULL);
    socket.bind ("ipc://localhost:4444");
    while (true) {
//        std::cout << "Server waiting for message" << std::endl;
        char buf[100];
        socket.recv (buf, 100);
        std::cout << "Server received: " << buf << std::endl;

    }
}


void client()
{
    std::cout << "Starting Client" << std::endl;
    //  Prepare our context and socket
    zmq::context_t context (1);
    zmq::socket_t socket (context, ZMQ_PUSH);
    socket.connect ("ipc://localhost:4444");

    unsigned int current = 1;

    while (true) {
//        std::cout << "Client Sending" << std::endl;
        char buf[100] = {0};
        const auto len = sprintf(buf, "Hello %d", current++);
        socket.send (buf, len);

        //  Do some 'work'
        sleep(1);
    }
}

int main (void)
{
    std::thread serverThread(server);
    std::thread clientThread(client);


    sleep(20);
    return 0;
}


