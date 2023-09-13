#pragma clang diagnostic push
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"
#include "GameManager.h"
#include "../Levels/FirstLevel.h"
#include "../PositionsAndMovement/AutonomousMovementSystem.h"
#include "../PositionsAndMovement/CollisionCheckSystem.h"
#include "../TextCommands/TextCommandSystem.h"
#include "../Rendering/SDLRenderer.h"
#include "../Woodworking/ChoppingSystem.h"
#include "../Creation/ItemCreationSystem.h"
#include "../MainPlayer/MainPlayerAccessSystem.h"
#include "../Inventory/PlayerPickUpSystem.h"

GameManager::GameManager(Position position): canon(position), startingPosition(position) {
    window = std::make_unique<Window>();
    renderer = std::make_shared<SDLRenderer>((window->getWindow()));
}

void GameManager::setup() {
    setupSystems();
    FirstLevel level1{startingPosition + Window::getMiddlePosition()};
}

void GameManager::setupSystems() {
    ecsManager->addSystem<AutonomousMovementSystem>();
    ecsManager->addSystem<EntityRenderSystem>();
    ecsManager->addSystem<CollisionCheckSystem>();
    ecsManager->addSystem<CollisionHandleSystem>();
    ecsManager->addSystem<PlayerKeyboardInputSystem>();
    ecsManager->addSystem<CameraFollowSystem>();
    ecsManager->addSystem<UnprocessedKeyboardMovementSystem>();
    ecsManager->addSystem<CanonRegisteringSystem>(canon);
    ecsManager->addSystem<MovementHandleSystem>();
    ecsManager->addSystem<CanonMovementHandleSystem>(canon);
    ecsManager->addSystem<WordInputSystem>();
    ecsManager->addSystem<TextCommandSystem>();
    ecsManager->addSystem<ChoppingSystem>();
    ecsManager->addSystem<ItemCreationSystem>();
    ecsManager->addSystem<MainPlayerAccessSystem>();
    ecsManager->addSystem<PlayerPickUpSystem>();
}

void GameManager::update(double deltaTime) {
    auto recentlyAddedEntities = ecsManager->addNewEntities();
    ecsManager->getSystem<CanonRegisteringSystem>().placeEntities(recentlyAddedEntities);
    ecsManager->removeDeadEntities();
    ecsManager->runFirstSystems();
    ecsManager->runTimedSystems(deltaTime);
    ecsManager->runCameraSystem();
}

void GameManager::render() {
    ecsManager->render(renderer);
}

#pragma clang diagnostic pop