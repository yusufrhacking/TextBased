#ifndef TEXTBASED_CANONMOVEMENTHANDLESYSTEM_H
#define TEXTBASED_CANONMOVEMENTHANDLESYSTEM_H


#include "EventConsumerSystem.h"
#include "../../../TheCanon/Canon.h"
#include "../../../Helpers/EventSystem/Events/ReadyToMoveEvent.h"
#include "../../../Helpers/EventSystem/Events/PostMovementEvent.h"

class CanonMovementHandleSystem: public EventConsumerSystem {
    Canon& canon;
public:
    CanonMovementHandleSystem(Canon& canon);
    void listenToEvents();
    void onMovement(PostMovementEvent& event);

};


#endif //TEXTBASED_CANONMOVEMENTHANDLESYSTEM_H
