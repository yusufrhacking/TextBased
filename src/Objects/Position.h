#ifndef TEXTBASED_POSITION_H
#define TEXTBASED_POSITION_H


struct Position {
    int xPos;
    int yPos;

    Position(int x, int y){
        this->xPos = x;
        this->yPos = y;
    }

    Position(){
        this->xPos = 0;
        this->yPos = 0;
    }
};


#endif //TEXTBASED_POSITION_H