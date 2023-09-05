#include <spdlog/spdlog.h>
#include "TextCommandSystem.h"
#include "../EventSystem/EventBus.h"
#include "../HighLevel/ECSManager.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

TextCommandSystem::TextCommandSystem() {
    listenToEvents();
}

void TextCommandSystem::listenToEvents() {
    eventBus->listenToEvent<ProcessedTextEvent>(this, &TextCommandSystem::onCommand);
}

void TextCommandSystem::onCommand(ProcessedTextEvent &event) {
    spdlog::debug("Processed text event: {}", event.processedText);
}
