#include <catch2/catch_test_macros.hpp>
#include "../main/ECS/Design/Managers/ECSManager.h"
#include "../main/ECS/Systems/MovementSystem.h"

TEST_CASE("Movement System Testing", "[UpdateSystem]"){
    std::unique_ptr<ECSManager> ecsManager = std::make_unique<ECSManager>();
    ecsManager->addSystem<MovementSystem>();
    Entity movedEntity = ecsManager->createEntity();
    ecsManager->addComponentToEntity<PositionComponent>(movedEntity, std::make_shared<Position>(0, 0));
    ecsManager->addComponentToEntity<MovementComponent>(movedEntity, std::make_shared<Velocity>(20, 20));

    SECTION("Test if in Movement System"){
        MovementSystem system = ecsManager->getSystem<MovementSystem>();
        REQUIRE(system.getRelevantEntities().contains(movedEntity));
    }
    SECTION("Test Removing MovementComponent removes entity from Movement System"){
        ecsManager->removeComponentFromEntity<MovementComponent>(movedEntity);
        MovementSystem system = ecsManager->getSystem<MovementSystem>();
        REQUIRE(!system.getRelevantEntities().contains(movedEntity));

    }
    SECTION("Test Removing PositionComponent removes entity from Movement System"){
        ecsManager->removeComponentFromEntity<PositionComponent>(movedEntity);
        MovementSystem system = ecsManager->getSystem<MovementSystem>();
        REQUIRE(!system.getRelevantEntities().contains(movedEntity));
    }
}
