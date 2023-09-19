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
#include "../Text/Split.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

TextCommandSystem::TextCommandSystem() {
    listenToEvents();
}

void TextCommandSystem::listenToEvents() {
    eventBus->listenToEvent<TextCommandEvent>(this, &TextCommandSystem::onCommand);
}

void TextCommandSystem::onCommand(TextCommandEvent &event) {
    auto words = Split::getWords(event.processedText);
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
}
