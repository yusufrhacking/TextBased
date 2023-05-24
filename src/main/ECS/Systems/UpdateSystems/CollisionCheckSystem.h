#ifndef TEXTBASED_COLLISIONCHECKSYSTEM_H
#define TEXTBASED_COLLISIONCHECKSYSTEM_H
#include "UpdateSystem.h"
#include "../../Components/CollisionComponent.h"
#include "../../Components/TextComponents/TextComponent.h"
#include "../../Design/Managers/ECSManager.h"
#include "../../../Helpers/EventSystem/EventBus/EventBus.h"
#include "../EventCreationSystems/EventProducerSystem.h"


class CollisionCheckSystem: public UpdateSystem {
    public:
        CollisionCheckSystem();

        void update(double deltaTime) override;

    private:

        bool checkAABBCollision(std::shared_ptr<Position> firstPosition, CollisionComponent firstCollider,
                                std::shared_ptr<Position> secondPosition, CollisionComponent secondCollider);

    void handleCollision(Entity entity, Entity entity1);

    void
    resolveCollisionY(PositionComponent &firstPosition, CollisionComponent &firstCollider,
                      PositionComponent &secondPosition,
                      CollisionComponent &secondCollider, float collisionDepthY);

    void resolveCollisionX(PositionComponent& firstPosition, CollisionComponent& firstCollider,
                           PositionComponent& secondPosition, CollisionComponent& secondCollider,
                           float collisionDepthX);

    float getCollisionDepthY(PositionComponent &firstPosition, CollisionComponent &firstCollider,
                             PositionComponent &secondPosition, CollisionComponent &secondCollider);

    float getCollisionDepthX(PositionComponent &firstPosition, CollisionComponent &firstCollider,
                             PositionComponent &secondPosition, CollisionComponent &secondCollider);
};


#endif //TEXTBASED_COLLISIONCHECKSYSTEM_H
