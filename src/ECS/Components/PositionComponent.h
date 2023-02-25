#ifndef TEXTBASED_POSITIONCOMPONENT_H
#define TEXTBASED_POSITIONCOMPONENT_H
#include "../../Objects/Position.h"
#include "../../Objects/Velocity.h"

struct PositionComponent {
    Position* position;


    PositionComponent(Position* position, Velocity* velocity){
        this->position = position;
        this->velocity = velocity;
    }

    PositionComponent() {
        this->position = new Position(0, 0);
        this->velocity = new Velocity(0, 0);
    }
};


#endif //TEXTBASED_POSITIONCOMPONENT_H
