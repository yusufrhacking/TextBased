#include <catch2/catch_test_macros.hpp>
#include "../../main/Positioning/PositionComponent.h"
#include "../../main/HighLevel/ECSManager.h"
#include "../../main/Camera/CameraFollowSystem.h"
#include "../../main/TheCanon/CanonRegisteringSystem.h"

extern std::unique_ptr<ECSManager> ecsManager;

TEST_CASE("Entity moving is updated in Canon", "[MapPosition][PositionComponent]"){
    ecsManager = std::make_unique<ECSManager>();

    Page::pageWidth = 1470;
    Page::pageHeight = 956;

    auto startingPosition = Position(1000, 1000);
    Canon canon{startingPosition};
    ecsManager->addSystem<CanonRegisteringSystem>(canon);

    auto entity = ecsManager->createEntity();
    ecsManager->addComponentToEntity<PositionComponent>(entity, startingPosition);

    ecsManager->addNewEntities();

    auto& positionComp = ecsManager->getComponentFromEntity<PositionComponent>(entity);
    auto& canonSystem = ecsManager->getSystem<CanonRegisteringSystem>();
    canonSystem.update();

    positionComp.shiftPosition(1000, 1000);
    canonSystem.update();

    auto expectedMapPosition = Canon::getMapPosition(positionComp.getPosition());
    auto entitiesAtNewPage = canon.getEntitiesAtPage(expectedMapPosition);

    REQUIRE(entitiesAtNewPage.contains(entity));

    auto entitiesAtOldPage = canon.getEntitiesAtPage(startingPosition);
    REQUIRE(!entitiesAtOldPage.contains(entity));
}