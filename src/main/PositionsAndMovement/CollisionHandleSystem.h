#ifndef TEXTBASED_COLLISIONHANDLESYSTEM_H
#define TEXTBASED_COLLISIONHANDLESYSTEM_H

#include "../ECSObjects/EventConsumerSystem.h"
#include "CollisionEvent.h"

class CollisionHandleSystem: public EventConsumerSystem {
public:
    CollisionHandleSystem();

    void listenToEvents();

    void onCollision(CollisionEvent &event);

private:
    std::vector<Entity> getChildEntities(const Entity &entity);

    void revertPosition(const Entity &entity, const std::vector<Entity> &childEntities);

    void updateChildPositions(const std::vector<Entity> &childEntities, float overlap, bool movePositive);
};

#endif //TEXTBASED_COLLISIONHANDLESYSTEM_H
