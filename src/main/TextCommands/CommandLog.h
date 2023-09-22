#ifndef TEXTBASED_COMMANDLOG_H
#define TEXTBASED_COMMANDLOG_H

#include "Command.h"
class CommandLog {
    std::vector<Command> commands;
public:
    CommandLog();

    void addCommand(const Command &command);

    std::vector<Command> getCommands() const;
};


#endif //TEXTBASED_COMMANDLOG_H
