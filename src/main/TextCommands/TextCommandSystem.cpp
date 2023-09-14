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
#include "../Inventory/StashPlayerItemEvent.h"

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
    bool stashNext = false;
//    for (const auto& word: words) {
//        if (addNext){
//            if (word == "axe"){
//                eventBus->emitEvent<CreatePlayerItemEvent>(Item::AXE);
//            }
//            addNext = false;
//        }
//        if (placeNext){
//            if (word == "wood"){
//                eventBus->emitEvent<PlaceEvent>(Item::WOOD);
//            }
//            placeNext = false;
//        }
//        if (stashNext){
//            if (word == "axe"){
//                eventBus->emitEvent<StashPlayerItemEvent>(Item::AXE);
//            }
//            stashNext = false;
//        }
//        if (word == "create"){
//            addNext = true;
//        }
//        if (word == "place"){
//            placeNext = true;
//        }
//        if (word == "stash"){
//            stashNext = true;
//        }
//        if (word == "pickup"){
//            eventBus->emitEvent<PlayerPickUpEvent>(ecsManager->getSystem<MainPlayerAccessSystem>().getMainPlayer());
//        }
//    }
    if (event.processedText == "chop") {
        eventBus->emitEvent<ChopEvent>(ChopEvent());
    }
    if (event.processedText == "create axe"){
        eventBus->emitEvent<CreatePlayerItemEvent>(Item::AXE);
    }
    if (event.processedText == "stash axe"){
        eventBus->emitEvent<StashPlayerItemEvent>(Item::AXE);
    }
    if (event.processedText == "place wood"){
        eventBus->emitEvent<PlaceEvent>(Item::WOOD);
    }
    if (event.processedText == "pickup"){
        eventBus->emitEvent<PlayerPickUpEvent>(ecsManager->getSystem<MainPlayerAccessSystem>().getMainPlayer());
    }
//
//    if (event.processedText == "stash axe") {
//        eventBus->emitEvent<StashPlayerItemEvent>(Item::AXE);
//    }
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
