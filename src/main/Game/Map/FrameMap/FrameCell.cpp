#include "FrameCell.h"

FrameCell::FrameCell(): neighbors(4){
    isFilled = false;
    biome = Biome::BLANK;
}

void FrameCell::setNeighborFrame(Direction direction, FrameCell* neighbor) {
    neighbors[direction] = neighbor;
}

std::bitset<4> FrameCell::getOpenPathsSignature(){
    auto openSidesSignature = std::bitset<4>();
    for (int x = 0; x < neighbors.size(); x++){//0 = N, 1 = E, 2 = S, 3 = W
        if (!neighbors[x]->isFilled){
            openSidesSignature.set(x, true);
            continue;
        }
        auto neighborIsThisWay = static_cast<Direction>(x);
        auto relevantNeighborSide = getOppositeDirection(neighborIsThisWay);
        if (neighbors[x]->isOpenAt(relevantNeighborSide)){
            openSidesSignature.set(x, true);
        }
    }
    return openSidesSignature;//TIME TO WRITE UNIT TESTS (SHOULD HAVE DONE THIS FIRST BUT I AM SLEEP DEPRIVED);
}

bool FrameCell::isOpenAt(Direction direction) const{
    switch (direction){
        case NORTH: return frame->openAt.north;
        case SOUTH: return frame->openAt.south;
        case EAST: return frame->openAt.east;
        case WEST: return frame->openAt.west;
    }
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
