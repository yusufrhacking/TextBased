#include <catch2/catch_test_macros.hpp>
#include <memory>
#include "../../../main/ECS/Design/Managers/ECSManager.h"
#include "../../../main/ECS/Systems/EventCreationSystems/CollisionCheckSystem.h"

extern std::unique_ptr<ECSManager> ecsManager;
TEST_CASE("Collision System", "[System][Collision]") {
    ecsManager = std::make_unique<ECSManager>();

    ecsManager->addSystem<CollisionCheckSystem>();
    Entity entity = ecsManager->createEntity();
    ecsManager->addComponentToEntity<PositionComponent>(entity, std::make_shared<Position>(0, 0));
    ecsManager->addComponentToEntity<TextComponent>(entity, "text");
    Size size = ecsManager->getComponentFromEntity<TextComponent>(entity).surfaceSize;
    ecsManager->addComponentToEntity<ColliderComponent>(entity, size);

    SECTION("Adding and Removing Components") {
        SECTION("Test if in Collision System") {
            auto system = ecsManager->getSystem<CollisionCheckSystem>();
            REQUIRE(system.getRelevantEntities().contains(entity));
        }
        SECTION("Test Removing PositionComponent removes entity from Collision System") {
            ecsManager->removeComponentFromEntity<PositionComponent>(entity);
            auto system = ecsManager->getSystem<CollisionCheckSystem>();
            REQUIRE(!system.getRelevantEntities().contains(entity));
        }
        SECTION("Test Removing TextComponent removes entity from Collision System") {
            ecsManager->removeComponentFromEntity<TextComponent>(entity);
            auto system = ecsManager->getSystem<CollisionCheckSystem>();
            REQUIRE(!system.getRelevantEntities().contains(entity));
        }
        SECTION("Test removing Collider removes entity from Collision System") {
            ecsManager->removeComponentFromEntity<ColliderComponent>(entity);
            auto system = ecsManager->getSystem<CollisionCheckSystem>();
            REQUIRE(!system.getRelevantEntities().contains(entity));
        }
    }
}
