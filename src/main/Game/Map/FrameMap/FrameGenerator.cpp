#include "FrameGenerator.h"
#include "../../Levels/Forest/FourWayForestFrame.h"
#include "../../Levels/Forest/VerticalForestFrame.h"
#include "FrameCell.h"
#include <bitset>
using OpeningSignature = std::bitset<4>();

FrameGenerator::FrameGenerator(std::shared_ptr<FrameMap> frameMap) {
    this->frameMap = frameMap;
}

void FrameGenerator::generateFrame(MapPosition nextFrameMapPosition) {
    if (nextFrameMapPosition.isPositionPositive()) {
        auto& newFrameCell = frameMap->get(nextFrameMapPosition);
        if (!newFrameCell.isFilled) {
            frameCellAtPosition(newFrameCell);
        }
    }
}


std::bitset<4> FrameGenerator::getOpeningSignature(FrameCell& cell){
    auto openSidesSignature = std::bitset<4>();
    auto neighbors = cell.getNeighbors();
    for (int x = 0; x < neighbors.size(); x++){//0 = N, 1 = E, 2 = S, 3 = W
        auto neighborIsThisWay = static_cast<Direction>(x);
        auto relevantNeighborSide = FrameCell::getOppositeDirection(neighborIsThisWay);
    }
}

void FrameGenerator::frameCellAtPosition(FrameCell &newFrameCell) {
    if (newFrameCell.biome == Biome::FOREST){
        if (rand() % 2 == 0){
            newFrameCell.frame = std::make_unique<VerticalForestFrame>(newFrameCell.gameReferencePosition);
        } else{
            newFrameCell.frame = std::make_unique<FourWayForestFrame>(newFrameCell.gameReferencePosition);
        }
        newFrameCell.isFilled = true;
    }
}
