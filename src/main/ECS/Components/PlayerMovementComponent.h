#ifndef TEXTBASED_PLAYERMOVEMENTCOMPONENT_H
#define TEXTBASED_PLAYERMOVEMENTCOMPONENT_H
#include <memory>
#include "../../Helpers/Objects/Velocity.h"

struct PlayerMovementComponent{
    std::shared_ptr<Velocity> velocity;

    explicit PlayerMovementComponent(std::shared_ptr<Velocity> velocity){
        this->velocity = std::move(velocity);
    }

    PlayerMovementComponent() {
        this->velocity = std::make_shared<Velocity>(0, 0);
    }
};
#endif
