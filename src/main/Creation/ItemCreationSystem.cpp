#include "ItemCreationSystem.h"
#include "../HighLevel/ECSManager.h"
#include "CreateItemEvent.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../Woodworking/AxeComponent.h"
#include "../MainPlayer/TiedChildComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

ItemCreationSystem::ItemCreationSystem(){
    requireComponent<MainPlayerComponent>();
    listenToEvents();
}
void ItemCreationSystem::listenToEvents(){
    eventBus->listenToEvent<CreateItemEvent>(this, &ItemCreationSystem::onCreate);
}
void ItemCreationSystem::onCreate(CreateItemEvent& event){
    switch (event.item){
        case Item::AXE: createAxe();
        case Item::WOOD_PILE: createWoodPile(event.position);
        default: break;
    }
}

void ItemCreationSystem::createAxe(){
    auto mainPlayer = *getRelevantEntities().begin();
    auto mainPlayerPosition = ecsManager->getComponentFromEntity<PositionComponent>(mainPlayer).getPosition();
    auto axe = ecsManager->createEntity();
    ecsManager->addComponentToEntity<TiedChildComponent>(mainPlayer, axe);

    ecsManager->addComponentToEntity<TextComponent>(axe, "exAxe\n  x\n  e");
    ecsManager->addComponentToEntity<PositionComponent>(
            axe, mainPlayerPosition + Position(AXE_X_OFFSET, AXE_Y_OFFSET));
    ecsManager->addComponentToEntity<StyleComponent>(axe);
    ecsManager->addComponentToEntity<AxeComponent>(axe);
}

void ItemCreationSystem::createWoodPile(Position position) {
    auto wood = ecsManager->createEntity();
    ecsManager->addComponentToEntity<TextComponent>(wood, "Wood");
    ecsManager->addComponentToEntity<PositionComponent>(wood, position);
    ecsManager->addComponentToEntity<StyleComponent>(wood);
}
