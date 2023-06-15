#include "FrameCell.h"

FrameCell::FrameCell(): neighbors(4){
    isFilled = false;
    biome = Biome::BLANK;
}

void FrameCell::setNeighborFrame(Direction direction, FrameCell* neighbor) {
    neighbors[direction] = neighbor;
}

bool FrameCell::isNeighborOpen(Direction direction) const {
    auto neighborOpenAt = neighbors[direction]->frame->openAt;
    switch (direction){
        case NORTH: return neighborOpenAt.south;
        case SOUTH: return neighborOpenAt.north;
        case EAST: return neighborOpenAt.west;
        case WEST: return neighborOpenAt.east;
    }
}

//FrameCell FrameCell::getNeighbor(Direction direction) const {
//    return *neighbors[direction];
//}
