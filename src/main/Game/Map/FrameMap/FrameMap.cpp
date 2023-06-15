#include <spdlog/spdlog.h>
#include "FrameCell.h"
#include "FrameMap.h"
#include "../../Levels/Forest/ForestFrame.h"
#include "../../Levels/Forest/VerticalForestFrame.h"
#include "../../Levels/Forest/FourWayForestFrame.h"

FrameMap::FrameMap(Position startingPosition): startingPosition(startingPosition) {
    frameMap = std::vector<std::vector<FrameCell>>(numRows, std::vector<FrameCell>(numCols));
    startingMapPosition = getMapPositionFromGamePosition(startingPosition);
    auto& startingCell = frameMap[startingMapPosition.xPos][startingMapPosition.yPos];//need to add adjustment to make the middle though
    startingCell.frame = std::make_unique<FourWayForestFrame>(startingPosition);
    startingCell.isFilled = true;//THE CAMERA POSITIONS ARE TIED
    startingCell.biome = FOREST;
    applyBiomeToRadius(FOREST, 10);
}

Frame &FrameMap::getFrame(Position position) {
    auto mapPosition = getMapPositionFromGamePosition(position);
    return *frameMap[mapPosition.xPos][mapPosition.yPos].frame;
}

void FrameMap::surroundLocation(Position playerPosition) {
    auto playerMapPosition = getMapPositionFromGamePosition(playerPosition);
    for (int deltaX = -1; deltaX <= 1; ++deltaX) {
        for (int deltaY = -1; deltaY <= 1; ++deltaY) {
            if (deltaX == 0 && deltaY == 0) {
                continue;
            }
            auto newMapPosition = playerMapPosition + MapPosition(deltaX, deltaY);

            if (newMapPosition.isPositionPositive()) {
                auto& newCell = frameMap[newMapPosition.xPos][newMapPosition.yPos];
                if (!newCell.isFilled) {
                    auto newGamePosition = Window::deriveRelativeTopLeft(playerPosition);
                    auto positionDirection = Position((float)deltaX * (float)frameWidth, (float)deltaY * (float)frameHeight);
                    newGamePosition += positionDirection;
                    frameCellAtPosition(newCell, newGamePosition);
                }
            }
        }
    }
}

void FrameMap::frameCellAtPosition(FrameCell &cell, Position position) {
    if (cell.biome == FOREST){
        cell.frame = std::make_unique<FourWayForestFrame>(position);
        cell.isFilled = true;
    }
}



bool FrameMap::isFrameAtPositionFilled(Position position) {
    auto mapPosition = getMapPositionFromGamePosition(position);
    return frameMap[mapPosition.xPos][mapPosition.yPos].isFilled;
}

MapPosition FrameMap::getMapPositionFromGamePosition(Position playerPosition) {
    int rowPos = (int)playerPosition.xPos/frameWidth;
    int colPos = (int)playerPosition.yPos/frameHeight;
    return {rowPos, colPos};
}

Position FrameMap::getGamePositionFromMapPosition(MapPosition mapPosition) {
    int xPos = mapPosition.xPos * frameWidth;
    int yPos = (int)mapPosition.yPos * frameHeight;
    return {static_cast<float>(xPos), static_cast<float>(yPos)};
}

void FrameMap::applyBiomeToRadius(Biome biome, int radius) {
    int halfRadius = radius/2;
    for (int deltaX = -halfRadius; deltaX < halfRadius; ++deltaX) {
        for (int deltaY = -halfRadius; deltaY < 1; ++deltaY) {
            auto mapPosition = startingMapPosition + MapPosition(deltaX, deltaY);
            frameMap[mapPosition.xPos][mapPosition.yPos].biome = FOREST;
        }
    }
}
