#ifndef TEXTBASED_EMMASTART_H
#define TEXTBASED_EMMASTART_H


#include "../PositionsAndMovement/Position.h"


class EmmaStart {
    Position startingPosition;
    float newItemX = 1000;

public:
    EmmaStart(Position startingPosition);

    void createSubject(Position position);

    void createTerrain(Position position);

    void createCandidateLetters(Position terrainPosition);

    void createObstacle(Position terrainPosition);

    void createAbyz(const Position &terrainPosition) const;
};


#endif //TEXTBASED_EMMASTART_H
