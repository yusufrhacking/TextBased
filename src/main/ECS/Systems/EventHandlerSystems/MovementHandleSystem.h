#ifndef TEXTBASED_MOVEMENTHANDLESYSTEM_H
#define TEXTBASED_MOVEMENTHANDLESYSTEM_H


#include "EventConsumerSystem.h"
#include "../../../Helpers/EventSystem/Events/MovementEvent.h"
#include "../../../TheCanon/Canon.h"

class MovementHandleSystem: public EventConsumerSystem {
    Canon& canon;
public:
    MovementHandleSystem(Canon& canon);
    void listenToEvents();
    void onMovement(MovementEvent& event);


};


#endif //TEXTBASED_MOVEMENTHANDLESYSTEM_H
