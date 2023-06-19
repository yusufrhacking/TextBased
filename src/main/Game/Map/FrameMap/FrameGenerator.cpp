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


void FrameGenerator::frameCellAtPosition(FrameCell &newFrameCell) {
    auto openPathsSignature = newFrameCell.getOpenPathsSignature();
    if (newFrameCell.biome == Biome::FOREST){
        if (rand() % 2 == 0){
            newFrameCell.frame = std::make_unique<VerticalForestFrame>(newFrameCell.gameReferencePosition);
        } else{
            newFrameCell.frame = std::make_unique<FourWayForestFrame>(newFrameCell.gameReferencePosition);
        }
        newFrameCell.isFilled = true;
    }
}
