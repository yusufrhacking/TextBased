#ifndef TEXTBASED_COLLISIONHANDLESYSTEM_H
#define TEXTBASED_COLLISIONHANDLESYSTEM_H

#include "../ECSObjects/EventConsumerSystem.h"
#include "CollisionEvent.h"

class CollisionHandleSystem: public EventConsumerSystem {
public:
    CollisionHandleSystem();

    void handleCollision(float deltaTime, Entity entity);

    void listenToEvents();

    void zeroOutVelocity(Entity entity, CollisionDirection collisionDirection);

    void onCollision(CollisionEvent &event);

private:
    std::set<Entity> getChildEntities(const Entity &entity);

    void revertPosition(const Entity &entity, const std::set<Entity> &childEntities);

    void resolveOverlapBasedOnVelocity(Entity entity1, Entity entity2);


    void updateChildPositions(const std::set<Entity> &childEntities, float overlap, bool movePositive);
};

#endif //TEXTBASED_COLLISIONHANDLESYSTEM_H
