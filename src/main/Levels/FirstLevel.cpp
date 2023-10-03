#include "FirstLevel.h"
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

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;


FirstLevel::FirstLevel(Position startingPosition): startingPosition(startingPosition) {
    witt = ecsManager->createEntity();
    createTree();
    createPlayer();
    createLetter('a', startingPosition + Position(-100, 0));
    createLetter('x', startingPosition + Position(100, 0));
    createLetter('e', startingPosition + Position(0, -100));
    createAbyz();
}

void FirstLevel::createPlayer() {
    ecsManager->addComponentToEntity<TextComponent>(witt, "Witt");
    ecsManager->addComponentToEntity<PositionComponent>(witt, startingPosition);
    ecsManager->addComponentToEntity<MainPlayerComponent>(witt, std::make_shared<Velocity>(15, 15));
    ecsManager->addComponentToEntity<StyleComponent>(witt);
    ecsManager->addComponentToEntity<CollisionComponent>(witt);
    ecsManager->addComponentToEntity<InventoryComponent>(witt);
    ecsManager->addComponentToEntity<LiveComponent>(witt);
}

void FirstLevel::createTree() {
    auto tree = ecsManager->createEntity();
    ecsManager->addComponentToEntity<TextComponent>(tree, TextGenerator::getTreeText());
    ecsManager->addComponentToEntity<PositionComponent>(tree, startingPosition + Position(100, 200));
    ecsManager->addComponentToEntity<StyleComponent>(tree);
    ecsManager->addComponentToEntity<CollisionComponent>(tree);
    ecsManager->addComponentToEntity<TreeComponent>(tree);
    ecsManager->addComponentToEntity<LiveComponent>(tree);
}

void FirstLevel::createLetter(char letter, Position position) {
    auto letterA = ecsManager->createEntity();
    ecsManager->addComponentToEntity<TextComponent>(letterA, std::string(1, letter));
    ecsManager->addComponentToEntity<PositionComponent>(letterA, position);
    ecsManager->addComponentToEntity<StyleComponent>(letterA, Type::PLAIN_LETTER);
    ecsManager->addComponentToEntity<LiveComponent>(letterA);
    ecsManager->addComponentToEntity<LetterComponent>(letterA, char_to_enum(letter));
}

void FirstLevel::createAbyz() {
    auto abyz1 = ecsManager->createEntity();
    ecsManager->addComponentToEntity<TextComponent>(abyz1, "Abyz");
    ecsManager->addComponentToEntity<PositionComponent>(abyz1, startingPosition + Position(400, -150));
    ecsManager->addComponentToEntity<StyleComponent>(abyz1, Type::PLAIN_TEXT);
    ecsManager->addComponentToEntity<LiveComponent>(abyz1);
    ecsManager->addComponentToEntity<AbyzComponent>(abyz1);
    ecsManager->addComponentToEntity<HealthComponent>(abyz1, 5);
    ecsManager->addComponentToEntity<AttackableComponent>(abyz1);
    ecsManager->addComponentToEntity<OnDeathComponent>(abyz1, [this, abyz1]() {
        eventBus->emitEvent<CreatePlayerItemEvent>(Item::AXE);
    });
}


