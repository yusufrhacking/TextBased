#ifndef TEXTBASED_POSITIONCOMPONENT_H
#define TEXTBASED_POSITIONCOMPONENT_H
#include "../../Helpers/Objects/Position.h"
#include "../../Helpers/Objects/Velocity.h"
#include <memory>
#include <utility>

struct PositionComponent {
    std::shared_ptr<Position> position;

    explicit PositionComponent(std::shared_ptr<Position>position){
        this->position = std::move(position);
    }

    explicit PositionComponent(Position position){
        this->position = std::make_shared<Position>(position.xPos, position.yPos);
    }

    PositionComponent() {
        this->position = std::make_shared<Position>(0, 0);
    }
};


#endif
