#include "CollisionCheckSystem.h"
#include "../../../Helpers/EventSystem/Events/CollisionEvent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

CollisionCheckSystem::CollisionCheckSystem() {
    requireComponent<PositionComponent>();
    requireComponent<TextComponent>();
    requireComponent<CollisionComponent>();
}


void CollisionCheckSystem::update(double deltaTime) {
    auto relevantEntities = getRelevantEntities();

    for (auto firstIterator = relevantEntities.begin(); firstIterator != relevantEntities.end(); firstIterator++){
        Entity first = *firstIterator;
        auto& firstPosition = ecsManager->getComponentFromEntity<PositionComponent>(first);
        auto& firstCollider = ecsManager->getComponentFromEntity<CollisionComponent>(first);

        for (auto secondIterator = firstIterator; secondIterator != relevantEntities.end(); secondIterator++){
            Entity second = *secondIterator;

            if (first == second){
                continue;
            }

            auto& secondPosition = ecsManager->getComponentFromEntity<PositionComponent>(second);
            auto& secondCollider = ecsManager->getComponentFromEntity<CollisionComponent>(second);

            bool isAABCollision = checkAABBCollision(firstPosition.getPosition(), firstCollider, secondPosition.getPosition(), secondCollider);

            if (isAABCollision){
                eventBus->emitEvent<CollisionEvent>(first, second, deltaTime);
//                ecsManager->killEntity(first);
//                ecsManager->killEntity(second);
            }

        }
    }
}

bool CollisionCheckSystem::checkAABBCollision(const Position firstPosition, CollisionComponent firstCollider,
                                              const Position secondPosition, CollisionComponent secondCollider) {
    bool firstXOverlap = firstPosition.xPos < (secondPosition.xPos + secondCollider.widthCollisionRange);
    bool secondXOverlap = (firstPosition.xPos + firstCollider.widthCollisionRange) > secondPosition.xPos;
    bool xOverlap = firstXOverlap && secondXOverlap;

    bool firstYOverlap = firstPosition.yPos < secondPosition.yPos + secondCollider.heightCollisionRange;
    bool secondYOverlap = firstPosition.yPos + firstCollider.heightCollisionRange > secondPosition.yPos;
    bool yOverlap = firstYOverlap && secondYOverlap;

    return xOverlap && yOverlap;
}



