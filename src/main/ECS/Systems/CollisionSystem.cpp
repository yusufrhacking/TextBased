#include "CollisionSystem.h"

extern std::unique_ptr<ECSManager> ecsManager;

void CollisionSystem::update(double deltaTime) {
    auto relevantEntities = getReleventEntities();

    for (auto firstEntity = relevantEntities.begin(); firstEntity != relevantEntities.end(); firstEntity++){
        Entity first = *firstEntity;
        auto& firstPosition = ecsManager->getComponentFromEntity<PositionComponent>(first);
        auto& firstCollider = ecsManager->getComponentFromEntity<ColliderComponent>(first);

        for (auto secondEntity = firstEntity; secondEntity != relevantEntities.end(); secondEntity++){
            Entity second = *secondEntity;

            if (first == second){
                continue;
            }

            auto& secondPosition = ecsManager->getComponentFromEntity<PositionComponent>(second);
            auto& secondCollider = ecsManager->getComponentFromEntity<ColliderComponent>(second);

            bool isAABCollision = checkAABBCollision(firstPosition.position, firstCollider, secondPosition.position, secondCollider);


        }
    }
}

bool CollisionSystem::checkAABBCollision(std::shared_ptr<Position> firstPosition, ColliderComponent firstCollider,
                                         std::shared_ptr<Position> secondPosition, ColliderComponent secondCollider) {
    bool firstXOverlap = firstPosition->xPos < (secondPosition->xPos + secondCollider.widthCollisionRange);
    bool secondXOverlap = (firstPosition->xPos + firstCollider.widthCollisionRange) > secondPosition->xPos;
    bool xOverlap = firstXOverlap && secondXOverlap;

    bool firstYOverlap = firstPosition->yPos < secondPosition->yPos + secondCollider.heightCollisionRange;
    bool secondYOverlap = firstPosition->yPos + firstCollider.heightCollisionRange > secondPosition->yPos;
    bool yOverlap = firstYOverlap && secondYOverlap;

    return xOverlap && yOverlap;
}
