#include "FullBasicLevel.h"
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
#include "../Text/TextGenerator.h"
#include "../Woodworking/TreeComponent.h"
#include "../MainPlayer/MainPlayerComponent.h"
#include "../HighLevel/ECSManager.h"
#include "../Woodworking/TreePrefab.h"
#include "../Abyz/AbyzPrefab.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;


FullBasicLevel::FullBasicLevel(Position startingPosition): startingPosition(startingPosition) {
    witt = ecsManager->createEntity();
    TreePrefab tree{startingPosition + Position(100, 200)};
    createPlayer();
    createLetter('a', startingPosition + Position(-100, 0));
    createLetter('x', startingPosition + Position(100, 0));
    createLetter('e', startingPosition + Position(0, -100));
    AbyzPrefab abyz{startingPosition + Position(400, -150)};
}

void FullBasicLevel::createPlayer() {
    ecsManager->addComponentToEntity<TextComponent>(witt, "Witt");
    ecsManager->addComponentToEntity<PositionComponent>(witt, startingPosition);
    ecsManager->addComponentToEntity<MainPlayerComponent>(witt, std::make_shared<Velocity>(15, 15));
    ecsManager->addComponentToEntity<StyleComponent>(witt);
    ecsManager->addComponentToEntity<CollisionComponent>(witt);
    ecsManager->addComponentToEntity<InventoryComponent>(witt);
    ecsManager->addComponentToEntity<LiveComponent>(witt);
    ecsManager->addComponentToEntity<HealthComponent>(witt, 10);
}

void FullBasicLevel::createTree() {
    auto tree = ecsManager->createEntity();
    ecsManager->addComponentToEntity<TextComponent>(tree, TextGenerator::getTreeText());
    Position treePosition = startingPosition + Position(100, 200);
    ecsManager->addComponentToEntity<PositionComponent>(tree, treePosition);
    ecsManager->addComponentToEntity<StyleComponent>(tree);
    ecsManager->addComponentToEntity<CollisionComponent>(tree);
    ecsManager->addComponentToEntity<TreeComponent>(tree);
    ecsManager->addComponentToEntity<LiveComponent>(tree);
    ecsManager->addComponentToEntity<OnDeathComponent>(tree, [this, treePosition]() {
        eventBus->emitEvent<CreateItemAtPositionEvent>(Item::WOOD, TreeComponent::findTreeMiddle(treePosition));
    });
}

void FullBasicLevel::createLetter(char letter, Position position) {
    auto letterA = ecsManager->createEntity();
    ecsManager->addComponentToEntity<TextComponent>(letterA, std::string(1, letter));
    ecsManager->addComponentToEntity<PositionComponent>(letterA, position);
    ecsManager->addComponentToEntity<StyleComponent>(letterA, Type::PLAIN_LETTER);
    ecsManager->addComponentToEntity<LiveComponent>(letterA);
    ecsManager->addComponentToEntity<LetterComponent>(letterA, char_to_enum(letter));
}

void FullBasicLevel::createAbyz() {
    auto abyz1 = ecsManager->createEntity();
    ecsManager->addComponentToEntity<TextComponent>(abyz1, "Abyz");
    ecsManager->addComponentToEntity<PositionComponent>(abyz1, startingPosition + Position(400, -150));
    ecsManager->addComponentToEntity<StyleComponent>(abyz1, Type::PLAIN_TEXT);
    ecsManager->addComponentToEntity<LiveComponent>(abyz1);
    ecsManager->addComponentToEntity<AbyzComponent>(abyz1);
    ecsManager->addComponentToEntity<HealthComponent>(abyz1, 5);
    ecsManager->addComponentToEntity<AttackableComponent>(abyz1);
    ecsManager->addComponentToEntity<OnDeathComponent>(abyz1, [this, abyz1]() {
        eventBus->emitEvent<CreateItemAtEntityEvent>(Item::LETTER, abyz1);
    });
    ecsManager->addComponentToEntity<CollisionComponent>(abyz1);

}


