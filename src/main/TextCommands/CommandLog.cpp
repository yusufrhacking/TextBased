#include "CommandLog.h"

CommandLog::CommandLog() = default;

void CommandLog::addCommand(const Command& command) {
    commands.push_back(command);
}

std::vector<Command> CommandLog::getCommands() const {
    return commands;
}
