#include "FrameMap.h"
#include "../../Levels/ForestFrame.h"

FrameMap::FrameMap(Position startingPosition) {
    this->startingPosition = startingPosition;
    frameMap = std::vector<std::vector<FrameCell>>(numRows, std::vector<FrameCell>(numCols, startingFrame));
    auto startingMapPosition = getMapPositionFromGamePosition(this->startingPosition);
    frameMap[startingMapPosition.xPos][startingMapPosition.yPos].frame = ForestFrame(this->startingPosition);
    //create frame at this position
}

Frame &FrameMap::getFrame(Position position) {
    auto mapPosition = getMapPositionFromGamePosition(position);
    return frameMap[mapPosition.xPos][mapPosition.yPos].frame;
}

void FrameMap::surroundLocation(Position playerPosition) {

}

bool FrameMap::isFrameAtPositionFilled(Position position) {
    auto mapPosition = getMapPositionFromGamePosition(position);
    return frameMap[mapPosition.xPos][mapPosition.yPos].isFilled;
}

MapPosition FrameMap::getMapPositionFromGamePosition(Position playerPosition) {
    int frameWidth = Window::windowWidth;
    int rowPos = (int)playerPosition.xPos/frameWidth;
    int frameHeight = Window::windowHeight;
    int colPos = (int)playerPosition.yPos/frameHeight;
    return {rowPos, colPos};
}
