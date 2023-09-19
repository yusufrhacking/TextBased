#include <spdlog/spdlog.h>
#include "GrammarSystem.h"
#include "../EventSystem/EventBus.h"
#include "GrammarEvent.h"
#include "../TextCommands/ProcessedTextEvent.h"

extern std::unique_ptr<EventBus> eventBus;

GrammarSystem::GrammarSystem() {
    listenToEvents();
}

void GrammarSystem::listenToEvents() {
    eventBus->listenToEvent<GrammarEvent>(this, &GrammarSystem::onGrammar);
}

void GrammarSystem::onGrammar(GrammarEvent &event) {
    spdlog::debug("Grammar Event");
    eventBus->emitEvent<ProcessedTextEvent>(event.text);
}
