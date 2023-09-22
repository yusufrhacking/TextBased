#ifndef TEXTBASED_COMMAND_H
#define TEXTBASED_COMMAND_H

#include <string>

enum class Author{

};

struct Command{
    Author author;
    std::string command;
};

#endif
