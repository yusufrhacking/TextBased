#include "FrameGenerator.h"
#include "../../Levels/Forest/FourWayForestFrame.h"
#include "../../Levels/Forest/VerticalForestFrame.h"

FrameGenerator::FrameGenerator(std::shared_ptr<FrameMap> frameMap) {
    this->frameMap = frameMap;
}

void FrameGenerator::generateFrame(MapPosition playerMapPosition, MapPosition nextFrameMapPosition) {
    if (nextFrameMapPosition.isPositionPositive()) {
        auto& playerCell = frameMap->get(playerMapPosition);
        auto& newFrameCell = frameMap->get(nextFrameMapPosition);
        if (!newFrameCell.isFilled) {
            frameCellAtPosition(playerCell, newFrameCell);
        }
    }
}

void FrameGenerator::frameCellAtPosition(FrameCell &playerCell, FrameCell &newFrameCell) {
    if (newFrameCell.biome == Biome::FOREST){
        if (playerCell.frame->openAt.north && playerCell.frame->openAt.east){
            newFrameCell.frame = std::make_unique<VerticalForestFrame>(newFrameCell.gameReferencePosition);
        } else{
            newFrameCell.frame = std::make_unique<FourWayForestFrame>(newFrameCell.gameReferencePosition);
        }
        newFrameCell.isFilled = true;
    }
}
