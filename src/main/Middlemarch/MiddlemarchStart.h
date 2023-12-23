#ifndef TEXTBASED_MIDDLEMARCHSTART_H
#define TEXTBASED_MIDDLEMARCHSTART_H


#include "../PositionsAndMovement/Position.h"

class MiddlemarchStart {
private:
    Position startPosition;
public:
    explicit MiddlemarchStart(Position startingPosition);

    void speakEngineer() const;
};


#endif //TEXTBASED_MIDDLEMARCHSTART_H
