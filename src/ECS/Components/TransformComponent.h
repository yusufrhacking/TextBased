#ifndef TEXTBASED_TRANSFORMCOMPONENT_H
#define TEXTBASED_TRANSFORMCOMPONENT_H
#include "../../Objects/Position.h"
#include "../../Objects/Velocity.h"

struct TransformComponent {
    Position* position;
    Velocity* velocity;

    TransformComponent(Position* position, Velocity* velocity){
        this->position = position;
        this->velocity = velocity;
    }

    TransformComponent() {
        this->position = new Position(0, 0);
        this->velocity = new Velocity(0, 0);
    }
};


#endif //TEXTBASED_TRANSFORMCOMPONENT_H
