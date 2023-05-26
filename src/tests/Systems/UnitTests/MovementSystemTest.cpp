#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include <memory>
#include "../../../main/ECS/Design/Managers/ECSManager.h"
#include "../../../main/ECS/Systems/UpdateSystems/AutonomousMovementSystem.h"

extern std::unique_ptr<ECSManager> ecsManager;

TEST_CASE("Movement System Testing", "[System][AutonomousMovementSystem]") {
    ecsManager = std::make_unique<ECSManager>();
    ecsManager->addSystem<AutonomousMovementSystem>();
    Entity movedEntity = ecsManager->createEntity();
    ecsManager->addComponentToEntity<PositionComponent>(movedEntity, std::make_shared<Position>(0, 0));
    ecsManager->addComponentToEntity<MovementComponent>(movedEntity, std::make_shared<Velocity>(20, 20));

    SECTION("Test if in Movement System") {
        AutonomousMovementSystem system = ecsManager->getSystem<AutonomousMovementSystem>();
        REQUIRE(system.getRelevantEntities().contains(movedEntity));
    }SECTION("Test Removing MovementComponent removes entity from Movement System") {
        ecsManager->removeComponentFromEntity<MovementComponent>(movedEntity);
        AutonomousMovementSystem system = ecsManager->getSystem<AutonomousMovementSystem>();
        REQUIRE(!system.getRelevantEntities().contains(movedEntity));

    }SECTION("Test Removing PositionComponent removes entity from Movement System") {
        ecsManager->removeComponentFromEntity<PositionComponent>(movedEntity);
        AutonomousMovementSystem system = ecsManager->getSystem<AutonomousMovementSystem>();
        REQUIRE(!system.getRelevantEntities().contains(movedEntity));
    }
}

using Catch::Matchers::WithinAbs;

TEST_CASE("AutonomousMovementSystem update function moves entities correctly", "[System][MovementSystemUpdate][UpdateMethod]") {
    ecsManager = std::make_unique<ECSManager>();


    ecsManager->addSystem<AutonomousMovementSystem>();


    Position pos;
    pos.xPos = 0.0f;
    pos.yPos = 0.0f;
    std::shared_ptr<Velocity> velocity = std::make_shared<Velocity>(2.0, 3.0);

    Entity entity = ecsManager->createEntity();
    ecsManager->addComponentToEntity<PositionComponent>(entity, pos);
    ecsManager->addComponentToEntity<MovementComponent>(entity, velocity);

    ecsManager->getSystem<AutonomousMovementSystem>().update(1);

    const auto& updatedPosition = ecsManager->getComponentFromEntity<PositionComponent>(entity);
    REQUIRE_THAT(updatedPosition.getPosition().xPos, WithinAbs(2.0, 1e-6)); // Check x position with a margin of error
    REQUIRE_THAT(updatedPosition.getPosition().yPos, WithinAbs(3.0, 1e-6)); // Check y position with a margin of error
}
