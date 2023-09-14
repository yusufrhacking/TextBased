#include "ItemCreationSystem.h"
#include "../HighLevel/ECSManager.h"
#include "CreateItemAtPositionEvent.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../Woodworking/AxeComponent.h"
#include "../MainPlayer/TiedChildComponent.h"
#include "../Woodworking/WoodComponent.h"
#include "CreatePlayerItemEvent.h"
#include "ItemComponent.h"
#include "../Inventory/PickupComponent.h"
#include "../PositionsAndMovement/LiveComponent.h"
#include "../MainPlayer/MainPlayerAccessSystem.h"
#include "../Inventory/InventoryComponent.h"
#include "StashPlayerItemEvent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

ItemCreationSystem::ItemCreationSystem(){
    requireComponent<MainPlayerComponent>();
    listenToEvents();
}
void ItemCreationSystem::listenToEvents(){
    eventBus->listenToEvent<CreateItemAtPositionEvent>(this, &ItemCreationSystem::onCreateAtPosition);
    eventBus->listenToEvent<CreatePlayerItemEvent>(this, &ItemCreationSystem::onCreate);
    eventBus->listenToEvent<StashPlayerItemEvent>(this, &ItemCreationSystem::onStash);
}
void ItemCreationSystem::onCreateAtPosition(CreateItemAtPositionEvent& event){
    switch (event.item){
        case Item::WOOD: createWoodPile(event.position); break;
        default: break;
    }
}

void ItemCreationSystem::onStash(StashPlayerItemEvent& event) {
    switch (event.item) {
        case Item::AXE: stashAxe(); break;
        default: break;
    }
}

void ItemCreationSystem::stashAxe() {

}

void ItemCreationSystem::onCreate(CreatePlayerItemEvent& event) {
    switch (event.item){
        case Item::AXE: createAxe(); break;
        default: break;
    }
}

void ItemCreationSystem::createAxe(){
    auto mainPlayer = *getRelevantEntities().begin();
    auto mainPlayerPosition = ecsManager->getComponentFromEntity<PositionComponent>(mainPlayer).getPosition();
    auto axe = ecsManager->createEntity();
    ecsManager->addComponentToEntity<TiedChildComponent>(mainPlayer, axe);
    ecsManager->getComponentFromEntity<InventoryComponent>(mainPlayer).items.push_back(axe);

    ecsManager->addComponentToEntity<TextComponent>(axe, "exAxe\n  x\n  e");
    ecsManager->addComponentToEntity<PositionComponent>(
            axe, mainPlayerPosition + AxeComponent::AXE_POSITION_OFFSET);
    ecsManager->addComponentToEntity<StyleComponent>(axe);
    ecsManager->addComponentToEntity<AxeComponent>(axe);
    ecsManager->addComponentToEntity<ItemComponent>(axe, Item::AXE);
    ecsManager->addComponentToEntity<LiveComponent>(axe);
}

void ItemCreationSystem::createWoodPile(Position position) {
    auto wood = ecsManager->createEntity();
    ecsManager->addComponentToEntity<TextComponent>(wood, "Wood");
    ecsManager->addComponentToEntity<PositionComponent>(wood, position);
    ecsManager->addComponentToEntity<StyleComponent>(wood);
    ecsManager->addComponentToEntity<WoodComponent>(wood);
    ecsManager->addComponentToEntity<ItemComponent>(wood, Item::WOOD);
    ecsManager->addComponentToEntity<PickupComponent>(wood);
    ecsManager->addComponentToEntity<LiveComponent>(wood);

}

