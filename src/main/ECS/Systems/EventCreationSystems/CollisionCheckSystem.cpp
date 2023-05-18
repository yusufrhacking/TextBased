#include "CollisionCheckSystem.h"
#include "../../../Helpers/EventSystem/Events/CollisionEvent.h"

extern std::unique_ptr<ECSManager> ecsManager;

CollisionCheckSystem::CollisionCheckSystem() {
    requireComponent<PositionComponent>();
    requireComponent<TextComponent>();
    requireComponent<CollisionComponent>();
}


void CollisionCheckSystem::update(std::shared_ptr<EventBus> eventBus) {
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

            bool isAABCollision = checkAABBCollision(firstPosition.position, firstCollider, secondPosition.position, secondCollider);

            if (isAABCollision){
                eventBus->emitEvent<CollisionEvent>(first, second);
//                ecsManager->killEntity(first);
//                ecsManager->killEntity(second);
            }

        }
    }
}

bool CollisionCheckSystem::checkAABBCollision(std::shared_ptr<Position> firstPosition, CollisionComponent firstCollider,
                                              std::shared_ptr<Position> secondPosition, CollisionComponent secondCollider) {
    bool firstXOverlap = firstPosition->xPos < (secondPosition->xPos + secondCollider.widthCollisionRange);
    bool secondXOverlap = (firstPosition->xPos + firstCollider.widthCollisionRange) > secondPosition->xPos;
    bool xOverlap = firstXOverlap && secondXOverlap;

    bool firstYOverlap = firstPosition->yPos < secondPosition->yPos + secondCollider.heightCollisionRange;
    bool secondYOverlap = firstPosition->yPos + firstCollider.heightCollisionRange > secondPosition->yPos;
    bool yOverlap = firstYOverlap && secondYOverlap;

    return xOverlap && yOverlap;
}

void CollisionCheckSystem::handleCollision(Entity firstEntity, Entity secondEntity) {
    // Get relevant components
    auto& firstPosition = ecsManager->getComponentFromEntity<PositionComponent>(firstEntity);
    auto& firstCollider = ecsManager->getComponentFromEntity<CollisionComponent>(firstEntity);
    auto& secondPosition = ecsManager->getComponentFromEntity<PositionComponent>(secondEntity);
    auto& secondCollider = ecsManager->getComponentFromEntity<CollisionComponent>(secondEntity);

    // Calculate collision depth in x and y axes
    float collisionDepthX = getCollisionDepthX(firstPosition, firstCollider, secondPosition, secondCollider);
    float collisionDepthY = getCollisionDepthY(firstPosition, firstCollider, secondPosition, secondCollider);

    // Update positions to resolve collision
    if (std::abs(collisionDepthX) < std::abs(collisionDepthY)) {
        resolveCollisionX(firstPosition, firstCollider, secondPosition, secondCollider, collisionDepthX);
    } else {
        resolveCollisionY(firstPosition, firstCollider, secondPosition, secondCollider, collisionDepthY);
    }
}

float CollisionCheckSystem::getCollisionDepthX(PositionComponent& firstPosition, CollisionComponent& firstCollider,
                                               PositionComponent& secondPosition, CollisionComponent& secondCollider) {
    if (firstPosition.position->xPos < secondPosition.position->xPos) {
        return (firstPosition.position->xPos + firstCollider.widthCollisionRange) - secondPosition.position->xPos;
    } else {
        return (secondPosition.position->xPos + secondCollider.widthCollisionRange) - firstPosition.position->xPos;
    }
}

float CollisionCheckSystem::getCollisionDepthY(PositionComponent& firstPosition, CollisionComponent& firstCollider,
                                               PositionComponent& secondPosition, CollisionComponent& secondCollider) {
    if (firstPosition.position->yPos < secondPosition.position->yPos) {
        return (firstPosition.position->yPos + firstCollider.heightCollisionRange) - secondPosition.position->yPos;
    } else {
        return (secondPosition.position->yPos + secondCollider.heightCollisionRange) - firstPosition.position->yPos;
    }
}

void CollisionCheckSystem::resolveCollisionX(PositionComponent& firstPosition, CollisionComponent& firstCollider,
                                             PositionComponent& secondPosition, CollisionComponent& secondCollider,
                                             float collisionDepthX) {
    if (firstPosition.position->xPos < secondPosition.position->xPos) {
        firstPosition.position->xPos -= collisionDepthX / 2.0f;
        secondPosition.position->xPos += collisionDepthX / 2.0f;
    } else {
        firstPosition.position->xPos += collisionDepthX / 2.0f;
        secondPosition.position->xPos -= collisionDepthX / 2.0f;
    }
}

void CollisionCheckSystem::resolveCollisionY(PositionComponent& firstPosition, CollisionComponent& firstCollider,
                                             PositionComponent& secondPosition, CollisionComponent& secondCollider,
                                             float collisionDepthY) {
    if (firstPosition.position->yPos < secondPosition.position->yPos) {
        firstPosition.position->yPos -= collisionDepthY / 2.0f;
        secondPosition.position->yPos += collisionDepthY / 2.0f;
    } else {
        firstPosition.position->yPos += collisionDepthY / 2.0f;
        secondPosition.position->yPos -= collisionDepthY / 2.0f;
    }
}

