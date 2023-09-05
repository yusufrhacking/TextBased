#ifndef TEXTBASED_CANONMOVEMENTHANDLESYSTEM_H
#define TEXTBASED_CANONMOVEMENTHANDLESYSTEM_H
#include "../ECSObjects/EventConsumerSystem.h"
#include "Canon.h"
#include "../PositionsAndMovement/PostMovementEvent.h"

class CanonMovementHandleSystem: public EventConsumerSystem {
    Canon& canon;
public:
    CanonMovementHandleSystem(Canon& canon);
    void listenToEvents();
    void onMovement(PostMovementEvent& event);

};


#endif //TEXTBASED_CANONMOVEMENTHANDLESYSTEM_H
