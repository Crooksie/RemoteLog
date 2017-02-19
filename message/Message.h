//
// Created by crooksie on 19/02/17.
//

#ifndef REMOTELOG_MESSAGE_H
#define REMOTELOG_MESSAGE_H


#include <string>

class Message {
public:
    Message(int pid, const std::string &message);

    int getPid() const;

    const std::string &getMessage() const;
    std::string serialise() const;
    static Message deserialise(const std::string &message);


private:
    int pid;
    std::string message;
};


#endif //REMOTELOG_MESSAGE_H
