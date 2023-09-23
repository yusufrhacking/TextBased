#ifndef TEXTBASED_COMMAND_H
#define TEXTBASED_COMMAND_H

#include <string>
struct Command{
    std::string command;
    std::string subject;
    Command(std::string command, std::string subject): command(command), subject(subject){}
};

#endif //TEXTBASED_COMMAND_H
