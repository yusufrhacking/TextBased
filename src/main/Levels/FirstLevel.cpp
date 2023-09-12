#include "FirstLevel.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../PositionsAndMovement/CollisionComponent.h"
#include "../MainPlayer/TiedChildComponent.h"
#include "../Woodworking/AxeComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;

FirstLevel::FirstLevel(Position startingPosition): startingPosition(startingPosition) {
    witt = ecsManager->createEntity();
    axe = ecsManager->createEntity();
    createTree();
    createAxe();
    createPlayer();
}

void FirstLevel::createPlayer() {
    ecsManager->addComponentToEntity<TextComponent>(witt, "Witt");
    ecsManager->addComponentToEntity<PositionComponent>(witt, startingPosition);
    ecsManager->addComponentToEntity<MainPlayerComponent>(witt, std::make_shared<Velocity>(15, 15));
    ecsManager->addComponentToEntity<StyleComponent>(witt);
    ecsManager->addComponentToEntity<CollisionComponent>(witt, "Witt");
    ecsManager->addComponentToEntity<TiedChildComponent>(witt, axe);
}

void FirstLevel::createTree() {
    auto tree = ecsManager->createEntity();
    ecsManager->addComponentToEntity<TextComponent>(tree, TextGenerator::getTreeText());
    ecsManager->addComponentToEntity<PositionComponent>(tree, startingPosition + Position(100, 200));
    ecsManager->addComponentToEntity<StyleComponent>(tree);
    ecsManager->addComponentToEntity<CollisionComponent>(tree, ecsManager->getComponentFromEntity<TextComponent>(tree).surfaceSize);
    ecsManager->addComponentToEntity<TreeComponent>(tree);
}

void FirstLevel::createAxe() {
    ecsManager->addComponentToEntity<TextComponent>(axe, "exAxe\n  x\n  e");
    ecsManager->addComponentToEntity<PositionComponent>(axe, startingPosition + Position(15, -45));
    ecsManager->addComponentToEntity<StyleComponent>(axe);
    ecsManager->addComponentToEntity<AxeComponent>(axe);
}


