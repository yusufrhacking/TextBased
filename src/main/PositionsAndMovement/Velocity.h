#ifndef TEXTBASED_VELOCITY_H
#define TEXTBASED_VELOCITY_H

struct Velocity{
    double x;
    double y;

    Velocity(double x, double y){
        this->x = x;
        this->y = y;
    }

    Velocity(){
        this->x = 0;
        this->y = 0;
    }
};

#endif //TEXTBASED_VELOCITY_H
