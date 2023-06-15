#include "FrameCell.h"

FrameCell::FrameCell(): neighbors(4){
    isFilled = false;
    biome = BLANK;
}

void FrameCell::setNeighborFrame(Direction direction, FrameCell* neighbor) {
    neighbors[direction] = neighbor;
}
