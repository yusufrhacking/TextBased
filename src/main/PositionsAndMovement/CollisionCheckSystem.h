#ifndef TEXTBASED_COLLISIONCHECKSYSTEM_H
#define TEXTBASED_COLLISIONCHECKSYSTEM_H
#include "../ECSObjects/UpdateSystem.h"
#include "CollisionComponent.h"
#include "../ECSObjects/FinalSystem.h"
#include "../Text/TextComponent.h"
#include "../HighLevel/ECSManager.h"


class CollisionCheckSystem: public FinalSystem {
    public:
        CollisionCheckSystem();

        void update(double deltaTime) override;

    static bool checkAABBCollision(Position firstPosition, EntitySize firstCollider,
                                   Position secondPosition, EntitySize secondCollider);

};


#endif //TEXTBASED_COLLISIONCHECKSYSTEM_H
