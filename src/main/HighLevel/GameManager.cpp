#pragma clang diagnostic push
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"
#include "GameManager.h"
#include "../Levels/FirstLevel.h"
#include "../PositionsAndMovement/AutonomousMovementSystem.h"
#include "../PositionsAndMovement/CollisionCheckSystem.h"
#include "../TextCommands/TextCommandSystem.h"
#include "../Rendering/UIRenderSystem.h"
#include "../Rendering/SDLRenderer.h"

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
    ecsManager->addSystem<WordComprehensionSystem>();
    ecsManager->addSystem<UIRenderSystem>(renderer);
    ecsManager->addSystem<TextCommandSystem>();
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