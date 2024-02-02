#ifndef TEXTBASED_MIDDLEMARCHSTART_H
#define TEXTBASED_MIDDLEMARCHSTART_H


#include "../PositionsAndMovement/Position.h"

class MiddlemarchStart {
private:
    Position startPosition;
public:
    void createWitt(Position startingPosition);

    void createSubject(Position subjectPosition);

    void createTarget();

    explicit MiddlemarchStart(Position startingPosition);

    void createPreludeText() const;

    void speakEngineer() const;
};


#endif //TEXTBASED_MIDDLEMARCHSTART_H
