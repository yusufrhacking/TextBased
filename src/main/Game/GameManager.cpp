#pragma clang diagnostic push
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"
#include "GameManager.h"
#include "../ECS/Systems/UpdateSystems/AutonomousMovementSystem.h"
#include "TextGenerator.h"
#include "../ECS/Components/CollisionComponent.h"
#include "Levels/Level1.h"
#include "../ECS/Systems/EventHandlerSystems/CollisionHandleSystem.h"
#include "../ECS/Systems/EventHandlerSystems/PlayerMovementSystem.h"
#include "../ECS/Systems/UpdateSystems/CameraFollowSystem.h"

void GameManager::setup() {
    setupSystems();
    Level1 level1;
    level1.setup();
}

void GameManager::setupSystems() const {
    ecsManager->addSystem<AutonomousMovementSystem>();
    ecsManager->addSystem<RenderSystem>();
    ecsManager->addSystem<CollisionCheckSystem>();
    ecsManager->addSystem<CollisionHandleSystem>();
    ecsManager->addSystem<PlayerMovementSystem>();
    ecsManager->addSystem<CameraFollowSystem>();
}

#pragma clang diagnostic pop