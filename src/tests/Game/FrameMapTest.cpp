#include <catch2/catch_test_macros.hpp>
#include "../../main/Game/Map/FrameMap/FrameMap.h"
extern std::unique_ptr<Window> window;

TEST_CASE("Frame Map Surround Location Test", "[FrameMap]"){
//    window = std::make_unique<Window>();
    window->windowWidth = 1000;
    window->windowHeight = 1000;
    Position startingPosition(1000, 1000);
    FrameMap frameMap(startingPosition);

    frameMap.surroundLocation(startingPosition);
//    SECTION("Top Right Is Created"){
        Position topRight = startingPosition + Position((float)Window::windowWidth, -(float)Window::windowHeight);
        REQUIRE(frameMap.isFrameAtPositionFilled(topRight));
//    }
//    SECTION("Top Middle Is Created"){
        Position topMiddle = startingPosition + Position(0, -(float)Window::windowHeight);
        REQUIRE(frameMap.isFrameAtPositionFilled(topMiddle));
//    }
//    SECTION("Top Left Is Created"){
        Position topLeft = startingPosition + Position(-(float)Window::windowWidth, -(float)Window::windowHeight);
        REQUIRE(frameMap.isFrameAtPositionFilled(topLeft));
//    }
//    SECTION("Middle Left Is Created"){
        Position middleLeft = startingPosition + Position(-(float)Window::windowWidth, 0);
        REQUIRE(frameMap.isFrameAtPositionFilled(middleLeft));
//    }
//    SECTION("Middle Right Is Created"){
        Position middleRight = startingPosition + Position((float)Window::windowWidth, 0);
        REQUIRE(frameMap.isFrameAtPositionFilled(middleRight));
//    }
//    SECTION("Bottom Right Is Created"){
        Position bottomRight = startingPosition + Position((float)Window::windowWidth, (float)Window::windowHeight);
        REQUIRE(frameMap.isFrameAtPositionFilled(bottomRight));
//    }
//    SECTION("Bottom Middle Is Created"){
        Position bottomMiddle = startingPosition + Position(0, (float)Window::windowHeight);
        REQUIRE(frameMap.isFrameAtPositionFilled(bottomMiddle));
//    }
//    SECTION("Bottom Left Is Created"){
        Position bottomLeft = startingPosition + Position(-(float)Window::windowWidth, (float)Window::windowHeight);
        REQUIRE(frameMap.isFrameAtPositionFilled(bottomLeft));
//    }

}