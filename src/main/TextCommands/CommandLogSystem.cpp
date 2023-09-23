#include <spdlog/spdlog.h>
#include "CommandLogSystem.h"
#include "../EventSystem/EventBus.h"
#include "../TextInput/ProspectiveTextCommandEvent.h"

extern std::unique_ptr<EventBus> eventBus;


CommandLogSystem::CommandLogSystem() {
    listenToEvents();
}

void CommandLogSystem::addCommand(const AuthoredCommand& command) {
    commands.push_back(command);
}

std::vector<AuthoredCommand> CommandLogSystem::getCommands() const {
    return commands;
}

void CommandLogSystem::listenToEvents() {
    eventBus->listenToEvent<ProspectiveTextCommandEvent>(this, &CommandLogSystem::onCommand);
}

void CommandLogSystem::onCommand(ProspectiveTextCommandEvent &event) {
    commands.emplace_back(Author::PLAYER, Command(event.command, event.subject));
//    spdlog::debug("Commands in the list:");
//    for (const auto& command : commands) {
//        spdlog::debug("Author: {}, AuthoredCommand: {}", static_cast<int>(command.author), command.command);
//    }
}