#pragma clang diagnostic push
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"
#include "GameManager.h"
#include "../ECS/Systems/UpdateSystems/AutonomousMovementSystem.h"
#include "TextGenerator.h"
#include "../ECS/Components/CollisionComponent.h"
#include "Levels/BasicSetup.h"
#include "../ECS/Systems/EventHandlerSystems/CollisionHandleSystem.h"
#include "../ECS/Systems/EventHandlerSystems/PlayerKeyboardInputSystem.h"
#include "../ECS/Systems/SpecialSystems/CameraFollowSystem.h"
#include "../ECS/Systems/SpecialSystems/UnprocessedMovements/UnprocessedKeyboardMovementSystem.h"
#include "Game.h"
#include "../ECS/Systems/SpecialSystems/CanonSystem.h"

GameManager::GameManager(Position position): canon(position) {

}

void GameManager::setup() {
    setupSystems();
    BasicSetup level1{};
    level1.setup();
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