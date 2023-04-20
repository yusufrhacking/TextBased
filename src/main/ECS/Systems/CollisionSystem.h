#ifndef TEXTBASED_COLLISIONSYSTEM_H
#define TEXTBASED_COLLISIONSYSTEM_H
#include "UpdateSystem.h"
#include "../Components/ColliderComponent.h"
#include "../Components/TextComponent.h"
#include "../Design/Managers/ECSManager.h"


class CollisionSystem: public UpdateSystem {
    public:
        CollisionSystem(){
            requireComponent<PositionComponent>();
            requireComponent<TextComponent>();//Eventually want to not require something to be visible to collide
            requireComponent<ColliderComponent>();
        }

        void update(double deltaTime) override;

    private:
        bool checkAABBCollision(std::shared_ptr<Position> firstPosition, ColliderComponent firstCollider,
                                std::shared_ptr<Position> secondPosition, ColliderComponent secondCollider);
};


#endif //TEXTBASED_COLLISIONSYSTEM_H
