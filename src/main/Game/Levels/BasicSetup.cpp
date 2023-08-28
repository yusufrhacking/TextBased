#include "BasicSetup.h"
#include "../GameManager.h"
#include "../../ECS/Components/MainPlayerComponent.h"
#include "../../ECS/Components/TextComponents/TreeComponent.h"
#include "../Game.h"
#include "../GameSystems/Camera/Camera.h"

extern std::unique_ptr<ECSManager> ecsManager;

void BasicSetup::setup() {
    createPlayer();
    createTree();
}

void BasicSetup::createPlayer() {
    witt = ecsManager->createEntity();
    ecsManager->addComponentToEntity<TextComponent>(witt, "Witt");
    auto startingPosition = Game::startingTopLeftPosition + Window::getMiddlePosition();
    ecsManager->addComponentToEntity<PositionComponent>(witt, Game::startingTopLeftPosition + Window::getMiddlePosition());
    ecsManager->addComponentToEntity<MainPlayerComponent>(witt, std::make_shared<Velocity>(15, 15));
    ecsManager->addComponentToEntity<StyleComponent>(witt);
    ecsManager->addComponentToEntity<CollisionComponent>(witt, ecsManager->getComponentFromEntity<TextComponent>(witt).surfaceSize);
}

void BasicSetup::createTree() {
    auto tree = ecsManager->createEntity();
    ecsManager->addComponentToEntity<TextComponent>(tree, "Tree");
    ecsManager->addComponentToEntity<PositionComponent>(tree, Game::startingTopLeftPosition);
    ecsManager->addComponentToEntity<StyleComponent>(tree);

}


