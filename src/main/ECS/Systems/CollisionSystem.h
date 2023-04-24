#ifndef TEXTBASED_COLLISIONSYSTEM_H
#define TEXTBASED_COLLISIONSYSTEM_H
#include "UpdateSystem.h"
#include "../Components/ColliderComponent.h"
#include "../Components/TextComponent.h"
#include "../Design/Managers/ECSManager.h"


class CollisionSystem: public UpdateSystem {
    public:
        CollisionSystem();

        void update(double deltaTime) override;

    private:
        bool checkAABBCollision(std::shared_ptr<Position> firstPosition, ColliderComponent firstCollider,
                                std::shared_ptr<Position> secondPosition, ColliderComponent secondCollider);

    void handleCollision(Entity entity, Entity entity1);

    void
    resolveCollisionY(PositionComponent &firstPosition, ColliderComponent &firstCollider,
                      PositionComponent &secondPosition,
                      ColliderComponent &secondCollider, float collisionDepthY);

    void resolveCollisionX(PositionComponent& firstPosition, ColliderComponent& firstCollider,
                                            PositionComponent& secondPosition, ColliderComponent& secondCollider,
                                            float collisionDepthX);

    float getCollisionDepthY(PositionComponent &firstPosition, ColliderComponent &firstCollider,
                             PositionComponent &secondPosition, ColliderComponent &secondCollider);

    float getCollisionDepthX(PositionComponent &firstPosition, ColliderComponent &firstCollider,
                             PositionComponent &secondPosition, ColliderComponent &secondCollider);
};


#endif //TEXTBASED_COLLISIONSYSTEM_H
