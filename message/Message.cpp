//
// Created by crooksie on 19/02/17.
//

#include <sstream>
#include "Message.h"

Message::Message(int pid, const std::string &message) : pid(pid), message(message) {}

int Message::getPid() const {
    return pid;
}

const std::string &Message::getMessage() const {
    return message;
}

std::string Message::serialise() const {
    std::stringstream stringstream;
    stringstream << pid;
    stringstream << message;
    std::string data;
    stringstream >> data;
    return data;
}

Message Message::deserialise(const std::string &message) {
    std::stringstream stringstream(message);
    int pid;
    stringstream >> pid;
    std::string msg;
    stringstream >> msg;
    return Message(pid, msg);
}
