#include <spdlog/spdlog.h>
#include "CommandLogSystem.h"
#include "../EventSystem/EventBus.h"
#include "../TextInput/TextCommandEvent.h"
#include "../Diegesis/EngineerTerminalEvent.h"

extern std::unique_ptr<EventBus> eventBus;


CommandLogSystem::CommandLogSystem() {
    listenToEvents();
}

void CommandLogSystem::addCommand(const AuthoredCommand& command) {
    commands.push_back(command);
}

std::vector<AuthoredCommand> CommandLogSystem::getAuthoredCommands() const {
    return commands;
}

void CommandLogSystem::listenToEvents() {
    eventBus->listenToEvent<TextCommandEvent>(this, &CommandLogSystem::onCommand);
    eventBus->listenToEvent<EngineerTerminalEvent>(this, &CommandLogSystem::onEngineerText);
}

void CommandLogSystem::onCommand(TextCommandEvent &event) {
    commands.emplace_back(Author::PLAYER, Command(event.command, event.subject));
}

void CommandLogSystem::onEngineerText(EngineerTerminalEvent &event) {
    commands.emplace_back(Author::ENGINEER, Command(event.text));
}
