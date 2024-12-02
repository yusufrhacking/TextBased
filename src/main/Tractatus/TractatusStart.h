#ifndef TEXTBASED_TRACTATUSSTART_H
#define TEXTBASED_TRACTATUSSTART_H
#include "../ECSObjects/Entity.h"

#include "../PositionsAndMovement/Position.h"

class TractatusStart {
    Position startingPosition;
    Entity wittgenstein;
public:
    TractatusStart(Position startingPosition);
};


#endif //TEXTBASED_TRACTATUSSTART_H
