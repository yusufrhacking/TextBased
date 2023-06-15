#ifndef TEXTBASED_MAPPOSITION_H
#define TEXTBASED_MAPPOSITION_H
#include "Position.h"

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

    MapPosition operator+(const MapPosition& other) const {
        return {this->xPos + other.xPos, this->yPos + other.yPos};
    }

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
