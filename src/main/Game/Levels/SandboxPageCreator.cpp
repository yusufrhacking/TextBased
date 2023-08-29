#include "SandboxPageCreator.h"
#include "../GameManager.h"
#include "../../ECS/Components/MainPlayerComponent.h"
#include "../../ECS/Components/TextComponents/TreeComponent.h"
#include "../Game.h"
#include "../GameSystems/Camera/Camera.h"

extern std::unique_ptr<ECSManager> ecsManager;

SandboxPageCreator::SandboxPageCreator(Position startingPosition): startingPosition(startingPosition) {
    createPlayer();
    createTree();
}

void SandboxPageCreator::createPlayer() {
    witt = ecsManager->createEntity();
    ecsManager->addComponentToEntity<TextComponent>(witt, "Witt");
    ecsManager->addComponentToEntity<PositionComponent>(witt, startingPosition);
    ecsManager->addComponentToEntity<MainPlayerComponent>(witt, std::make_shared<Velocity>(15, 15));
    ecsManager->addComponentToEntity<StyleComponent>(witt);
    ecsManager->addComponentToEntity<CollisionComponent>(witt, ecsManager->getComponentFromEntity<TextComponent>(witt).surfaceSize);
}

void SandboxPageCreator::createTree() {
    auto tree = ecsManager->createEntity();
    ecsManager->addComponentToEntity<TextComponent>(tree, TextGenerator::getTreeText());
    ecsManager->addComponentToEntity<PositionComponent>(tree, Game::startingTopLeftPosition);
    ecsManager->addComponentToEntity<StyleComponent>(tree);
}


