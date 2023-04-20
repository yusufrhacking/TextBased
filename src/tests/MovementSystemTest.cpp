#include <catch2/catch_test_macros.hpp>
#include "../main/ECS/Design/Managers/ECSManager.h"
#include "../main/ECS/Systems/MovementSystem.h"

TEST_CASE("Movement System testing"){
    std::unique_ptr<ECSManager> manager = std::make_unique<ECSManager>();
    manager->addSystem<MovementSystem>();
    Entity movedEntity = manager->createEntity();
    manager->addComponentToEntity<PositionComponent>(movedEntity, std::make_shared<Position>(0, 0));
    manager->addComponentToEntity<MovementComponent>(movedEntity, std::make_shared<Velocity>(0, 0));

    SECTION("Test if in Movement System"){
        MovementSystem system = manager->getSystem<MovementSystem>();
        REQUIRE(system.getReleventEntities().contains(movedEntity));
    }
    SECTION("Test removed from Movement System"){

    }
    SECTION("Test if now moves with new velocity"){

    }
}