#ifndef TEXTBASED_POSITIONCOMPONENT_H
#define TEXTBASED_POSITIONCOMPONENT_H
#include "../../Helpers/Objects/Position.h"
#include "../../Helpers/Objects/Velocity.h"
#include <memory>
#include <utility>

struct PositionComponent {
private:
    std::shared_ptr<Position> position;
    Position previousPosition;
public:

    explicit PositionComponent(std::shared_ptr<Position> position) {
        this->position = std::move(position);
        this->previousPosition = *this->position;
    }

    explicit PositionComponent(Position position) {
        this->position = std::make_shared<Position>(position.xPos, position.yPos);
        this->previousPosition = Position(position.xPos, position.yPos);
    }

    PositionComponent() {
        this->position = std::make_shared<Position>(0, 0);
        this->previousPosition = Position(0, 0);
    }

    void updatePreviousPosition(){
        previousPosition = *position;
    }

    void changePosition(double xChange, double yChange){
        updatePreviousPosition();
        position->xPos += (float)xChange;
        position->yPos += (float)yChange;
    }

    [[nodiscard]] Position getPosition() const{
        return *position;
    }

    [[nodiscard]] Position getPreviousPosition() const{
        return previousPosition;
    }

    void revertPosition(){
//        printf("REVERTING POSITION\n");
//        printf("UPDATING\n");
//        printf("Previous X Pos: %f\n", previousPosition.xPos);
//        printf("Previous Y Pos: %f\n", previousPosition.yPos);
        *position = previousPosition;
//        printf("New X Pos: %f\n", position->xPos);
//        printf("New Y Pos: %f\n", position->yPos);
    }

};



#endif
