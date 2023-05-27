#ifndef TEXTBASED_POSITION_H
#define TEXTBASED_POSITION_H


struct Position {
    float xPos;
    float yPos;

    Position(float x, float y){
        this->xPos = x;
        this->yPos = y;
    }

    Position(){
        this->xPos = 0;
        this->yPos = 0;
    }

    float getAbsoluteDifference(Position position) const{
        return abs(position.xPos - this->xPos) + abs(position.yPos - this->yPos);
    }
};


#endif //TEXTBASED_POSITION_H
