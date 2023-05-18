#ifndef TEXTBASED_COLLISIONHANDLESYSTEM_H
#define TEXTBASED_COLLISIONHANDLESYSTEM_H

#include "EventConsumerSystem.h"
#include "../../Components/CollisionComponent.h"
#include "../../../Helpers/EventSystem/Events/CollisionEvent.h"

class CollisionHandleSystem: public EventConsumerSystem {
public:
    CollisionHandleSystem();

    void listenToEvents();

    void onCollision(CollisionEvent& event);
};


#endif //TEXTBASED_COLLISIONHANDLESYSTEM_H
