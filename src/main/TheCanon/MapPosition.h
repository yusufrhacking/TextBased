#ifndef TEXTBASED_MAPPOSITION_H
#define TEXTBASED_MAPPOSITION_H

struct MapPosition{
    int xPos;
    int yPos;

    MapPosition(){
        xPos = -1;
        yPos = -1;
    }

    MapPosition(int xPos, int yPos){
        this->xPos = xPos;
        this->yPos = yPos;
    }

    [[nodiscard]] bool isPositionPositive() const{
        return xPos > 0 && yPos > 0;
    }

    [[nodiscard]] int getDistanceFrom(MapPosition other) const{
        return abs(xPos - other.xPos) + abs(yPos - other.yPos);
    }

    bool operator==(const MapPosition& other) const {
        return this->xPos == other.xPos && this->yPos == other.yPos;
    }

    bool operator!=(const MapPosition& other) const {
        return !(*this == other);
    }

    MapPosition operator+(const MapPosition& other) const {
        return {this->xPos + other.xPos, this->yPos + other.yPos};
    }

//    MapPosition operator+(Direction direction) const {
//        switch(direction){
//            case NORTH: return {this->xPos, this->yPos + 1};
//            case EAST: return {this->xPos - 1, this->yPos};
//            case SOUTH: return {this->xPos, this->yPos - 1};
//            case WEST: return {this->xPos + 1, this->yPos};
//        }
//    }

    MapPosition operator-(const MapPosition& other) const {
        return {this->xPos - other.xPos, this->yPos - other.yPos};
    }

    MapPosition& operator+=(const MapPosition& other) {
        this->xPos += other.xPos;
        this->yPos += other.yPos;
        return *this;
    }
};

#endif //TEXTBASED_MAPPOSITION_H
