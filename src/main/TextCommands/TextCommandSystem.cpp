#include <spdlog/spdlog.h>
#include "TextCommandSystem.h"
#include "../EventSystem/EventBus.h"
#include "../HighLevel/ECSManager.h"
#include "../Woodworking/ChopEvent.h"
#include "../Creation/CreateItemAtPositionEvent.h"
#include "../Inventory/PlayerPickUpEvent.h"
#include "../Creation/CreatePlayerItemEvent.h"
#include "../MainPlayer/MainPlayerAccessSystem.h"
#include "../Inventory/PlaceEvent.h"
#include "../Creation/StashPlayerItemEvent.h"

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
    bool placeNext = false;
    for (const auto& word: words) {
        if (addNext){
            if (word == "axe"){
                eventBus->emitEvent<CreatePlayerItemEvent>(Item::AXE);
            }
            addNext = false;
        }
        if (placeNext){
            if (word == "wood"){
                eventBus->emitEvent<PlaceEvent>(Item::WOOD);
            }
            placeNext = false;
        }
        if (word == "create"){
            addNext = true;
        }
        if (word == "place"){
            placeNext = true;
        }
        if (word == "pickup"){
            eventBus->emitEvent<PlayerPickUpEvent>(*ecsManager->getSystem<MainPlayerAccessSystem>().getRelevantEntities().begin());
        }
    }
    if (event.processedText == "chop") {
        eventBus->emitEvent<ChopEvent>(ChopEvent());
    }

    if (event.processedText == "stash axe") {
//        std:: cout << "hello";
        eventBus->emitEvent<StashPlayerItemEvent>(Item::AXE);
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
