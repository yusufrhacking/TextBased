#include <catch2/catch_test_macros.hpp>
#include "../../main/ECS/Components/PositionComponent.h"
#include "../../main/ECS/Design/Managers/ECSManager.h"
#include "../../main/ECS/Systems/SpecialSystems/CameraFollowSystem.h"
#include "../../main/ECS/Systems/SpecialSystems/CanonSystem.h"

extern std::unique_ptr<ECSManager> ecsManager;

TEST_CASE("Entity moving is updated in Canon", "[MapPosition][PositionComponent]"){
    ecsManager = std::make_unique<ECSManager>();

    Page::pageWidth = 1470;
    Page::pageHeight = 956;

    auto startingPosition = Position(1000, 1000);
    Canon canon{startingPosition};
    ecsManager->addSystem<CanonSystem>(canon);

    auto entity = ecsManager->createEntity();
    ecsManager->addComponentToEntity<PositionComponent>(entity, startingPosition);

    ecsManager->addNewEntities();

    auto& positionComp = ecsManager->getComponentFromEntity<PositionComponent>(entity);
    auto& canonSystem = ecsManager->getSystem<CanonSystem>();
    canonSystem.update();

    positionComp.changePosition(1000, 1000);
    canonSystem.update();

    auto expectedMapPosition = Canon::getMapPosition(positionComp.getPosition());
    auto entitiesAtNewPage = canon.getEntitiesAtPage(expectedMapPosition);

    REQUIRE(entitiesAtNewPage.contains(entity));
//
//    auto entitiesAtOldPage = canon.getEntitiesAtPage(positionComp.getPosition());
//    REQUIRE(!entitiesAtOldPage.contains(entity));
}