#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include "../main/ECS/Design/Managers/ECSManager.h"
#include "../main/ECS/Systems/MovementSystem.h"
#include "ECSTest.h"

extern std::unique_ptr<ECSManager> ecsManager;
TEST_CASE("Movement System Testing", "[UpdateSystem]"){
    ecsManager = std::make_unique<ECSManager>();
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

using Catch::Matchers::WithinAbs;

TEST_CASE("MovementSystem update function moves entities correctly", "[UpdateMethod]") {
    // Create an ECSManager instance or mock it as needed
    ecsManager = std::make_unique<ECSManager>();
    // Create a PositionComponent and MovementComponent
    PositionComponent position;
    position.position->xPos = 0.0f;
    position.position->yPos = 0.0f;
    MovementComponent movement;
    movement.velocity->xVelocity = 2.0;
    movement.velocity->yVelocity = 3.0;

    // Add the components to an entity
    Entity entity = ecsManager->createEntity();
    ecsManager->addComponentToEntity<PositionComponent>(entity, std::move(position));
    ecsManager->addComponentToEntity<MovementComponent>(entity, std::move(movement));

    // Update the MovementSystem with a deltaTime of 1.0
    MovementSystem movementSystem;
    movementSystem.update(1.0);

    // Check if the position has been updated correctly
    const auto& updatedPosition = ecsManager->getComponentFromEntity<PositionComponent>(entity);
    REQUIRE_THAT(updatedPosition.position->xPos, WithinAbs(2.0, 1e-6)); // Check x position with a margin of error
    REQUIRE_THAT(updatedPosition.position->yPos, WithinAbs(3.0, 1e-6)); // Check y position with a margin of error
}
