#include "FrameCell.h"

FrameCell::FrameCell(): neighbors(4){
    isFilled = false;
    biome = Biome::BLANK;
}

void FrameCell::setNeighborFrame(Direction direction, FrameCell* neighbor) {
    neighbors[direction] = neighbor;
}

using OpeningSignature = std::bitset<4>();

bool FrameCell::isNeighborOpen(Direction direction) const {
    auto neighborOpenAt = neighbors[direction]->frame->openAt;
    switch (direction){
        case NORTH: return neighborOpenAt.south;
        case SOUTH: return neighborOpenAt.north;
        case EAST: return neighborOpenAt.west;
        case WEST: return neighborOpenAt.east;
    }
}

Direction FrameCell::getOppositeDirection(Direction direction) const {
    switch (direction){
        case NORTH: return SOUTH;
        case SOUTH: return NORTH;
        case EAST: return WEST;
        case WEST: return EAST;
    }
}

//FrameCell FrameCell::getNeighbor(Direction direction) const {
//    return *neighbors[direction];
//}
