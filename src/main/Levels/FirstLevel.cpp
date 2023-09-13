#include "FirstLevel.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../PositionsAndMovement/CollisionComponent.h"
#include "../MainPlayer/TiedChildComponent.h"
#include "../Woodworking/AxeComponent.h"
#include "../Inventory/InventoryComponent.h"
#include "../PositionsAndMovement/LiveComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;

FirstLevel::FirstLevel(Position startingPosition): startingPosition(startingPosition) {
    witt = ecsManager->createEntity();
    createTree();
    createPlayer();
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


