#ifndef TEXTBASED_COLLISIONCHECKSYSTEM_H
#define TEXTBASED_COLLISIONCHECKSYSTEM_H
#include "UpdateSystem.h"
#include "../../Components/CollisionComponent.h"
#include "../../Components/TextComponents/TextComponent.h"
#include "../../Design/Managers/ECSManager.h"
#include "../../../Helpers/EventSystem/EventBus/EventBus.h"


class CollisionCheckSystem: public UpdateSystem {
    public:
        CollisionCheckSystem();

        void update(double deltaTime) override;

    static bool checkAABBCollision(Position firstPosition, CollisionComponent firstCollider,
                                   Position secondPosition, CollisionComponent secondCollider);

};


#endif //TEXTBASED_COLLISIONCHECKSYSTEM_H
