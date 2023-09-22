#ifndef TEXTBASED_COMMAND_H
#define TEXTBASED_COMMAND_H

#include <string>
#include <utility>

enum class Author{
    PLAYER,
    ENGINEER,
    BRICOLEUR
};

struct Command{
    Author author;
    std::string command;
    Command(Author author, std::string command): author(author), command(std::move(command)){}
};

#endif
