#include <spdlog/spdlog.h>
#include "FrameMap.h"
#include "../../Levels/Forest/ForestFrame.h"
#include "../../Levels/Forest/VerticalForestFrame.h"
#include "../../Levels/Forest/FourWayForestFrame.h"

FrameMap::FrameMap(Position startingPosition) {
    this->startingPosition = startingPosition;
    frameMap = std::vector<std::vector<FrameCell>>(numRows, std::vector<FrameCell>(numCols));
    startingMapPosition = getMapPositionFromGamePosition(startingPosition);
    auto& startingCell = frameMap[startingMapPosition.xPos][startingMapPosition.yPos];//need to add adjustment to make the middle though
    startingCell.frame = std::make_unique<FourWayForestFrame>(startingPosition);
    startingCell.isFilled = true;//THE CAMERA POSITIONS ARE TIED
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

            int neighborX = playerMapPosition.xPos + deltaX;
            int neighborY = playerMapPosition.yPos + deltaY;

            if (neighborX >= 0 && neighborY >= 0) {
                if (neighborX == 8 && neighborY == 11){
                    spdlog::warn("FUCK");
                }
                auto& neighborCell = frameMap[neighborX][neighborY];
                if (!neighborCell.isFilled) {
                    auto newPosition = Window::deriveRelativeTopLeft(playerPosition);
                    auto positionDirection = Position((float)deltaX * (float)frameWidth, (float)deltaY * (float)frameHeight);
                    newPosition += positionDirection;
                    neighborCell.frame = std::make_unique<VerticalForestFrame>(newPosition);
                    neighborCell.isFilled = true;
                }
            }
        }
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
