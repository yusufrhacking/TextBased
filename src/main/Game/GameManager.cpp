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

void GameManager::setup() {
    setupSystems();
    BasicSetup level1{};
    level1.setup();
}

void GameManager::setupSystems() const {
    ecsManager->addSystem<AutonomousMovementSystem>();
    ecsManager->addSystem<RenderSystem>();
    ecsManager->addSystem<CollisionCheckSystem>();
    ecsManager->addSystem<CollisionHandleSystem>();
    ecsManager->addSystem<PlayerKeyboardInputSystem>();
    ecsManager->addSystem<CameraFollowSystem>();
    ecsManager->addSystem<UnprocessedKeyboardMovementSystem>();
    Canon canon{Game::startingTopLeftPosition};
    ecsManager->addSystem<CanonSystem>(canon);
}

#pragma clang diagnostic pop