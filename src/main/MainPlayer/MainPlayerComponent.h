#ifndef TEXTBASED_MAINPLAYERCOMPONENT_H
#define TEXTBASED_MAINPLAYERCOMPONENT_H
#include <memory>
#include "../Positioning/Velocity.h"

struct MainPlayerComponent{
    std::shared_ptr<Velocity> movementSpeed;

    explicit MainPlayerComponent(std::shared_ptr<Velocity> velocity){
        this->movementSpeed = velocity;
    }

    MainPlayerComponent() {
        this->movementSpeed = std::make_shared<Velocity>(0, 0);
    }
};
#endif
