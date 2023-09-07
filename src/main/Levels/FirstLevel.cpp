#include "FirstLevel.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../PositionsAndMovement/CollisionComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;

FirstLevel::FirstLevel(Position startingPosition): startingPosition(startingPosition) {
    createPlayer();
    createTree(startingPosition);
    createWelcomeText();
}

void FirstLevel::createPlayer() {
    witt = ecsManager->createEntity();
    ecsManager->addComponentToEntity<TextComponent>(witt, "Witt");
    ecsManager->addComponentToEntity<PositionComponent>(witt, startingPosition);
    ecsManager->addComponentToEntity<MainPlayerComponent>(witt, std::make_shared<Velocity>(15, 15));
    ecsManager->addComponentToEntity<StyleComponent>(witt);
    ecsManager->addComponentToEntity<CollisionComponent>(witt, ecsManager->getComponentFromEntity<TextComponent>(witt).surfaceSize);
}

void FirstLevel::createTree(Position position) {
    auto tree = ecsManager->createEntity();
    ecsManager->addComponentToEntity<TextComponent>(tree, TextGenerator::getTreeText());
    ecsManager->addComponentToEntity<PositionComponent>(tree, position);
    ecsManager->addComponentToEntity<StyleComponent>(tree);
    auto component = ecsManager->getComponentFromEntity<TextComponent>(tree);
    ecsManager->addComponentToEntity<CollisionComponent>(tree, component.surfaceSize);  //THIS IS A WIP
}

void FirstLevel::createWelcomeText() {
    auto text = ecsManager->createEntity();
    Position position {-750, 0};
    ecsManager->addComponentToEntity<TextComponent>(text, TextGenerator::getWelcomeText());
    ecsManager->addComponentToEntity<PositionComponent>(text, startingPosition + position);
    ecsManager->addComponentToEntity<StyleComponent>(text);
}


