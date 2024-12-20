#ifndef TEXTBASED_MAINPLAYERCOMPONENT_H
#define TEXTBASED_MAINPLAYERCOMPONENT_H
#include <memory>
#include "../PositionsAndMovement/Velocity.h"

struct KeyboardMovementComponent{
    std::shared_ptr<Velocity> movementSpeed;

    explicit KeyboardMovementComponent(std::shared_ptr<Velocity> velocity){
        this->movementSpeed = velocity;
    }

    KeyboardMovementComponent() {
        this->movementSpeed = std::make_shared<Velocity>(0, 0);
    }
};
#endif
