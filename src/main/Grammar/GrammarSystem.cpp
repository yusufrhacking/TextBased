#include <spdlog/spdlog.h>
#include "GrammarSystem.h"
#include "../EventSystem/EventBus.h"
#include "GrammarEvent.h"
#include "../TextCommands/ProcessedTextEvent.h"
#include "../Text/Split.h"

extern std::unique_ptr<EventBus> eventBus;

GrammarSystem::GrammarSystem() {
    listenToEvents();
}

void GrammarSystem::listenToEvents() {
    eventBus->listenToEvent<GrammarEvent>(this, &GrammarSystem::onGrammar);
}

void GrammarSystem::onGrammar(GrammarEvent &event) {
    auto words = Split::getWords(event.text);
    for (auto word: words){

    }
    spdlog::debug("Grammar Event");
    eventBus->emitEvent<ProcessedTextEvent>(event.text);
}
