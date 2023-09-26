#include "PlaceSystem.h"
#include "../HighLevel/ECSManager.h"
#include "InventoryComponent.h"
#include "PlaceEvent.h"
#include "../MainPlayer/MainPlayerAccessSystem.h"
#include "../Creation/ItemComponent.h"
#include "../PositionsAndMovement/LiveComponent.h"
#include "../PositionsAndMovement/PositionComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

PlaceSystem::PlaceSystem(){
    listenToEvents();
}
void PlaceSystem::listenToEvents(){
    eventBus->listenToEvent<PlaceEvent>(this, &PlaceSystem::onPlacement);
}
void PlaceSystem::onPlacement(PlaceEvent& event){
    auto mainPlayer = ecsManager->getSystem<MainPlayerAccessSystem>().getMainPlayer();
    auto& inventoryComponent = ecsManager->getComponentFromEntity<InventoryComponent>(mainPlayer);
    auto& inventory = inventoryComponent.inventory;
    auto& inventoryItems = inventory.getItems();

    for (auto it = inventoryItems.begin(); it != inventoryItems.end(); ++it){
        auto item = *it;
        if (ecsManager->getComponentFromEntity<ItemComponent>(item).type == event.type){
            ecsManager->addComponentToEntity<LiveComponent>(item);
            auto& itemPosition = ecsManager->getComponentFromEntity<PositionComponent>(item);
            itemPosition = ecsManager->getComponentFromEntity<PositionComponent>(mainPlayer);

            inventory.removeItemAt(it);
            break;
        }
    }
}
