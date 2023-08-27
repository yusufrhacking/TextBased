#include <catch2/catch_test_macros.hpp>
#include "../../main/ECS/Components/PositionComponent.h"
#include "../../main/ECS/Design/Managers/ECSManager.h"

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

TEST_CASE("Canon System", "[Canon]"){
    Page::pageWidth = 1470;
    Page::pageHeight = 956;
    ecsManager = std::make_unique<ECSManager>();


}