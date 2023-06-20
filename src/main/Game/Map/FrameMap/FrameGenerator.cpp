#include "FrameGenerator.h"
#include "../../Levels/Forest/FourWayForestFrame.h"
#include "../../Levels/Forest/VerticalForestFrame.h"
#include "FrameCell.h"
#include <bitset>

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

std::bitset<4> FrameGenerator::getOpenPathsSignature(FrameCell cell){
    auto neighbors = frameMap->getNeighborsOf(cell.mapPosition);
    auto openSidesSignature = std::bitset<4>();
    for (int x = 0; x < neighbors.size(); x++){//0 = N, 1 = E, 2 = S, 3 = W
        if (!neighbors[x]->isFilled){
            openSidesSignature.set(x, true);
            continue;
        }
        auto neighborIsThisWay = static_cast<Direction>(x);
        auto relevantNeighborSide = FrameCell::getOppositeDirection(neighborIsThisWay);
        if (neighbors[x]->isOpenAt(relevantNeighborSide)){
            openSidesSignature.set(x, true);
        }
    }
    return openSidesSignature;//TIME TO WRITE UNIT TESTS (SHOULD HAVE DONE THIS FIRST BUT I AM SLEEP DEPRIVED);
}

void FrameGenerator::frameCellAtPosition(FrameCell &newFrameCell) {
    auto openPathsSignature = getOpenPathsSignature(newFrameCell);
    if (newFrameCell.biome == Biome::FOREST){
        if (rand() % 2 == 0){
            newFrameCell.frame = std::make_unique<VerticalForestFrame>(newFrameCell.gameReferencePosition);
        } else{
            newFrameCell.frame = std::make_unique<FourWayForestFrame>(newFrameCell.gameReferencePosition);
        }
        newFrameCell.isFilled = true;
    }
}
