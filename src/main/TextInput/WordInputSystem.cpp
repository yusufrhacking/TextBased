#include <spdlog/spdlog.h>
#include "GameKeyEvent.h"
#include "WordInputSystem.h"
#include "TextQueuedEvent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

WordInputSystem::WordInputSystem() {
    listenToEvents();
    listening_to_letters = false;
}

void WordInputSystem::listenToEvents(){
    eventBus->listenToEvent<GameKeyEvent>(this, &WordInputSystem::onGameKey);
    eventBus->listenToEvent<TextInputEvent>(this, &WordInputSystem::onText);
}
void WordInputSystem::onGameKey(GameKeyEvent& event){
    if (event.getKey() == GameKey::TEXT_FLIP){
        listening_to_letters = !listening_to_letters;
        spdlog::debug("TEXT FLIPPING to {} with {}", listening_to_letters, text);
        if (!text.empty()){
            eventBus->emitEvent<TextCommandEvent>(TextCommandEvent(text));
        }
        text = "";
    }
    if (event.getKey() == GameKey::BACKSPACE){
        if (!text.empty()){
            text.pop_back();
        }
    }
}

void WordInputSystem::onText(TextInputEvent &event) {
    if (listening_to_letters){
        auto newText = std::string(event.textEvent.text);
        spdlog::debug("Event text: {}", newText);
        text += newText;
    }
}

void WordInputSystem::render(const std::shared_ptr<Renderer> &renderer, Camera camera) {
    renderer->renderTerminal(text);
}

