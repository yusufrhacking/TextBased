#include <spdlog/spdlog.h>
#include "FrameCell.h"
#include "MapManager.h"
#include "../../Levels/Forest/ForestFrame.h"
#include "../../Levels/Forest/VerticalForestFrame.h"
#include "../../Levels/Forest/FourWayForestFrame.h"

MapManager::MapManager(Position startingPosition) {
    startingMapPosition = getMapPositionFromGamePosition(startingPosition);
    frameMap = std::make_shared<FrameMap>();
    auto& startingCell = frameMap->get(startingMapPosition);
    startingCell.frame = std::make_unique<FourWayForestFrame>(startingPosition);
    startingCell.isFilled = true;
    startingCell.biome = Biome::FOREST;
    applyBiomeAcrossRadius(Biome::FOREST, 2);
}

Frame &MapManager::getFrame(Position position) {
    auto mapPosition = getMapPositionFromGamePosition(position);
    return *frameMap->get(mapPosition).frame;
}

void MapManager::surroundLocation(Position playerPosition) {
    auto playerMapPosition = getMapPositionFromGamePosition(playerPosition);
    auto& playerCell = frameMap->get(playerMapPosition);
    for (int deltaX = -1; deltaX <= 1; ++deltaX) {
        for (int deltaY = -1; deltaY <= 1; ++deltaY) {
            if (deltaX == 0 && deltaY == 0) {
                continue;
            }
            auto nextFrameMapPosition = playerMapPosition + MapPosition(deltaX, deltaY);
            frameGenerator.generateFrame();
            if (nextFrameMapPosition.isPositionPositive()) {
                auto& cell = frameMap->get(nextFrameMapPosition);
                if (!cell.isFilled) {
                    frameCellAtPosition(playerCell, cell);
                }
            }
        }
    }
}

void MapManager::frameCellAtPosition(FrameCell& playerCell, FrameCell &newCell) {
    if (newCell.biome == Biome::FOREST){
        if (playerCell.frame->openAt.north && playerCell.frame->openAt.east){
            newCell.frame = std::make_unique<VerticalForestFrame>(newCell.gameReferencePosition);
        } else{
            newCell.frame = std::make_unique<FourWayForestFrame>(newCell.gameReferencePosition);
        }
        newCell.isFilled = true;
    }
}

void MapManager::applyBiomeAcrossRadius(Biome biome, int radius) {
    for (int deltaX = -radius; deltaX < radius; ++deltaX) {
        for (int deltaY = -radius; deltaY < radius; ++deltaY) {
            auto mapPosition = startingMapPosition + MapPosition(deltaX, deltaY);
            frameMap->get(mapPosition).biome = biome;
        }
    }
}

bool MapManager::isFrameAtPositionFilled(Position position) {
    auto mapPosition = getMapPositionFromGamePosition(position);
    return frameMap->get(mapPosition).isFilled;
}

MapPosition MapManager::getMapPositionFromGamePosition(Position playerPosition) {
    int rowPos = (int)playerPosition.xPos/frameWidth;
    int colPos = (int)playerPosition.yPos/frameHeight;
    return {rowPos, colPos};
}

Position MapManager::getGamePositionFromMapPosition(MapPosition mapPosition) {
    int xPos = mapPosition.xPos * frameWidth;
    int yPos = (int)mapPosition.yPos * frameHeight;
    return {static_cast<float>(xPos), static_cast<float>(yPos)};
}
