#include "BasicLevel.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../PositionsAndMovement/CollisionComponent.h"
#include "../MainPlayer/TiedChildComponent.h"
#include "../Woodworking/AxeComponent.h"
#include "../Inventory/InventoryComponent.h"
#include "../PositionsAndMovement/LiveComponent.h"
#include "../Lettering/LetterComponent.h"
#include "../TerminalUI/FixedPositionComponent.h"
#include "../TerminalUI/LiveTerminalRenderSystem.h"
#include "../TerminalUI/TerminalUnderscoreComponent.h"
#include "../Abyz/AbyzComponent.h"
#include "../Health/HealthComponent.h"
#include "../Attacking/AttackableComponent.h"
#include "../Health/OnDeathComponent.h"
#include "../Creation/ItemCreationSystem.h"
#include "../Woodworking/ChoppableComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;


BasicLevel::BasicLevel(Position startingPosition): startingPosition(startingPosition) {
    witt = ecsManager->createEntity();
    createTree();
    createPlayer();
    createLetter('a', startingPosition + Position(-100, 0));
    createLetter('x', startingPosition + Position(100, 0));
    createLetter('e', startingPosition + Position(0, -100));
    createAbyz();
}

void BasicLevel::createPlayer() {
    ecsManager->addComponentToEntity<TextComponent>(witt, "Witt");
    ecsManager->addComponentToEntity<PositionComponent>(witt, startingPosition);
    ecsManager->addComponentToEntity<MainPlayerComponent>(witt, std::make_shared<Velocity>(15, 15));
    ecsManager->addComponentToEntity<GenericStyleComponent>(witt);
    ecsManager->addComponentToEntity<CollisionComponent>(witt);
    ecsManager->addComponentToEntity<InventoryComponent>(witt);
    ecsManager->addComponentToEntity<LiveComponent>(witt);
    ecsManager->addComponentToEntity<HealthComponent>(witt, 10);
}

void BasicLevel::createTree() {
    auto tree = ecsManager->createEntity();
    ecsManager->addComponentToEntity<TextComponent>(tree, TextGenerator::getTreeText());
    Position treePosition = startingPosition + Position(100, 200);
    ecsManager->addComponentToEntity<PositionComponent>(tree, treePosition);
    ecsManager->addComponentToEntity<GenericStyleComponent>(tree);
    ecsManager->addComponentToEntity<CollisionComponent>(tree);
    ecsManager->addComponentToEntity<TreeComponent>(tree);
    ecsManager->addComponentToEntity<LiveComponent>(tree);
    ecsManager->addComponentToEntity<OnDeathComponent>(tree, [this, treePosition]() {
        eventBus->emitEvent<CreateItemAtPositionEvent>(Item::WOOD, TreeComponent::findTreeMiddle(treePosition));
    });
    ecsManager->addComponentToEntity<ChoppableComponent>(tree);
}

void BasicLevel::createLetter(char letter, Position position) {
    auto letterA = ecsManager->createEntity();
    ecsManager->addComponentToEntity<TextComponent>(letterA, std::string(1, letter));
    ecsManager->addComponentToEntity<PositionComponent>(letterA, position);
    ecsManager->addComponentToEntity<GenericStyleComponent>(letterA, Type::PLAIN_LETTER);
    ecsManager->addComponentToEntity<LiveComponent>(letterA);
    ecsManager->addComponentToEntity<LetterComponent>(letterA, char_to_enum(letter));
}

void BasicLevel::createAbyz() {
    auto abyz1 = ecsManager->createEntity();
    ecsManager->addComponentToEntity<TextComponent>(abyz1, "Abyz");
    ecsManager->addComponentToEntity<PositionComponent>(abyz1, startingPosition + Position(400, -150));
    ecsManager->addComponentToEntity<GenericStyleComponent>(abyz1, Type::PLAIN_TEXT);
    ecsManager->addComponentToEntity<LiveComponent>(abyz1);
    ecsManager->addComponentToEntity<AbyzComponent>(abyz1);
    ecsManager->addComponentToEntity<HealthComponent>(abyz1, 5);
    ecsManager->addComponentToEntity<AttackableComponent>(abyz1);
    ecsManager->addComponentToEntity<OnDeathComponent>(abyz1, [this, abyz1]() {
        eventBus->emitEvent<CreateItemAtEntityEvent>(Item::LETTER, abyz1);
    });
    ecsManager->addComponentToEntity<CollisionComponent>(abyz1);

}


