#include <catch2/catch_test_macros.hpp>
#include <memory>
#include "../../main/Game/Map/FrameMap/MapManager.h"
#include "../../main/ECS/Design/Managers/ECSManager.h"

extern std::unique_ptr<ECSManager> ecsManager;

//TEST_CASE("Frame Map Surround Location Test", "[MapManager]"){
//    ecsManager = std::make_unique<ECSManager>();
//    window->windowWidth = 1000;
//    window->windowHeight = 1000;
//    Position startingPosition(10000, 10000);
//    MapManager mapManager(startingPosition);
//    mapManager.surroundLocation(startingPosition);
//
//    Position topMiddle = startingPosition + Position(0, -Window::windowHeight);
//    REQUIRE(mapManager.isFrameAtPositionFilled(topMiddle));
//
//    Position middleLeft = startingPosition + Position(-Window::windowWidth, 0);
//    REQUIRE(mapManager.isFrameAtPositionFilled(middleLeft));
//
//    Position middleRight = startingPosition + Position(Window::windowWidth, 0);
//    REQUIRE(mapManager.isFrameAtPositionFilled(middleRight));
//
//    Position bottomMiddle = startingPosition + Position(0, Window::windowHeight);
//    REQUIRE(mapManager.isFrameAtPositionFilled(bottomMiddle));
//}