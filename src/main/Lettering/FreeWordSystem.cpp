#include "FreeWordSystem.h"
#include "../EventSystem/EventBus.h"
#include "../HighLevel/ECSManager.h"
#include "CharacterStorageSystem.h"
#include "FreeWordEvent.h"
#include "../MainPlayer/MainPlayerAccessSystem.h"
#include "../Inventory/InventoryComponent.h"
#include "WordDepositEvent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

FreeWordSystem::FreeWordSystem() {
    listenToEvents();
}

void FreeWordSystem::listenToEvents() {
    eventBus->listenToEvent<FreeWordEvent>(this, &FreeWordSystem::onFreeWord);
}

void FreeWordSystem::onFreeWord(FreeWordEvent &event) {
    Item type = event.type;
    Entity mainPlayer = ecsManager->getSystem<MainPlayerAccessSystem>().getMainPlayer();
    Inventory inventory = ecsManager->getComponentFromEntity<InventoryComponent>(mainPlayer).inventory;
    if (inventory.hasItems(type)){
        auto entity = inventory.removeAnItem(type);
        ecsManager->killEntity(entity);
        eventBus->emitEvent<WordDepositEvent>(event.word);
    }
}