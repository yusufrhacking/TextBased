#include <catch2/catch_test_macros.hpp>
#include "../../main/Positioning/PositionComponent.h"
#include "../../main/HighLevel/ECSManager.h"
#include "../../main/Camera/CameraFollowSystem.h"
#include "../../main/TheCanon/CanonRegisteringSystem.h"
#include "../../main/HighLevel/GameManager.h"



TEST_CASE("Game Manager Adding to Canon Works", "[GameManager][Canon]"){
    ecsManager = std::make_unique<ECSManager>();

    auto startingPosition = Position(1000, 1000);
    auto kirk = GameManager(startingPosition);

    Page::pageWidth = 1470;
    Page::pageHeight = 956;

    auto entity = ecsManager->createEntity();
    ecsManager->addComponentToEntity<PositionComponent>(entity, startingPosition);

    Canon canon{startingPosition};
    ecsManager->addSystem<CanonRegisteringSystem>(canon);
    kirk.update(0.0);

    auto& positionComp = ecsManager->getComponentFromEntity<PositionComponent>(entity);
    auto& canonSystem = ecsManager->getSystem<CanonRegisteringSystem>();

    auto expectedMapPosition = Canon::getMapPosition(positionComp.getPosition());
    auto entitiesAtNewPage = canonSystem.canon.getEntitiesAtPage(expectedMapPosition);

    REQUIRE(entitiesAtNewPage.contains(entity));
}