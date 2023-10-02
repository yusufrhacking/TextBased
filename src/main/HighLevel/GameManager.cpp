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
#include "../Inventory/InventorySystem.h"
#include "../Inventory/PlaceSystem.h"
#include "../Lettering/CharacterStorageSystem.h"
#include "../Grammar/GrammarSystem.h"
#include "../Lettering/LetterPickupSystem.h"
#include "../TerminalUI/LiveTerminalRenderSystem.h"
#include "../TextCommands/CommandLogSystem.h"
#include "../TerminalUI/TerminalHistoryRenderSystem.h"
#include "../Diegesis/EngineerDialogueSystem.h"
#include "../Lettering/LetterBankRenderSystem.h"
#include "../Rendering/RenderControllerSystem.h"
#include "../Lettering/FreeWordSystem.h"
#include "../Attacking/AttackAttemptSystem.h"
#include "../Health/HealthSystem.h"
#include "../Health/PendingDeathSystem.h"

GameManager::GameManager(Position position): canon(position), startingPosition(position) {
    window = std::make_unique<Window>();
    renderer = std::make_shared<SDLRenderer>((window->getWindow()));
}

void GameManager::setup() {
    setupSystems();
    FirstLevel level1{startingPosition + Window::getMiddlePosition()};
}

void GameManager::setupSystems() {
    ecsManager->addSystem<RenderControllerSystem>();
    ecsManager->addSystem<AutonomousMovementSystem>();
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
    ecsManager->addSystem<InventorySystem>();
    ecsManager->addSystem<PlaceSystem>();
    ecsManager->addSystem<GrammarSystem>();
    ecsManager->addSystem<CharacterStorageSystem>();
    ecsManager->addSystem<LetterPickupSystem>();
    ecsManager->addSystem<CommandLogSystem>();
    ecsManager->addSystem<EngineerDialogueSystem>();
    ecsManager->addSystem<FreeWordSystem>();
    ecsManager->addSystem<AttackAttemptSystem>();
    ecsManager->addSystem<HealthSystem>();
    ecsManager->addSystem<PendingDeathSystem>();
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