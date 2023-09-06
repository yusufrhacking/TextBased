#include "FirstLevel.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../PositionsAndMovement/CollisionComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;

FirstLevel::FirstLevel(Position startingPosition): startingPosition(startingPosition) {
    createPlayer();
    createTree();
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

void FirstLevel::createTree() {
    auto tree = ecsManager->createEntity();
    ecsManager->addComponentToEntity<TextComponent>(tree, TextGenerator::getTreeText());
    ecsManager->addComponentToEntity<PositionComponent>(tree, startingPosition);
    ecsManager->addComponentToEntity<StyleComponent>(tree);
}

void FirstLevel::createWelcomeText() {
    auto text = ecsManager->createEntity();
    Position position {Window::windowWidth, 0};
    ecsManager->addComponentToEntity<TextComponent>(text, TextGenerator::getWelcomeText());
    ecsManager->addComponentToEntity<PositionComponent>(text, Game::startingTopLeftPosition + position);
    ecsManager->addComponentToEntity<StyleComponent>(text);
}


