#include <catch2/catch_test_macros.hpp>
#include "../main/ECS/Design/Managers/ECSManager.h"

TEST_CASE("Entity Testing"){
    ECSManager my;
    std::unique_ptr<ECSManager> manager = std::make_unique<ECSManager>();
    Entity testEntity = manager->createEntity();
    SECTION("Add and retrieve component"){
        manager->addComponentToEntity<StyleComponent>(testEntity);
        REQUIRE(typeid(manager->getComponentFromEntity<StyleComponent>(testEntity)) == typeid(StyleComponent));
    }
    SECTION("Add and remove component"){
        manager->addComponentToEntity<StyleComponent>(testEntity);

        manager->removeComponentFromEntity<StyleComponent>(testEntity);

        REQUIRE_THROWS(manager->getComponentFromEntity<StyleComponent>(testEntity));
    }

}