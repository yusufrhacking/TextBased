#ifndef TEXTBASED_COLLISIONCHECKSYSTEM_H
#define TEXTBASED_COLLISIONCHECKSYSTEM_H
#include "../ECSObjects/UpdateSystem.h"
#include "CollisionComponent.h"
#include "../Text/TextComponent.h"
#include "../HighLevel/ECSManager.h"
#include "../../../Helpers/EventSystem/EventBus/EventBus.h"


class CollisionCheckSystem: public UpdateSystem {
    public:
        CollisionCheckSystem();

        void update(double deltaTime) override;

    static bool checkAABBCollision(Position firstPosition, CollisionComponent firstCollider,
                                   Position secondPosition, CollisionComponent secondCollider);

};


#endif //TEXTBASED_COLLISIONCHECKSYSTEM_H
