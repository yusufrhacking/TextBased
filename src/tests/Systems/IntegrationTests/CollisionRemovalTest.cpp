#include <catch2/catch_test_macros.hpp>
#include <sys/stat.h>
#include "../../../main/Globals.h"
#include "../../../main/ECS/Design/Managers/ECSManager.h"
#include "../../../main/ECS/Systems/MovementSystem.h"
#include "../../../main/ECS/Systems/CollisionSystem.h"

const int X_POINT_OF_COLLISION = 20;
const int Y_POINT_OF_COLLISION = 20;
const int DELTA_TIME = 1;

extern std::unique_ptr<ECSManager> ecsManager;

static void addComponentsToEntities(Entity staticEntity, Entity movingEntity){
    ecsManager->addComponentToEntity<PositionComponent>(
            staticEntity, std::make_shared<Position>(X_POINT_OF_COLLISION, Y_POINT_OF_COLLISION));
    ecsManager->addComponentToEntity<TextComponent>(staticEntity, "Static Entity");
    Size staticEntitySize = ecsManager->getComponentFromEntity<TextComponent>(staticEntity).surfaceSize;
    ecsManager->addComponentToEntity<ColliderComponent>(staticEntity, staticEntitySize);

    ecsManager->addComponentToEntity<PositionComponent>(movingEntity, std::make_shared<Position>(0, 0));
    ecsManager->addComponentToEntity<TextComponent>(movingEntity, "Moving Entity");
    Size movingEntitySize = ecsManager->getComponentFromEntity<TextComponent>(movingEntity).surfaceSize;
    ecsManager->addComponentToEntity<ColliderComponent>(movingEntity,movingEntitySize);
    ecsManager->addComponentToEntity<MovementComponent>(
            movingEntity, std::make_shared<Velocity>(X_POINT_OF_COLLISION*DELTA_TIME, Y_POINT_OF_COLLISION*DELTA_TIME));
}

TEST_CASE("Removes Both Entities When One Moves Into the Other", "[CollisionRemoval]") {
    ecsManager = std::make_unique<ECSManager>();
    ecsManager->addSystem<MovementSystem>();
    ecsManager->addSystem<CollisionSystem>();

    Entity staticEntity = ecsManager->createEntity();
    Entity movingEntity = ecsManager->createEntity();

    addComponentsToEntities(staticEntity, movingEntity);

    auto& collisionSystem = ecsManager->getSystem<CollisionSystem>();
    auto& movementSystem = ecsManager->getSystem<MovementSystem>();

    REQUIRE(collisionSystem.getRelevantEntities().contains(staticEntity));
    REQUIRE(collisionSystem.getRelevantEntities().contains(movingEntity));
    REQUIRE(movementSystem.getRelevantEntities().contains(movingEntity));

    movementSystem.update(DELTA_TIME);
    collisionSystem.update(DELTA_TIME);
    ecsManager->update(DELTA_TIME);//Required to flush out entitiesToBeKilled() --> this is why this should realistically be a mocked version of the ECS manager

    REQUIRE(!collisionSystem.getRelevantEntities().contains(staticEntity));
    REQUIRE(!collisionSystem.getRelevantEntities().contains(movingEntity));
    REQUIRE(!movementSystem.getRelevantEntities().contains(movingEntity));
    REQUIRE_THROWS(ecsManager->removeComponentFromEntity<PositionComponent>(staticEntity));
    REQUIRE_THROWS(ecsManager->removeComponentFromEntity<MovementComponent>(movingEntity));
    REQUIRE_THROWS(ecsManager->getComponentFromEntity<TextComponent>(staticEntity));
    REQUIRE_THROWS(ecsManager->getComponentFromEntity<TextComponent>(movingEntity));
}