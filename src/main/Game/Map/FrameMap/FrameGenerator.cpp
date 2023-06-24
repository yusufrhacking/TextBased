#include "FrameGenerator.h"
#include "../../Levels/Forest/FourWayForestFrame.h"
#include "../../Levels/Forest/VerticalForestFrame.h"
#include "FrameCell.h"
#include "OpenPathsSignature.h"
#include "../../Levels/Forest/SouthOpenForestFrame.h"
#include "../../Levels/Forest/SouthEastOpenForestFrame.h"
#include <bitset>

FrameGenerator::FrameGenerator(std::shared_ptr<FrameMap> frameMap) {
    this->frameMap = frameMap;
}

void FrameGenerator::generateFrame(MapPosition nextFrameMapPosition) {
    if (nextFrameMapPosition.isPositionPositive()) {
        auto& newFrameCell = frameMap->get(nextFrameMapPosition);
        if (!newFrameCell.isFilled) {
            createFrame(newFrameCell);
        }
    }
}

void FrameGenerator::createFrame(FrameCell &newFrameCell) {
    auto openPathsSignature = getOpenPathsSignature(newFrameCell);
//    if (openPathsSignature[NORTH] && openPathsSignature[SOUTH]){
//        newFrameCell.frame = std::make_unique<VerticalForestFrame>(newFrameCell.gameReferencePosition);
//    }
//    else {
//        newFrameCell.frame = std::make_unique<FourWayForestFrame>(newFrameCell.gameReferencePosition);
//    }
    newFrameCell.frame = std::make_unique<SouthEastOpenForestFrame>(newFrameCell.gameReferencePosition);
    newFrameCell.isFilled = true;
}


OpenPathsSignature FrameGenerator::getOpenPathsSignature(FrameCell& cell){
    auto neighbors = frameMap->getNeighborsOf(cell.mapPosition);
    OpenPathsSignature openPathsSignature;
    for (int x = 0; x < neighbors.size(); x++){//0 = N, 1 = E, 2 = S, 3 = W
        if (!neighbors[x]->isFilled){
            openPathsSignature.set(x, true);
            continue;
        }
        auto neighborIsThisWay = static_cast<Direction>(x);
        auto relevantNeighborSide = FrameCell::getOppositeDirection(neighborIsThisWay);
        if (neighbors[x]->isOpenAt(relevantNeighborSide)){
            openPathsSignature.set(x, true);
        }
    }
    return openPathsSignature;//TIME TO WRITE UNIT TESTS (SHOULD HAVE DONE THIS FIRST BUT I AM SLEEP DEPRIVED);
}
