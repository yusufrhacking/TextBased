#ifndef TEXTBASED_POSITION_H
#define TEXTBASED_POSITION_H
#include <stdlib.h>

struct Position {
    float xPos;
    float yPos;

    Position(float x, float y){
        this->xPos = x;
        this->yPos = y;
    }

    Position(int x, int y){
        this->xPos = (float)x;
        this->yPos = (float)y;
    }



    Position(){
        this->xPos = 0;
        this->yPos = 0;
    }

    float getAbsoluteDifference(Position position) const{
        return abs(position.xPos - this->xPos) + abs(position.yPos - this->yPos);
    }

    Position operator+(const Position& other) const {
        return {this->xPos + other.xPos, this->yPos + other.yPos};
    }

    Position operator-(const Position& other) const {
        return {this->xPos - other.xPos, this->yPos - other.yPos};
    }

    Position& operator+=(const Position& other) {
        this->xPos += other.xPos;
        this->yPos += other.yPos;
        return *this;
    }

    Position operator/(const Position& other) const{
        return {(xPos + other.xPos) / 2, (yPos + other.yPos) / 2};
    }
};


#endif //TEXTBASED_POSITION_H
