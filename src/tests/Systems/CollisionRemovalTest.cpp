#include <catch2/catch_test_macros.hpp>
#include <sys/stat.h>
#include "../../main/Globals.h"
#include "../../main/ECS/Design/Managers/ECSManager.h"
#include "../../main/ECS/Systems/MovementSystem.h"
#include "../../main/ECS/Systems/CollisionSystem.h"


extern std::unique_ptr<ECSManager> ecsManager;

TEST_CASE("Removes Both Entities When One Moves Into the Other", "[CollisionRemoval]") {
    ecsManager = std::make_unique<ECSManager>();
    ecsManager->addSystem<MovementSystem>();
    ecsManager->addSystem<CollisionSystem>();

    Entity staticEntity = ecsManager->createEntity();
    Entity movingEntity = ecsManager->createEntity();

    ecsManager->addComponentToEntity<PositionComponent>(staticEntity, std::make_shared<Position>(0, 0));
    ecsManager->addComponentToEntity<TextComponent>(staticEntity, "Static Entity");
    Size staticEntitySize = ecsManager->getComponentFromEntity<TextComponent>(staticEntity).surfaceSize;
    ecsManager->addComponentToEntity<ColliderComponent>(staticEntity, staticEntitySize);

    ecsManager->addComponentToEntity<PositionComponent>(movingEntity, std::make_shared<Position>(0, 0));
    ecsManager->addComponentToEntity<TextComponent>(movingEntity, "Moving Entity");
    Size movingEntitySize = ecsManager->getComponentFromEntity<TextComponent>(movingEntity).surfaceSize;
    ecsManager->addComponentToEntity<ColliderComponent>(movingEntity,movingEntitySize);

}