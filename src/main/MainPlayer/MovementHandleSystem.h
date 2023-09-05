#ifndef TEXTBASED_MOVEMENTHANDLESYSTEM_H
#define TEXTBASED_MOVEMENTHANDLESYSTEM_H


#include "../ECSObjects/EventConsumerSystem.h"
#include "../TheCanon/Canon.h"
#include "../PositionsAndMovement/ReadyToMoveEvent.h"

class MovementHandleSystem: public EventConsumerSystem {
public:
    MovementHandleSystem();
    void listenToEvents();
    void onMovement(ReadyToMoveEvent& event);


};


#endif //TEXTBASED_MOVEMENTHANDLESYSTEM_H
