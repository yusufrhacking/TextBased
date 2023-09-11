#include "FirstLevel.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../PositionsAndMovement/CollisionComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;

FirstLevel::FirstLevel(Position startingPosition): startingPosition(startingPosition) {
    createPlayer();
    createTree();
    createAxe();
}

void FirstLevel::createPlayer() {
    witt = ecsManager->createEntity();
    ecsManager->addComponentToEntity<TextComponent>(witt, "Witt");
    ecsManager->addComponentToEntity<PositionComponent>(witt, startingPosition);
    ecsManager->addComponentToEntity<MainPlayerComponent>(witt, std::make_shared<Velocity>(15, 15));
    ecsManager->addComponentToEntity<StyleComponent>(witt);
    ecsManager->addComponentToEntity<CollisionComponent>(witt, ecsManager->getComponentFromEntity<TextComponent>(witt).surfaceSize);
}

void FirstLevel::createTree() {
    auto tree = ecsManager->createEntity();
    ecsManager->addComponentToEntity<TextComponent>(tree, TextGenerator::getTreeText());
    ecsManager->addComponentToEntity<PositionComponent>(tree, startingPosition + Position(100, 200));
    ecsManager->addComponentToEntity<StyleComponent>(tree);
    ecsManager->addComponentToEntity<CollisionComponent>(tree, ecsManager->getComponentFromEntity<TextComponent>(tree).surfaceSize);
}

void FirstLevel::createAxe() {
    auto axe = ecsManager->createEntity();
    ecsManager->addComponentToEntity<TextComponent>(axe, "exAxe\n  x\n  e");
    ecsManager->addComponentToEntity<PositionComponent>(axe, startingPosition + Position(-200, 200));
    ecsManager->addComponentToEntity<StyleComponent>(axe);
    ecsManager->addComponentToEntity<CollisionComponent>(axe, ecsManager->getComponentFromEntity<TextComponent>(axe).surfaceSize);
}


