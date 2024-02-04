#include <catch2/catch_test_macros.hpp>
#include "../../main/Positioning/PositionComponent.h"
#include "../../main/HighLevel/ECSManager.h"
#include "../../main/TheCanon/CanonRegisteringSystem.h"
#include "../../main/Camera/CameraFollowSystem.h"
#include "../../main/PositionsAndMovement/MovementSystem.h"

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
    ecsManager->addSystem<CanonRegisteringSystem>(canon);

    auto test = ecsManager->createEntity();
    ecsManager->addComponentToEntity<PositionComponent>(test, startingPosition);

    ecsManager->addNewEntities();

    SECTION("Canon System Places All Entities"){
        ecsManager->getSystem<CanonRegisteringSystem>().placeAllEntities();
        auto entitiesAtPage = canon.getEntitiesAtPage(startingPosition);
        REQUIRE(entitiesAtPage.contains(test));
    }
    SECTION("Canon System Specific Entity"){
        ecsManager->getSystem<CanonRegisteringSystem>().placeEntity(test);
        auto entitiesAtPage = canon.getEntitiesAtPage(startingPosition);
        REQUIRE(entitiesAtPage.contains(test));
    }
}

TEST_CASE("Position Component Places Player", "[Canon]"){
    ecsManager = std::make_unique<ECSManager>();

    Page::pageWidth = 1470;
    Page::pageHeight = 956;

    auto startingPosition = Position(1000, 1000);
    Canon canon{startingPosition};
    ecsManager->addSystem<CanonRegisteringSystem>(canon);

    auto test = ecsManager->createEntity();
    ecsManager->addComponentToEntity<PositionComponent>(test, startingPosition);
    ecsManager->addNewEntities();
    ecsManager->getSystem<CanonRegisteringSystem>().update();


    auto entitiesAtPage = canon.getEntitiesAtPage(startingPosition);

    REQUIRE(entitiesAtPage.contains(test));
}