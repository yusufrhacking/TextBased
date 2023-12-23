#include <catch2/catch_test_macros.hpp>
#include "gmock/gmock.h"
#include <memory>
#include "../../MockScopeGuard.h"
#include "../../../main/HighLevel/ECSManager.h"

extern std::unique_ptr<ECSManager> ecsManager;
TEST_CASE("Render System", "[System][EntityRenderSystem]") {
    ::testing::InitGoogleTest();
    ::testing::GTEST_FLAG(throw_on_failure) = true;
    ecsManager = std::make_unique<ECSManager>();

    ecsManager->addSystem<EntityRenderSystem>();
    Entity entity = ecsManager->createEntity();
    ecsManager->addComponentToEntity<PositionComponent>(entity, Position(0, 0));
    ecsManager->addComponentToEntity<TextComponent>(entity, "text");
    ecsManager->addComponentToEntity<GenericStyleComponent>(entity);
    SECTION("Adding and Removing Components") {
        SECTION("Test if in Render System") {
            EntityRenderSystem system = ecsManager->getSystem<EntityRenderSystem>();
            REQUIRE(system.getRelevantEntities().contains(entity));
        }
        SECTION("Test Removing PositionComponent removes entity from Render System") {
            ecsManager->removeComponentFromEntity<PositionComponent>(entity);
            EntityRenderSystem system = ecsManager->getSystem<EntityRenderSystem>();
            REQUIRE(!system.getRelevantEntities().contains(entity));
        }
        SECTION("Test Removing TextComponent removes entity from Render System") {
            ecsManager->removeComponentFromEntity<TextComponent>(entity);
            EntityRenderSystem system = ecsManager->getSystem<EntityRenderSystem>();
            REQUIRE(!system.getRelevantEntities().contains(entity));
        }
        SECTION("Test removing GenericStyleComponent removes entity from Render System") {
            ecsManager->removeComponentFromEntity<GenericStyleComponent>(entity);
            EntityRenderSystem system = ecsManager->getSystem<EntityRenderSystem>();
            REQUIRE(!system.getRelevantEntities().contains(entity));
        }
    }
    SECTION("Updating"){
        std::shared_ptr<MockRenderer> mr = std::make_shared<MockRenderer>();
        auto mockGuard = MockScopeGuard(mr);
        EXPECT_CALL(*mr, renderFrame()).Times(1);
        ecsManager->render(mr);
    }
}
