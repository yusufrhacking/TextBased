#include "ItemCreationSystem.h"
#include "../HighLevel/ECSManager.h"
#include "CreateItemAtPositionEvent.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../Woodworking/AxeComponent.h"
#include "../MainPlayer/TiedChildComponent.h"
#include "../Woodworking/WoodComponent.h"
#include "CreatePlayerItemEvent.h"
#include "ItemComponent.h"
#include "../Inventory/InventoryPickupComponent.h"
#include "../PositionsAndMovement/LiveComponent.h"
#include "../MainPlayer/MainPlayerAccessSystem.h"
#include "../Inventory/InventoryComponent.h"
#include "../Inventory/StashPlayerItemEvent.h"
#include "CreateItemAtEntityEvent.h"
#include "../Lettering/Letter.h"
#include "../Lettering/LetterComponent.h"
#include "../Attacking/ActiveWeaponComponent.h"
#include "CreateLetterAtPositionEvent.h"
#include "../MainPlayer/MainPlayerComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

ItemCreationSystem::ItemCreationSystem(){
    requireComponent<MainPlayerComponent>();
    listenToEvents();
}
void ItemCreationSystem::listenToEvents(){
    eventBus->listenToEvent<CreateItemAtPositionEvent>(this, &ItemCreationSystem::onCreateAtPosition);
    eventBus->listenToEvent<CreatePlayerItemEvent>(this, &ItemCreationSystem::onCreate);
    eventBus->listenToEvent<CreateItemAtEntityEvent>(this, &ItemCreationSystem::onCreateItemAtEntity);
    eventBus->listenToEvent<CreateLetterAtPositionEvent>(this, &ItemCreationSystem::onCreateLetterAtPosition);
}
void ItemCreationSystem::onCreateAtPosition(CreateItemAtPositionEvent& event){
    switch (event.item){
        case Item::WOOD: createWoodPile(event.position); break;
        default: break;
    }
}


void ItemCreationSystem::onCreate(CreatePlayerItemEvent& event) {
    switch (event.item){
        case Item::AXE: createAxe(); break;
        default: break;
    }
}

void ItemCreationSystem::createAxe(){
    auto mainPlayer = ecsManager->getSystem<MainPlayerAccessSystem>().getMainPlayer();
    auto mainPlayerPosition = ecsManager->getComponentFromEntity<PositionComponent>(mainPlayer).getPosition();
    auto axe = ecsManager->createEntity();
    ecsManager->addComponentToEntity<TiedChildComponent>(mainPlayer, axe);

    ecsManager->addComponentToEntity<TextComponent>(axe, "exAxe\n  x\n  e");
    ecsManager->addComponentToEntity<PositionComponent>(
            axe, mainPlayerPosition + AxeComponent::AXE_POSITION_OFFSET);
    ecsManager->addComponentToEntity<GenericStyleComponent>(axe);
    ecsManager->addComponentToEntity<AxeComponent>(axe);
    ecsManager->addComponentToEntity<ItemComponent>(axe, Item::AXE);
    ecsManager->addComponentToEntity<LiveComponent>(axe);

    if (!ecsManager->hasComponent<ActiveWeaponComponent>(mainPlayer)){
        ecsManager->addComponentToEntity<ActiveWeaponComponent>(mainPlayer, axe, Item::AXE);
    }
}

void ItemCreationSystem::createWoodPile(Position position) {
    auto wood = ecsManager->createEntity();
    ecsManager->addComponentToEntity<TextComponent>(wood, "Wood");
    ecsManager->addComponentToEntity<PositionComponent>(wood, position);
    ecsManager->addComponentToEntity<GenericStyleComponent>(wood);
    ecsManager->addComponentToEntity<WoodComponent>(wood);
    ecsManager->addComponentToEntity<ItemComponent>(wood, Item::WOOD);
    ecsManager->addComponentToEntity<InventoryPickupComponent>(wood, Item::WOOD);
    ecsManager->addComponentToEntity<LiveComponent>(wood);
}

void ItemCreationSystem::onCreateItemAtEntity(CreateItemAtEntityEvent &event) {
    switch (event.item){
        case Item::LETTER:
            createLetter(get_random_letter(), ecsManager->getComponentFromEntity<PositionComponent>(event.entity).getPosition());
            break;
        case Item::QUESTION_MARK:
            spdlog::info("AQUI");
            createLetter(Letter::QUESTION_MARK, ecsManager->getComponentFromEntity<PositionComponent>(event.entity).getPosition());
            break;
        default: break;
    }
}

void ItemCreationSystem::createLetter(Letter letter, Position position) {
    auto letterA = ecsManager->createEntity();
    ecsManager->addComponentToEntity<TextComponent>(letterA, std::string(1, enum_to_char(letter)));
    ecsManager->addComponentToEntity<PositionComponent>(letterA, position);
    ecsManager->addComponentToEntity<GenericStyleComponent>(letterA, Type::PLAIN_LETTER);
    ecsManager->addComponentToEntity<LiveComponent>(letterA);
    ecsManager->addComponentToEntity<LetterComponent>(letterA, letter);
}

void ItemCreationSystem::onCreateLetterAtPosition(CreateLetterAtPositionEvent &event) {
    auto letterEntity = ecsManager->createEntity();
    ecsManager->addComponentToEntity<TextComponent>(letterEntity, std::string(1, enum_to_char(event.letter)));
    ecsManager->addComponentToEntity<PositionComponent>(letterEntity, event.position);
    ecsManager->addComponentToEntity<GenericStyleComponent>(letterEntity, Type::PLAIN_LETTER);
    ecsManager->addComponentToEntity<LiveComponent>(letterEntity);
    ecsManager->addComponentToEntity<LetterComponent>(letterEntity, event.letter);
}

