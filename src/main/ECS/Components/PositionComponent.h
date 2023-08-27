#ifndef TEXTBASED_POSITIONCOMPONENT_H
#define TEXTBASED_POSITIONCOMPONENT_H
#include "../../Helpers/Objects/Position.h"
#include "../../Helpers/Objects/Velocity.h"
#include "../../Globals.h"
#include "../../Helpers/Objects/MapPosition.h"
#include "../../TheCanon/Canon.h"
#include <memory>
#include <utility>

extern int currFrame;

extern std::unique_ptr<Canon> canon;

struct PositionComponent {
private:
    Position position;
    Position previousPosition;
    MapPosition mapPosition;
    int frameLastMoved = -1;
public:

    explicit PositionComponent(Position position) {
        this->position = position;
        this->previousPosition = this->position;
        mapPosition = Canon::getMapPosition(position);
        canon.
    }

    PositionComponent() {
        this->position = Position(0, 0);
        this->previousPosition = Position(0, 0);
        mapPosition = Canon::getMapPosition(position);
    }


    void changePosition(double xChange, double yChange){
        previousPosition = position;
//        auto prevMapPosition = Canon::getMapPosition(position);
        frameLastMoved = currFrame;
        position.xPos += (float)xChange;
        position.yPos += (float)yChange;
        mapPosition = Canon::getMapPosition(position);
//        if (prevMapPosition != mapPosition){
//
//        }
    }

    [[nodiscard]] Position getPosition() const{
        return position;
    }

    [[nodiscard]] Position getPreviousPosition() const{
        return previousPosition;
    }

    [[nodiscard]] MapPosition getMapPosition() const{
        return mapPosition;
    }

    [[nodiscard]] int getFrameLastMoved() const{
        return frameLastMoved;
    }

    void revertPosition(){
        position = previousPosition;
    }

};



#endif
