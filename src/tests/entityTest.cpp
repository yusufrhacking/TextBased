#include <catch2/catch_test_macros.hpp>
#include "../main/ECS/Design/Managers/ECSManager.h"

TEST_CASE("Add and retrieve entity?"){
    ECSManager my;
    std::unique_ptr<ECSManager> manager = std::make_unique<ECSManager>();
    Entity testEntity = manager->createEntity();
    manager->addComponentToEntity<StyleComponent>(testEntity);
    REQUIRE(typeid(manager->getComponent<StyleComponent>(testEntity)) == typeid(StyleComponent));
}