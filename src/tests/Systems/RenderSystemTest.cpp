#include <catch2/catch_test_macros.hpp>
#include "../../main/ECS/Design/Managers/ECSManager.h"

extern std::unique_ptr<ECSManager> ecsManager;

TEST_CASE("Adding and removing components from render system", "[System][RenderSystem]"){
    ecsManager = std::make_unique<ECSManager>();
    ecsManager->addSystem<RenderSystem>();
    Entity entity = ecsManager->createEntity();
    ecsManager->addComponentToEntity<PositionComponent>(entity, std::make_shared<Position>(0, 0));
    ecsManager->addComponentToEntity<TextComponent>(entity, "text");
    ecsManager->addComponentToEntity<StyleComponent>(entity);

    SECTION("Test if in Render System") {
        RenderSystem system = ecsManager->getSystem<RenderSystem>();
        REQUIRE(system.getRelevantEntities().contains(entity));
    }
    SECTION("Test Removing PositionComponent removes entity from Render System") {
        ecsManager->removeComponentFromEntity<PositionComponent>(entity);
        RenderSystem system = ecsManager->getSystem<RenderSystem>();
        REQUIRE(!system.getRelevantEntities().contains(entity));
    }
    SECTION("Test Removing TextComponent removes entity from Render System") {
        ecsManager->removeComponentFromEntity<TextComponent>(entity);
        RenderSystem system = ecsManager->getSystem<RenderSystem>();
        REQUIRE(!system.getRelevantEntities().contains(entity));
    }
    SECTION("Test removing StyleComponent removes entity from Render System"){
        ecsManager->removeComponentFromEntity<StyleComponent>(entity);
        RenderSystem system = ecsManager->getSystem<RenderSystem>();
        REQUIRE(!system.getRelevantEntities().contains(entity));
    }
}

TEST_CASE("Entities being updated! - Using a mock renderer"){

}