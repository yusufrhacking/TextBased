#ifndef TEXTBASED_FULLBASICLEVEL_H
#define TEXTBASED_FULLBASICLEVEL_H


#include "../ECSObjects/Entity.h"
#include "../PositionsAndMovement/Position.h"

class FullBasicLevel {
public:
    FullBasicLevel(Position startingPosition);

private:
    Position startingPosition;
    void createPlayer();
    Entity witt;
};


#endif //TEXTBASED_FULLBASICLEVEL_H
