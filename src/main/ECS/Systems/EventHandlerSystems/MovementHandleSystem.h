#ifndef TEXTBASED_MOVEMENTHANDLESYSTEM_H
#define TEXTBASED_MOVEMENTHANDLESYSTEM_H


#include "EventConsumerSystem.h"
#include "../../../Helpers/EventSystem/Events/MovementEvent.h"

class MovementHandleSystem: public EventConsumerSystem {
public:
    MovementHandleSystem();
    void listenToEvents();
    void onMovement(MovementEvent& event);


};


#endif //TEXTBASED_MOVEMENTHANDLESYSTEM_H
