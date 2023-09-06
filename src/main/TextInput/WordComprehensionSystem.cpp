#include <spdlog/spdlog.h>
#include "GameKeyEvent.h"
#include "WordComprehensionSystem.h"
#include "TextQueuedEvent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

WordComprehensionSystem::WordComprehensionSystem() {
    listenToEvents();
    listening_to_letters = false;
}

void WordComprehensionSystem::listenToEvents(){
    eventBus->listenToEvent<GameKeyEvent>(this, &WordComprehensionSystem::onGameKey);
    eventBus->listenToEvent<TextInputEvent>(this, &WordComprehensionSystem::onText);
}
void WordComprehensionSystem::onGameKey(GameKeyEvent& event){
    if (event.getKey() == GameKey::TEXT_FLIP){
        listening_to_letters = !listening_to_letters;
        spdlog::debug("TEXT FLIPPING to {}", listening_to_letters);
    }
    else if (event.getKey() == GameKey::END_OF_TEXT){
        listening_to_letters = false;
        spdlog::debug("TEXT ENDING AT: {}", text);
        eventBus->emitEvent<TextCommandEvent>(TextCommandEvent(text));
        text = "";
    }
}

void WordComprehensionSystem::onText(TextInputEvent &event) {
    if (listening_to_letters){
        auto newText = std::string(event.textEvent.text);
        spdlog::debug("Event text: {}", newText);
        text += newText;
    }
}

void WordComprehensionSystem::render(const std::shared_ptr<Renderer> &renderer, Camera camera) {
    renderer->renderTerminal(text);
}

