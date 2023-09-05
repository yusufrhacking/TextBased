#pragma clang diagnostic push
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"
#include "GameManager.h"
#include "../Positioning/AutonomousMovementSystem.h"
#include "../Art/TextGenerator.h"
#include "../Positioning/CollisionComponent.h"
#include "../Game/Levels/FirstLevel.h"
#include "../PositionsAndMovement/CollisionHandleSystem.h"
#include "../MainPlayer/PlayerKeyboardInputSystem.h"
#include "../Camera/CameraFollowSystem.h"
#include "../MainPlayer/UnprocessedKeyboardMovementSystem.h"
#include "Game.h"
#include "../TheCanon/CanonRegisteringSystem.h"
#include "../MainPlayer/MovementHandleSystem.h"
#include "../TheCanon/CanonMovementHandleSystem.h"
#include "../TextInput/WordComprehensionSystem.h"

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
    ecsManager->addSystem<CanonRegisteringSystem>(canon);
    ecsManager->addSystem<MovementHandleSystem>();
    ecsManager->addSystem<CanonMovementHandleSystem>(canon);
    ecsManager->addSystem<WordComprehensionSystem>();
}

void GameManager::update(double deltaTime) {
    auto recentlyAddedEntities = ecsManager->addNewEntities();
    ecsManager->getSystem<CanonRegisteringSystem>().placeEntities(recentlyAddedEntities);
    ecsManager->removeDeadEntities();
    ecsManager->runFirstSystems();
    ecsManager->runTimedSystems(deltaTime);
    ecsManager->runCameraSystem();
}

#pragma clang diagnostic pop