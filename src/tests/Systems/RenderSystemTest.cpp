#include <catch2/catch_test_macros.hpp>
#include "gmock/gmock.h"
#include <memory>
#include "../MockScopeGuard.h"
#include "../../main/ECS/Design/Managers/ECSManager.h"

extern std::unique_ptr<ECSManager> ecsManager;
TEST_CASE("Render System", "[System][RenderSystem]") {
    ::testing::InitGoogleTest();
    ::testing::GTEST_FLAG(throw_on_failure) = true;
    ecsManager = std::make_unique<ECSManager>();

    ecsManager->addSystem<RenderSystem>();
    Entity entity = ecsManager->createEntity();
    ecsManager->addComponentToEntity<PositionComponent>(entity, std::make_shared<Position>(0, 0));
    ecsManager->addComponentToEntity<TextComponent>(entity, "text");
    ecsManager->addComponentToEntity<StyleComponent>(entity);
    SECTION("Adding and Removing Components") {
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
        SECTION("Test removing StyleComponent removes entity from Render System") {
            ecsManager->removeComponentFromEntity<StyleComponent>(entity);
            RenderSystem system = ecsManager->getSystem<RenderSystem>();
            REQUIRE(!system.getRelevantEntities().contains(entity));
        }
    }
    SECTION("Updating"){
        std::shared_ptr<MockRenderer> mr = std::make_shared<MockRenderer>();
        auto mockGuard = MockScopeGuard(mr);
        EXPECT_CALL(*mr, renderText(testing::_, testing::_, testing::_)).Times(1);
        EXPECT_CALL(*mr, renderFrame()).Times(1);
        ecsManager->render(mr);
    }
}
