#ifndef TEXTBASED_POSITIONCOMPONENT_H
#define TEXTBASED_POSITIONCOMPONENT_H
#include "../../Helpers/Objects/Position.h"
#include "../../Helpers/Objects/Velocity.h"
#include "../../Globals.h"
#include <memory>
#include <utility>

extern int currFrame;

struct PositionComponent {
private:
    Position position;
    Position previousPosition;
    int frameLastMoved = -1;
public:

    explicit PositionComponent(Position position) {
        this->position = position;
        this->previousPosition = this->position;
    }

    PositionComponent() {
        this->position = Position(0, 0);
        this->previousPosition = Position(0, 0);
    }


    void changePosition(double xChange, double yChange){
        previousPosition = position;
        frameLastMoved = currFrame;
        position.xPos += (float)xChange;
        position.yPos += (float)yChange;
    }

    [[nodiscard]] Position getPosition() const{
        return position;
    }

    [[nodiscard]] Position getPreviousPosition() const{
        return previousPosition;
    }

    [[nodiscard]] int getFrameLastMoved() const{
        return frameLastMoved;
    }

    void revertPosition(){
        position = previousPosition;
    }

};



#endif
