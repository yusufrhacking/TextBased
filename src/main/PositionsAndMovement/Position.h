#ifndef TEXTBASED_POSITION_H
#define TEXTBASED_POSITION_H
#include <stdlib.h>

struct Position {
    float x;
    float y;

    Position(float x, float y){
        this->x = x;
        this->y = y;
    }

    Position(int x, int y){
        this->x = (float)x;
        this->y = (float)y;
    }

    Position(){
        this->x = 0;
        this->y = 0;
    }

    float getAbsoluteDifference(Position position) const{
        return abs(position.x - this->x) + abs(position.y - this->y);
    }

    Position operator+(const Position& other) const {
        return {this->x + other.x, this->y + other.y};
    }

    Position operator-(const Position& other) const {
        return {this->x - other.x, this->y - other.y};
    }

    Position& operator+=(const Position& other) {
        this->x += other.x;
        this->y += other.y;
        return *this;
    }

    Position operator/(const Position& other) const{
        return {(x + other.x) / 2, (y + other.y) / 2};
    }
};


#endif //TEXTBASED_POSITION_H
