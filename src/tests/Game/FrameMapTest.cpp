#include <catch2/catch_test_macros.hpp>
#include "../../main/Game/Map/FrameMap/FrameMap.h"

TEST_CASE("Frame Map Test"){
    Position startingPosition(1000, 1000);
    FrameMap frameMap(startingPosition);

    SECTION("Filling Frame At Top Right"){
        frameMap.surroundLocation(startingPosition);
        Position topRight = startingPosition + Position((float)Window::windowWidth, (float)Window::windowHeight);
        REQUIRE(frameMap.isFrameAtPositionFilled(topRight));
    }
    //surround a frame, check the position windowWidth to the right and see if the frame is filled
}