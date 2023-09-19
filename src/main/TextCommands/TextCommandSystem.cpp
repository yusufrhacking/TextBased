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
    grammarSystem.addCommandKeyword("chop");
    grammarSystem.addCommandKeyword("create");
    grammarSystem.addCommandKeyword("stash");
    grammarSystem.addCommandKeyword("place");
    grammarSystem.addCommandKeyword("pickup");

    grammarSystem.addSubjectKeyword("axe");
    grammarSystem.addSubjectKeyword("wood");
    listenToEvents();
}

void TextCommandSystem::listenToEvents() {
    eventBus->listenToEvent<TextCommandEvent>(this, &TextCommandSystem::onCommand);
}

void TextCommandSystem::onCommand(TextCommandEvent &event) {
    auto words = Split::getWords(event.processedText);
    auto [command, subject] = grammarSystem.splitCommandAndSubject(event.processedText);

    if (command == "chop") {
        eventBus->emitEvent<ChopEvent>();
    } else if (command == "create") {
        eventBus->emitEvent<CreatePlayerItemEvent>(Item::AXE);
    } else if (command == "stash") {
        eventBus->emitEvent<StashPlayerItemEvent>(Item::AXE);
    } else if (command == "place") {
        eventBus->emitEvent<PlaceEvent>(Item::WOOD);
    } else if (command == "pickup") {
        eventBus->emitEvent<PlayerPickUpEvent>(ecsManager->getSystem<MainPlayerAccessSystem>().getMainPlayer());
    }
}
