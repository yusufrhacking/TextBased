#include <spdlog/spdlog.h>
#include "TextCommandSystem.h"
#include "../EventSystem/EventBus.h"
#include "../HighLevel/ECSManager.h"
#include "../Woodworking/ChopEvent.h"
#include "../Creation/CreateItemAtPositionEvent.h"
#include "../Inventory/PlayerPickUpEvent.h"
#include "../Creation/CreatePlayerItemEvent.h"
#include "../MainPlayer/MainPlayerAccessSystem.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

TextCommandSystem::TextCommandSystem() {
    listenToEvents();
}

void TextCommandSystem::listenToEvents() {
    eventBus->listenToEvent<TextCommandEvent>(this, &TextCommandSystem::onCommand);
}

void TextCommandSystem::onCommand(TextCommandEvent &event) {
    auto words = getWords(event.processedText);
    bool addNext = false;
    for (const auto& word: words){
        if (addNext){
            if (word == "axe"){
                eventBus->emitEvent<CreatePlayerItemEvent>(Item::AXE);
            }
            addNext = false;
        }
        if (word == "create"){
            addNext = true;
        }
        if (word == "pickup"){
            eventBus->emitEvent<PlayerPickUpEvent>(*ecsManager->getSystem<MainPlayerAccessSystem>().getRelevantEntities().begin());
        }
    }
    if (event.processedText == "chop"){
        eventBus->emitEvent<ChopEvent>(ChopEvent());
    }
//    spdlog::debug("Processed text event: {}", event.processedText);
}

std::vector<std::string> TextCommandSystem::getWords(std::string processedText) {
    std::istringstream iss(processedText);
    std::string token;
    std::vector<std::string> words;

    while(std::getline(iss, token, ' ')) {
        words.push_back(token);
    }
    return words;
}
