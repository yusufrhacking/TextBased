#include <catch2/catch_test_macros.hpp>
#include "../../main/ECS/Components/PositionComponent.h"
#include "../../main/ECS/Design/Managers/ECSManager.h"
#include "../../main/ECS/Systems/SpecialSystems/CanonSystem.h"
#include "../../main/ECS/Systems/SpecialSystems/CameraFollowSystem.h"
#include "../../main/ECS/Systems/SpecialSystems/UnprocessedMovements/UnprocessedKeyboardMovementSystem.h"

extern std::unique_ptr<ECSManager> ecsManager;

TEST_CASE("Correct Map Position", "[MapPosition][PositionComponent]"){
    Page::pageWidth = 1470;
    Page::pageHeight = 956;
    SECTION("PositionComponent creates correct MapPosition"){
        Position position(230430, 12020);
        PositionComponent positionComponent(position);

        MapPosition expectedMapPosition = {230430/1470, 12020/956}; //156, 12
        REQUIRE(positionComponent.getMapPosition() == expectedMapPosition);
    }
}


TEST_CASE("Canon System Places Player", "[Canon]"){
    ecsManager = std::make_unique<ECSManager>();

    Page::pageWidth = 1470;
    Page::pageHeight = 956;

    auto startingPosition = Position(1000, 1000);
    Canon canon{startingPosition};
    ecsManager->addSystem<CanonSystem>(canon);

    auto test = ecsManager->createEntity();
    ecsManager->addComponentToEntity<PositionComponent>(test, startingPosition);

    ecsManager->addNewEntities();

    SECTION("Canon System Places All Entities"){
        ecsManager->getSystem<CanonSystem>().placeAllEntities();
        auto entitiesAtPage = canon.getEntitiesAtPage(startingPosition);
        REQUIRE(entitiesAtPage.contains(test));
    }
    SECTION("Canon System Specific Entity"){
        ecsManager->getSystem<CanonSystem>().placeEntity(test);
        auto entitiesAtPage = canon.getEntitiesAtPage(startingPosition);
        REQUIRE(entitiesAtPage.contains(test));
    }


    SECTION("Position Component Spawns in Canon"){

    }
}