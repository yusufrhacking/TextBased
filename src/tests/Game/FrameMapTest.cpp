#include <catch2/catch_test_macros.hpp>
#include "../../main/Game/Map/FrameMap/FrameMap.h"
extern std::unique_ptr<Window> window;

TEST_CASE("Frame Map Surround Location Test", "[FrameMap]"){
    window->windowWidth = 1000;
    window->windowHeight = 1000;
    Position startingPosition(1000, 1000);
    FrameMap frameMap(startingPosition);

    frameMap.surroundLocation(startingPosition);

    Position topRight = startingPosition + Position((float)Window::windowWidth, -(float)Window::windowHeight);
    REQUIRE(frameMap.isFrameAtPositionFilled(topRight));

    Position topMiddle = startingPosition + Position(0, -(float)Window::windowHeight);
    REQUIRE(frameMap.isFrameAtPositionFilled(topMiddle));

    Position topLeft = startingPosition + Position(-(float)Window::windowWidth, -(float)Window::windowHeight);
    REQUIRE(frameMap.isFrameAtPositionFilled(topLeft));

    Position middleLeft = startingPosition + Position(-(float)Window::windowWidth, 0);
    REQUIRE(frameMap.isFrameAtPositionFilled(middleLeft));

    Position middleRight = startingPosition + Position((float)Window::windowWidth, 0);
    REQUIRE(frameMap.isFrameAtPositionFilled(middleRight));

    Position bottomRight = startingPosition + Position((float)Window::windowWidth, (float)Window::windowHeight);
    REQUIRE(frameMap.isFrameAtPositionFilled(bottomRight));

    Position bottomMiddle = startingPosition + Position(0, (float)Window::windowHeight);
    REQUIRE(frameMap.isFrameAtPositionFilled(bottomMiddle));

    Position bottomLeft = startingPosition + Position(-(float)Window::windowWidth, (float)Window::windowHeight);
    REQUIRE(frameMap.isFrameAtPositionFilled(bottomLeft));
}