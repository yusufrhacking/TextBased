#ifndef TEXTBASED_INTROPAC_H
#define TEXTBASED_INTROPAC_H

#include "../ECSObjects/Entity.h"
#include "../PositionsAndMovement/Position.h"

class IntroPac {
public:
    explicit IntroPac(Position startingPosition);
private:
    Entity witt;
    Position startingPosition;

    void createPlayer();

    void createTrees(Position position);

    void createWalls();
};


#endif //TEXTBASED_INTROPAC_H
