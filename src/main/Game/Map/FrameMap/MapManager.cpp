#include <spdlog/spdlog.h>
#include "FrameCell.h"
#include "MapManager.h"
#include "../../Levels/Forest/ForestFrame.h"
#include "../../Levels/Forest/VerticalForestFrame.h"
#include "../../Levels/Forest/FourWayForestFrame.h"

MapManager::MapManager(Position startingPosition): startingPosition(startingPosition) {
    startingMapPosition = getMapPositionFromGamePosition(startingPosition);
    auto& startingCell = frameMap[startingMapPosition];//need to add adjustment to make the middle though
    startingCell.frame = std::make_unique<FourWayForestFrame>(startingPosition);
    startingCell.isFilled = true;//THE CAMERA POSITIONS ARE TIED
    startingCell.biome = Biome::FOREST;
    applyBiomeAcrossRadius(Biome::FOREST, 4);
}

Frame &MapManager::getFrame(Position position) {
    auto mapPosition = getMapPositionFromGamePosition(position);
    return *frameMap[mapPosition].frame;
}

void MapManager::surroundLocation(Position playerPosition) {
    auto playerMapPosition = getMapPositionFromGamePosition(playerPosition);
    auto& playerCell = frameMap[playerMapPosition];
    for (int deltaX = -1; deltaX <= 1; ++deltaX) {
        for (int deltaY = -1; deltaY <= 1; ++deltaY) {
            if (deltaX == 0 && deltaY == 0) {
                continue;
            }
            auto mapPosition = playerMapPosition + MapPosition(deltaX, deltaY);

            if (mapPosition.isPositionPositive()) {
                auto& cell = frameMap[mapPosition];
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
    int halfRadius = radius/2;
    for (int deltaX = -halfRadius; deltaX < halfRadius; ++deltaX) {
        for (int deltaY = -halfRadius; deltaY < halfRadius; ++deltaY) {
            auto mapPosition = startingMapPosition + MapPosition(deltaX, deltaY);
            frameMap[mapPosition].biome = biome;
        }
    }
}

bool MapManager::isFrameAtPositionFilled(Position position) {
    auto mapPosition = getMapPositionFromGamePosition(position);
    return frameMap[mapPosition].isFilled;
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
