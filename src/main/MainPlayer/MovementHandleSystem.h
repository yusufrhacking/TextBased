#ifndef TEXTBASED_MOVEMENTHANDLESYSTEM_H
#define TEXTBASED_MOVEMENTHANDLESYSTEM_H


#include "../ECSObjects/EventConsumerSystem.h"
#include "../../../Helpers/EventSystem/Events/ReadyToMoveEvent.h"
#include "../TheCanon/Canon.h"

class MovementHandleSystem: public EventConsumerSystem {
public:
    MovementHandleSystem();
    void listenToEvents();
    void onMovement(ReadyToMoveEvent& event);


};


#endif //TEXTBASED_MOVEMENTHANDLESYSTEM_H
