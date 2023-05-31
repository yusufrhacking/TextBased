#include "FrameMap.h"
#include "../../Levels/ForestFrame.h"

FrameMap::FrameMap(Position startingPosition) {
    this->startingPosition = startingPosition;
    frameMap = std::vector<std::vector<FrameCell>>(numRows, std::vector<FrameCell>(numCols));
    startingMapPosition = getMapPositionFromGamePosition(startingPosition);
    auto startingCell = frameMap[startingMapPosition.xPos][startingMapPosition.yPos];
    startingCell.frame = std::make_unique<ForestFrame>(startingPosition);
    startingCell.isFilled = true;
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
                auto& neighborCell = frameMap[neighborX][neighborY];
                if (!neighborCell.isFilled) {
                    auto newPosition = getGamePositionFromMapPosition(playerMapPosition);
                    newPosition += Position((float)deltaX * (float)frameWidth, (float)deltaY * -1 * (float)frameHeight);
                    neighborCell.frame = std::make_unique<ForestFrame>(newPosition);
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
