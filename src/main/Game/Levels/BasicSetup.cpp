#include "BasicSetup.h"
#include "../GameManager.h"
#include "../../ECS/Components/MainPlayerComponent.h"
#include "../../ECS/Components/TextComponents/TreeComponent.h"
#include "../Game.h"
#include "ForestScene.h"
extern std::unique_ptr<ECSManager> ecsManager;

void BasicSetup::setup() {
    createPlayer();
    ForestScene(Position(1000, 1000));
}

void BasicSetup::createPlayer() {
    Entity witt = ecsManager->createEntity();
    ecsManager->addComponentToEntity<TextComponent>(witt, "Witt");
    ecsManager->addComponentToEntity<PositionComponent>(witt, Game::startingPosition+window->getMiddlePosition());
    ecsManager->addComponentToEntity<MainPlayerComponent>(witt, std::make_shared<Velocity>(5, 5));
    ecsManager->addComponentToEntity<StyleComponent>(witt);
    ecsManager->addComponentToEntity<CollisionComponent>(witt, ecsManager->getComponentFromEntity<TextComponent>(witt).surfaceSize);
}


