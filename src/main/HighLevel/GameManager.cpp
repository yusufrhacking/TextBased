#pragma clang diagnostic push
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"
#include "GameManager.h"

#include "SystemAddSystem.h"
#include "../Levels/BasicLevel.h"
#include "../PositionsAndMovement/VelocitySystem.h"
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
#include "../Abyz/AbyzControlSystem.h"
#include "../Abyz/AbyzPlatformCollisionHandleSystem.h"
#include "../Abyz/AbyzTargetExecutionSystem.h"
#include "../Abyz/AbyzTargetAllocationSystem.h"
#include "../Abyz/LifeGateComponent.h"
#include "../Abyz/LifeGateSystem.h"
#include "../Abyz/WordRelicPrioritizingSystem.h"
#include "../Levels/FullBasicLevel.h"
#include "../Levels/IntroPac.h"
#include "../MainPlayer/PlayerRotateSystem.h"
#include "../Maze/IntroMazePrefab.h"
#include "../UIShow/UIControllerSystem.h"
#include "../Woodworking/AxeFlipSystem.h"
#include "../Middlemarch/MiddlemarchStart.h"
#include "../Gravity/GravitySystem.h"
#include "../Gravity/JumpingSystem.h"
#include "../MainPlayer/DamageSystem.h"
#include "../Platformer/HorizontalPlatformMovementSystem.h"
#include "../Platformer/PlatformLandingSystem.h"
#include "../PositionsAndMovement/RandomRightLeftMovementSystem.h"
#include "../PositionsAndMovement/RightLeftMovementSystem.h"
#include "../Spawning/SpawnAbyzSystem.h"
#include "../Emma/EmmaStart.h"
#include "../Diegesis/CoinBoxCollisionSystem.h"
#include "../Tractatus/TractatusStart.h"

GameManager::GameManager(Position position): canon(position), startingPosition(position) {
    window = std::make_unique<Window>();
    renderer = std::make_shared<SDLRenderer>((window->getWindow()));
}

void GameManager::setup() {
    setupSystems();
    FullBasicLevel levelJit{startingPosition + Window::getMiddlePosition()};
    //TractatusStart level1{startingPosition + Window::getMiddlePosition()};
}

void GameManager::setupSystems() {
    ecsManager->addSystem<RenderControllerSystem>();
    ecsManager->addSystem<VelocitySystem>();
    // ecsManager->addSystem<CollisionCheckSystem>();
    ecsManager->addSystem<CollisionHandleSystem>();
    ecsManager->addSystem<PlayerKeyboardInputSystem>();
    ecsManager->addSystem<CameraFollowSystem>();
    ecsManager->addSystem<MovementSystem>();
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
    ecsManager->addSystem<AbyzControlSystem>();
    ecsManager->addSystem<PlayerRotateSystem>();
    ecsManager->addSystem<UIControllerSystem>();
    ecsManager->addSystem<AxeFlipSystem>();
    ecsManager->addSystem<SystemAddSystem>();
    ecsManager->addSystem<AbyzTargetAllocationSystem>();
    ecsManager->addSystem<AbyzTargetExecutionSystem>();
    ecsManager->addSystem<WordRelicPrioritizingSystem>();
    ecsManager->addSystem<GravitySystem>();
    ecsManager->addSystem<RightLeftMovementSystem>();
    ecsManager->addSystem<SpawnAbyzSystem>();
    ecsManager->addSystem<LifeGateSystem>();
    ecsManager->addSystem<RandomRightLeftMovementSystem>();
    ecsManager->addSystem<PlatformLandingSystem>();
    ecsManager->addSystem<HorizontalPlatformMovementSystem>();
    ecsManager->addSystem<AbyzPlatformCollisionHandleSystem>();
    ecsManager->addSystem<DamageSystem>();
    ecsManager->addSystem<CoinBoxCollisionSystem>();
}

void GameManager::update(double deltaTime) {
    auto recentlyAddedEntities = ecsManager->addNewEntities();
    ecsManager->getSystem<CanonRegisteringSystem>().placeEntities(recentlyAddedEntities);
    ecsManager->removeDeadEntities();
    // ecsManager->runFirstSystems();
    ecsManager->runTimedSystems(deltaTime);
    ecsManager->runCameraSystem();
}

void GameManager::render() {
    ecsManager->render(renderer);
}

#pragma clang diagnostic pop