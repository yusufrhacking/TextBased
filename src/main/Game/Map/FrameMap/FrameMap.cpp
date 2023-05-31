#include "FrameMap.h"

FrameMap::FrameMap(Position startingPosition) {
    this->startingPosition = startingPosition;
    //create frame at this position
}

Frame &FrameMap::getFrame(Position position) {
    int xIndex = getXIndexFromPosition(position.xPos);
    int yIndex = getYIndexFromPosition(position.yPos);
    return frameMap[xIndex][yIndex];
}

void FrameMap::surroundLocation(Position playerPosition) {

}

int FrameMap::getXIndexFromPosition(float xPos) {

    return 0;
}

int FrameMap::getYIndexFromPosition(float yPos) {
    return 0;
}

bool FrameMap::isFrameAtPositionFilled(Position position) {
    return false;
}
