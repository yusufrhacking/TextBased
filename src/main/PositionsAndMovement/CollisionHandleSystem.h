#ifndef TEXTBASED_COLLISIONHANDLESYSTEM_H
#define TEXTBASED_COLLISIONHANDLESYSTEM_H

#include "../ECSObjects/EventConsumerSystem.h"
#include "../../../Positioning/CollisionComponent.h"
#include "../../../Helpers/EventSystem/Events/CollisionEvent.h"

class CollisionHandleSystem: public EventConsumerSystem {
public:
    CollisionHandleSystem();

    void listenToEvents();

    void onCollision(CollisionEvent &event);

private:
    Entity findOffender(Entity a, Entity b);

    Entity findDefender(Entity a, Entity b);

    float getMovementTotal(Entity entity);

};

#endif //TEXTBASED_COLLISIONHANDLESYSTEM_H
