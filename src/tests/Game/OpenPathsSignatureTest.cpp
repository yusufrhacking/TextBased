#include <catch2/catch_test_macros.hpp>
#include <memory>
#include "../../main/Game/Map/FrameMap/FrameCell.h"

TEST_CASE("Open Paths Signature Test", "[OpenPaths][MapManager]"){
    FrameCell center, north, east, south, west;
//    center.setNeighborFrame(NORTH, &north);
//    center.setNeighborFrame(EAST, &east);
//    center.setNeighborFrame(SOUTH, &south);
//    center.setNeighborFrame(WEST, &west);

    SECTION("Nothing else is filled"){
//        auto sig = center.getOpenPathsSignature();
        auto expected = std::bitset<4>();
        for (int x=0; x<expected.size(); x++){
            expected.set(x, true);
        }
        REQUIRE(sig == expected);
    }


}