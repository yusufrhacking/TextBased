#ifndef TEXTBASED_AUTHOREDCOMMAND_H
#define TEXTBASED_AUTHOREDCOMMAND_H

#include <string>
#include <utility>
#include "Command.h"

enum class Author{
    PLAYER,
    ENGINEER,
    BRICOLEUR
};

struct AuthoredCommand{
    Author author;
    Command command;
    AuthoredCommand(Author author, Command command): author(author), command(command){}
};

#endif
