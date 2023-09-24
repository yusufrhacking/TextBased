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
namespace AuthorCommands{
    static std::string authorToText(Author author) {
        switch (author) {
            case Author::PLAYER:
                return "ThePlayer";
            case Author::ENGINEER:
                return "TheEngineer";
            case Author::BRICOLEUR:
                return "TheBricoleur";
            default:
                return ""; // Default case or you could throw an exception.
        }
    }
}


struct AuthoredCommand{
    Author author;
    Command command;
    AuthoredCommand(Author author, Command command): author(author), command(command){}
};

#endif
