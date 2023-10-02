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
#include "../Lettering/FreeWordEvent.h"
#include "../Attacking/AttemptedAttackEvent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

TextCommandSystem::TextCommandSystem() {
    listenToEvents();
}

void TextCommandSystem::listenToEvents() {
    eventBus->listenToEvent<TextCommandEvent>(this, &TextCommandSystem::onCommand);
}

void TextCommandSystem::onCommand(TextCommandEvent &event) {
    auto command = event.command;
    auto subject = event.subject;
    if (command == "chop") {
        eventBus->emitEvent<ChopEvent>();
    } else if (command == "create") {
        eventBus->emitEvent<CreatePlayerItemEvent>(StringToItem(subject));
    } else if (command == "stash") {
        eventBus->emitEvent<StashPlayerItemEvent>(StringToItem(subject));
    } else if (command == "place") {
        eventBus->emitEvent<PlaceEvent>(StringToItem(subject));
    } else if (command == "pickup") {
        eventBus->emitEvent<PlayerPickUpEvent>(ecsManager->getSystem<MainPlayerAccessSystem>().getMainPlayer());
    } else if (command == "free") {
        eventBus->emitEvent<FreeWordEvent>(subject);
    } else if (command == "attack") {
        eventBus->emitEvent<AttemptedAttackEvent>(ecsManager->getSystem<MainPlayerAccessSystem>().getMainPlayer());
    }
}
