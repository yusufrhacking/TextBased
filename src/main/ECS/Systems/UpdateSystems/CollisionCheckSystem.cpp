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
                Entity offender = findOffender(first, second);
                Entity defender = findDefender(first, second);

                eventBus->emitEvent<CollisionEvent>(offender, defender, deltaTime);
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

Entity CollisionCheckSystem::findOffender(Entity a, Entity b) {
    auto aMovementTotal = getMovementTotal(a);
    auto bMovementTotal = getMovementTotal(b);

    if (aMovementTotal > bMovementTotal){
        return a;
    } else{
        return b;
    }
}

Entity CollisionCheckSystem::findDefender(Entity a, Entity b) {
    auto aMovementTotal = getMovementTotal(a);
    auto bMovementTotal = getMovementTotal(b);

    if (aMovementTotal < bMovementTotal){
        return a;
    } else{
        return b;
    }
}

float CollisionCheckSystem::getMovementTotal(Entity entity) {
    auto aPositionComponent = ecsManager->getComponentFromEntity<PositionComponent>(entity);
    auto currentPos = aPositionComponent.getPosition();
    auto previousPos = aPositionComponent.getPreviousPosition();

    float xChange = currentPos.xPos - previousPos.xPos;
    float yChange = currentPos.yPos - previousPos.yPos;
    return abs(xChange)+abs(yChange);
}


