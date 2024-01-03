#ifndef TEXTBASED_COLLISIONHANDLESYSTEM_H
#define TEXTBASED_COLLISIONHANDLESYSTEM_H

#include "../ECSObjects/EventConsumerSystem.h"
#include "CollisionEvent.h"

class CollisionHandleSystem: public EventConsumerSystem {
public:
    CollisionHandleSystem();

    void listenToEvents();

    void zeroOutVelocity(Entity entity, CollisionDirection collisionDirection);

    void onCollision(CollisionEvent &event);

private:
    std::set<Entity> getChildEntities(const Entity &entity);

    void revertPosition(const Entity &entity, const std::set<Entity> &childEntities);

    void updateChildPositions(const std::set<Entity> &childEntities, float overlap, bool movePositive);
};

#endif //TEXTBASED_COLLISIONHANDLESYSTEM_H
