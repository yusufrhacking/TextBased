#include <catch2/catch_test_macros.hpp>
#include "../main/ECS/Design/Managers/ECSManager.h"
#include "../main/ECS/Systems/MovementSystem.h"

TEST_CASE("Movement System Testing"){
    std::unique_ptr<ECSManager> manager = std::make_unique<ECSManager>();
    manager->addSystem<MovementSystem>();
    Entity movedEntity = manager->createEntity();
    manager->addComponentToEntity<PositionComponent>(movedEntity, std::make_shared<Position>(0, 0));
    manager->addComponentToEntity<MovementComponent>(movedEntity, std::make_shared<Velocity>(20, 20));

    SECTION("Test if in Movement System"){
        MovementSystem system = manager->getSystem<MovementSystem>();
        REQUIRE(system.getReleventEntities().contains(movedEntity));
    }
    SECTION("Test Removing MovementComponent removes entity from Movement System"){
        manager->removeComponentFromEntity<MovementComponent>(movedEntity);
        MovementSystem system = manager->getSystem<MovementSystem>();
        REQUIRE(!system.getReleventEntities().contains(movedEntity));

    }
    SECTION("Test Removing PositionComponent removes entity from Movement System"){
        manager->removeComponentFromEntity<PositionComponent>(movedEntity);
        MovementSystem system = manager->getSystem<MovementSystem>();
        REQUIRE(!system.getReleventEntities().contains(movedEntity));
    }
    SECTION("Test if now moves with new velocity"){
        manager->update(50);
//        auto positionComponent = manager->getComponentFromEntity<PositionComponent>(movedEntity);
//        auto position = positionComponent.position;
//        REQUIRE(position->xPos != 0);
//        REQUIRE(position->yPos != 0);
    }
}