#include "FrameCell.h"

FrameCell::FrameCell(): neighbors(4){
    isFilled = false;
    biome = Biome::BLANK;
}

void FrameCell::setNeighborFrame(Direction direction, FrameCell* neighbor) {
    neighbors[direction] = neighbor;
}


Direction FrameCell::getOppositeDirection(Direction direction) {
    switch (direction){
        case NORTH: return SOUTH;
        case SOUTH: return NORTH;
        case EAST: return WEST;
        case WEST: return EAST;
    }
}

std::vector<FrameCell *> FrameCell::getNeighbors() const {
    return neighbors;
}

//FrameCell FrameCell::getNeighbor(Direction direction) const {
//    return *neighbors[direction];
//}
