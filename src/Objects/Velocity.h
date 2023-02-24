#ifndef TEXTBASED_VELOCITY_H
#define TEXTBASED_VELOCITY_H

struct Velocity{
    int xVelocity;
    int yVelocity;

    Velocity(int x, int y){
        this->xVelocity = x;
        this->yVelocity = y;
    }

    Velocity(){
        this->xVelocity = 0;
        this->yVelocity = 0;
    }
};

#endif //TEXTBASED_VELOCITY_H
