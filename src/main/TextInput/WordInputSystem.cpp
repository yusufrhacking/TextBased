#include <spdlog/spdlog.h>
#include "GameKeyEvent.h"
#include "WordInputSystem.h"
#include "TextQueuedEvent.h"
#include "../TextCommands/ProcessedTextEvent.h"
#include "../Grammar/GrammarEvent.h"

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
    switch (event.getKey()){
        case GameKey::TEXT_FLIP: handleTextFlip(); break;
        case GameKey::BACKSPACE: handleBackSpace(); break;
        case GameKey::REPEAT_COMMAND: handleRepeatCommand(); break;
        default: break;
    }
}

void WordInputSystem::onText(TextInputEvent &event) {
    if (listening_to_letters){
        auto newText = std::string(event.textEvent.text);
        spdlog::trace("Event text: {}", newText);
        text += newText;
    }
}

void WordInputSystem::render(const std::shared_ptr<Renderer> &renderer, Camera camera) {
    renderer->renderTerminal(text);
}

void WordInputSystem::handleTextFlip() {
    listening_to_letters = !listening_to_letters;
    spdlog::trace("TEXT FLIPPING to {} with {}", listening_to_letters, text);
    if (!text.empty()){
        eventBus->emitEvent<GrammarEvent>(text);
        lastCommand = text;
    }
    text = "";
}

void WordInputSystem::handleBackSpace() {
    if (!text.empty()){
        text.pop_back();
    }
}

void WordInputSystem::handleRepeatCommand() {
    if (!lastCommand.empty()){
        if (text.empty()){
            eventBus->emitEvent<GrammarEvent>(lastCommand);
        }
    }
}

