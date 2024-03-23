#ifndef TEXTBASED_EMMASTART_H
#define TEXTBASED_EMMASTART_H


#include "../PositionsAndMovement/Position.h"

class EmmaStart {
    Position startingPosition;
public:
    EmmaStart(Position startingPosition);

    void createSubject(Position position);

    void createTerrain(Position position);
};


#endif //TEXTBASED_EMMASTART_H
