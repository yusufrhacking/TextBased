#include <catch2/catch_test_macros.hpp>
#include "../../main/ECS/Components/PositionComponent.h"
#include "../../main/ECS/Design/Managers/ECSManager.h"
#include "../../main/ECS/Systems/SpecialSystems/CameraFollowSystem.h"
#include "../../main/ECS/Systems/SpecialSystems/CanonSystem.h"
#include "../../main/Game/GameManager.h"



TEST_CASE("Game Manager Adding to Canon Works", "[GameManager][Canon]"){
    ecsManager = std::make_unique<ECSManager>();

    auto startingPosition = Position(1000, 1000);
    auto kirk = GameManager(startingPosition);

    Page::pageWidth = 1470;
    Page::pageHeight = 956;

    auto entity = ecsManager->createEntity();
    ecsManager->addComponentToEntity<PositionComponent>(entity, startingPosition);

    Canon canon{startingPosition};
    ecsManager->addSystem<CanonSystem>(canon);
    kirk.update(0.0);

    auto& positionComp = ecsManager->getComponentFromEntity<PositionComponent>(entity);
    auto& canonSystem = ecsManager->getSystem<CanonSystem>();

    auto expectedMapPosition = Canon::getMapPosition(positionComp.getPosition());
    auto entitiesAtNewPage = canonSystem.canon.getEntitiesAtPage(expectedMapPosition);

    REQUIRE(entitiesAtNewPage.contains(entity));
}