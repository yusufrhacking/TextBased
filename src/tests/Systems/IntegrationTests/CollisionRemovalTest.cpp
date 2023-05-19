#include <catch2/catch_test_macros.hpp>
#include <sys/stat.h>
#include "../../../main/Globals.h"
#include "../../../main/ECS/Design/Managers/ECSManager.h"
#include "../../../main/ECS/Systems/EventHandlerSystems/AutonomousMovementSystem.h"
#include "../../../main/ECS/Systems/EventCreationSystems/CollisionCheckSystem.h"
#include "../../../main/ECS/Systems/EventHandlerSystems/CollisionHandleSystem.h"

const int X_POINT_OF_COLLISION = 20;
const int Y_POINT_OF_COLLISION = 20;
const int DELTA_TIME = 1;

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;


static void addComponentsToEntities(Entity staticEntity, Entity movingEntity){
    ecsManager->addComponentToEntity<PositionComponent>(
            staticEntity, std::make_shared<Position>(X_POINT_OF_COLLISION, Y_POINT_OF_COLLISION));
    ecsManager->addComponentToEntity<TextComponent>(staticEntity, "Static Entity");
    Size staticEntitySize = ecsManager->getComponentFromEntity<TextComponent>(staticEntity).surfaceSize;
    ecsManager->addComponentToEntity<CollisionComponent>(staticEntity, staticEntitySize);

    ecsManager->addComponentToEntity<PositionComponent>(movingEntity, std::make_shared<Position>(0, 0));
    ecsManager->addComponentToEntity<TextComponent>(movingEntity, "Moving Entity");
    Size movingEntitySize = ecsManager->getComponentFromEntity<TextComponent>(movingEntity).surfaceSize;
    ecsManager->addComponentToEntity<CollisionComponent>(movingEntity, movingEntitySize);
    ecsManager->addComponentToEntity<MovementComponent>(
            movingEntity, std::make_shared<Velocity>(X_POINT_OF_COLLISION*DELTA_TIME, Y_POINT_OF_COLLISION*DELTA_TIME));
}

TEST_CASE("Removes Both Entities When One Moves Into the Other", "[CollisionRemoval]") {
    ecsManager = std::make_unique<ECSManager>();
    eventBus = std::make_unique<EventBus>();
    ecsManager->addSystem<AutonomousMovementSystem>();
    ecsManager->addSystem<CollisionCheckSystem>();

    ecsManager->addSystem<CollisionHandleSystem>();
    ecsManager->getSystem<CollisionHandleSystem>().listenToEvents();

    Entity staticEntity = ecsManager->createEntity();
    Entity movingEntity = ecsManager->createEntity();

    addComponentsToEntities(staticEntity, movingEntity);

    auto& collisionSystem = ecsManager->getSystem<CollisionCheckSystem>();
    auto& movementSystem = ecsManager->getSystem<AutonomousMovementSystem>();
    auto& collisionHandleSystem = ecsManager->getSystem<CollisionHandleSystem>();

    REQUIRE(collisionSystem.getRelevantEntities().contains(staticEntity));
    REQUIRE(collisionSystem.getRelevantEntities().contains(movingEntity));
    REQUIRE(movementSystem.getRelevantEntities().contains(movingEntity));
    REQUIRE(collisionHandleSystem.getRelevantEntities().contains(movingEntity));

    ecsManager->update(DELTA_TIME);
    ecsManager->update(DELTA_TIME);
    ecsManager->update(DELTA_TIME);//Required to flush out entitiesToBeKilled() --> this is why this should realistically be a mocked version of the ECS manager

    REQUIRE(!collisionSystem.getRelevantEntities().contains(staticEntity));
    REQUIRE(!collisionSystem.getRelevantEntities().contains(movingEntity));
    REQUIRE(!movementSystem.getRelevantEntities().contains(movingEntity));
    REQUIRE_THROWS(ecsManager->removeComponentFromEntity<PositionComponent>(staticEntity));
    REQUIRE_THROWS(ecsManager->removeComponentFromEntity<MovementComponent>(movingEntity));
    REQUIRE_THROWS(ecsManager->getComponentFromEntity<TextComponent>(staticEntity));
    REQUIRE_THROWS(ecsManager->getComponentFromEntity<TextComponent>(movingEntity));
}