#ifndef TEXTBASED_TRANSFORMCOMPONENT_H
#define TEXTBASED_TRANSFORMCOMPONENT_H
#include "../../Objects/Position.h"
#include "../../Objects/Velocity.h"
#include <memory>
#include <utility>
struct TransformComponent {
    std::shared_ptr<Position> position;

    explicit TransformComponent(std::shared_ptr<Position>position){
        this->position = std::move(position);
    }

    TransformComponent() {
        this->position = std::make_shared<Position>(0, 0);
    }
};


#endif //TEXTBASED_TRANSFORMCOMPONENT_H
