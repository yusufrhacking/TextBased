#include "BasicSetup.h"
#include "../GameManager.h"
#include "../../ECS/Components/MainPlayerComponent.h"
#include "../../ECS/Components/TextComponents/TreeComponent.h"
#include "../Game.h"
#include "Forest/ForestFrame.h"
#include "../GameSystems/Camera/Camera.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<Camera> camera;

void BasicSetup::setup() {
    createPlayer();
}

void BasicSetup::createPlayer() {
    witt = ecsManager->createEntity();
    ecsManager->addComponentToEntity<TextComponent>(witt, "Witt");
    auto startingPosition = Game::startingTopLeftPosition + window->getMiddlePosition();
    ecsManager->addComponentToEntity<PositionComponent>(witt, Game::startingTopLeftPosition + window->getMiddlePosition());
    ecsManager->addComponentToEntity<MainPlayerComponent>(witt, std::make_shared<Velocity>(15, 15));
    ecsManager->addComponentToEntity<StyleComponent>(witt);
    ecsManager->addComponentToEntity<CollisionComponent>(witt, ecsManager->getComponentFromEntity<TextComponent>(witt).surfaceSize);
}


