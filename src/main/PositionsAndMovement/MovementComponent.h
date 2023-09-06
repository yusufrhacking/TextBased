#ifndef TEXTBASED_MOVEMENTCOMPONENT_H
#define TEXTBASED_MOVEMENTCOMPONENT_H

#include "Velocity.h"
#include <memory>
#include <utility>

struct MovementComponent{
    std::shared_ptr<Velocity> velocity;

    explicit MovementComponent(std::shared_ptr<Velocity> velocity){
        this->velocity = std::move(velocity);
    }

    MovementComponent() {
        this->velocity = std::make_shared<Velocity>(0, 0);
    }
};

#endif
