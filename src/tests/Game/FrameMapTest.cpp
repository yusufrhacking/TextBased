#include <catch2/catch_test_macros.hpp>
#include "../../main/Game/Map/FrameMap/FrameMap.h"
extern std::unique_ptr<Window> window;

TEST_CASE("Frame Map Test", "[FrameMap]"){
    window = std::make_unique<Window>();
    Position startingPosition(1000, 1000);
    FrameMap frameMap(startingPosition);

    frameMap.surroundLocation(startingPosition);
    Position topRight = startingPosition + Position((float)Window::windowWidth, (float)Window::windowHeight);
    REQUIRE(frameMap.isFrameAtPositionFilled(topRight));
}