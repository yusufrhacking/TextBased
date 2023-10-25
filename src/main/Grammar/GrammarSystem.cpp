#include <spdlog/spdlog.h>
#include "GrammarSystem.h"
#include "../EventSystem/EventBus.h"
#include "GrammarEvent.h"
#include "../TextCommands/CharacterSpendEvent.h"
#include "../Text/Split.h"
#include "../TextInput/TextCommandEvent.h"

extern std::unique_ptr<EventBus> eventBus;

GrammarSystem::GrammarSystem() {
    commandKeywords.insert("chop");
    commandKeywords.insert("create");
    commandKeywords.insert("stash");
    commandKeywords.insert("place");
    commandKeywords.insert("pickup");
    commandKeywords.insert("free");
    commandKeywords.insert("attack");
    commandKeywords.insert("punch");

    subjectKeywords.insert("axe");
    subjectKeywords.insert("wood");
    listenToEvents();
}

void GrammarSystem::listenToEvents() {
    eventBus->listenToEvent<GrammarEvent>(this, &GrammarSystem::onGrammar);
}

std::pair<std::string, std::string> GrammarSystem::splitCommandAndSubject(const std::string& text) const {
    auto words = Split::getWords(text);

    std::string command;
    std::string subject;

    if (!words.empty() && isCommandKeyword(words[0])) {
        command = words[0];
        subject = (words.size() > 1 && isSubjectKeyword(words[1])) ? words[1] : "";
    }

    return {command, subject};
}

void GrammarSystem::onGrammar(GrammarEvent &event) {
    auto [command, subject] = splitCommandAndSubject(event.text);
    if (command == "create"){
        eventBus->emitEvent<CharacterSpendEvent>(command, subject);
    } else{
        eventBus->emitEvent<TextCommandEvent>(command, subject);
    }
}

bool GrammarSystem::isCommandKeyword(const std::string& keyword) const {
    return commandKeywords.find(keyword) != commandKeywords.end();
}

bool GrammarSystem::isSubjectKeyword(const std::string& keyword) const {
    return subjectKeywords.find(keyword) != subjectKeywords.end();
}

