#pragma clang diagnostic push
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"
#include "GameManager.h"
#include "../ECS/Systems/UpdateSystems/AutonomousMovementSystem.h"
#include "TextGenerator.h"
#include "../ECS/Components/CollisionComponent.h"
#include "Levels/FirstLevel.h"
#include "../ECS/Systems/EventHandlerSystems/CollisionHandleSystem.h"
#include "../ECS/Systems/EventHandlerSystems/PlayerKeyboardInputSystem.h"
#include "../ECS/Systems/SpecialSystems/CameraFollowSystem.h"
#include "../ECS/Systems/SpecialSystems/UnprocessedMovements/UnprocessedKeyboardMovementSystem.h"
#include "Game.h"
#include "../ECS/Systems/SpecialSystems/CanonSystem.h"
#include "../ECS/Systems/EventHandlerSystems/MovementHandleSystem.h"
#include "../ECS/Systems/EventHandlerSystems/CanonMovementHandleSystem.h"

GameManager::GameManager(Position position): canon(position) {
}

void GameManager::setup() {
    setupSystems();
    FirstLevel level1{Game::startingTopLeftPosition + Window::getMiddlePosition()};
}

void GameManager::setupSystems() {
    ecsManager->addSystem<AutonomousMovementSystem>();
    ecsManager->addSystem<RenderSystem>();
    ecsManager->addSystem<CollisionCheckSystem>();
    ecsManager->addSystem<CollisionHandleSystem>();
    ecsManager->addSystem<PlayerKeyboardInputSystem>();
    ecsManager->addSystem<CameraFollowSystem>();
    ecsManager->addSystem<UnprocessedKeyboardMovementSystem>();
    ecsManager->addSystem<CanonSystem>(canon);
    ecsManager->addSystem<MovementHandleSystem>();
    ecsManager->addSystem<CanonMovementHandleSystem>(canon);
}

void GameManager::update(double deltaTime) {
    auto recentlyAddedEntities = ecsManager->addNewEntities();
    ecsManager->getSystem<CanonSystem>().placeEntities(recentlyAddedEntities);
    ecsManager->removeDeadEntities();
    ecsManager->runFirstSystems();
    ecsManager->runTimedSystems(deltaTime);
    ecsManager->runCameraSystem();
}

#pragma clang diagnostic pop