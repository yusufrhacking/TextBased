#ifndef TEXTBASED_COLLISIONCHECKSYSTEM_H
#define TEXTBASED_COLLISIONCHECKSYSTEM_H
#include "../UpdateSystems/UpdateSystem.h"
#include "../../Components/ColliderComponent.h"
#include "../../Components/TextComponent.h"
#include "../../Design/Managers/ECSManager.h"
#include "../../../Helpers/EventSystem/EventBus/EventBus.h"
#include "EventCreationSystem.h"


class CollisionCheckSystem: public EventCreationSystem {
    public:
        CollisionCheckSystem();

        void update(std::shared_ptr<EventBus> eventBus) override;

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


#endif //TEXTBASED_COLLISIONCHECKSYSTEM_H
