#ifndef TEXTBASED_POSITIONCOMPONENT_H
#define TEXTBASED_POSITIONCOMPONENT_H
#include "../../Objects/Position.h"
#include "../../Objects/Velocity.h"
#include <memory>
#include <utility>
struct PositionComponent {
    std::shared_ptr<Position> position;

    explicit PositionComponent(std::shared_ptr<Position>position){
        this->position = std::move(position);
    }

    PositionComponent() {
        this->position = std::make_shared<Position>(0, 0);
    }
};


#endif //TEXTBASED_POSITIONCOMPONENT_H
