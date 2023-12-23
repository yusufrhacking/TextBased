#include <catch2/catch_test_macros.hpp>
#include "../main/HighLevel/ECSManager.h"

TEST_CASE("Entity Testing"){
    std::unique_ptr<ECSManager> manager = std::make_unique<ECSManager>();
    Entity testEntity = manager->createEntity();
    SECTION("Add and retrieve component"){
        manager->addComponentToEntity<GenericStyleComponent>(testEntity);
        REQUIRE(typeid(manager->getComponentFromEntity<GenericStyleComponent>(testEntity)) == typeid(GenericStyleComponent));
    }
    SECTION("Add and remove component"){
        manager->addComponentToEntity<GenericStyleComponent>(testEntity);

        manager->removeComponentFromEntity<GenericStyleComponent>(testEntity);

        REQUIRE_THROWS(manager->getComponentFromEntity<GenericStyleComponent>(testEntity));
    }

}