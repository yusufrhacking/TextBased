#ifndef TEXTBASED_VELOCITY_H
#define TEXTBASED_VELOCITY_H

struct Velocity{
    double xVelocity;
    double yVelocity;

    Velocity(double x, double y){
        this->xVelocity = x;
        this->yVelocity = y;
    }

    Velocity(){
        this->xVelocity = 0;
        this->yVelocity = 0;
    }
};

#endif //TEXTBASED_VELOCITY_H
