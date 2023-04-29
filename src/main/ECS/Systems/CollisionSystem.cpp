#include "CollisionSystem.h"

extern std::unique_ptr<ECSManager> ecsManager;

CollisionSystem::CollisionSystem() {
    requireComponent<PositionComponent>();
    requireComponent<TextComponent>();
    requireComponent<ColliderComponent>();
}


void CollisionSystem::update(double deltaTime) {
    auto relevantEntities = getRelevantEntities();

    for (auto firstIterator = relevantEntities.begin(); firstIterator != relevantEntities.end(); firstIterator++){
        Entity first = *firstIterator;
        auto& firstPosition = ecsManager->getComponentFromEntity<PositionComponent>(first);
        auto& firstCollider = ecsManager->getComponentFromEntity<ColliderComponent>(first);

        for (auto secondIterator = firstIterator; secondIterator != relevantEntities.end(); secondIterator++){
            Entity second = *secondIterator;

            if (first == second){
                continue;
            }

            auto& secondPosition = ecsManager->getComponentFromEntity<PositionComponent>(second);
            auto& secondCollider = ecsManager->getComponentFromEntity<ColliderComponent>(second);

            bool isAABCollision = checkAABBCollision(firstPosition.position, firstCollider, secondPosition.position, secondCollider);

            if (isAABCollision){
                ecsManager->killEntity(first);
                ecsManager->killEntity(second);
//                handleCollision(first, second);
            }

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

void CollisionSystem::handleCollision(Entity firstEntity, Entity secondEntity) {
    // Get relevant components
    auto& firstPosition = ecsManager->getComponentFromEntity<PositionComponent>(firstEntity);
    auto& firstCollider = ecsManager->getComponentFromEntity<ColliderComponent>(firstEntity);
    auto& secondPosition = ecsManager->getComponentFromEntity<PositionComponent>(secondEntity);
    auto& secondCollider = ecsManager->getComponentFromEntity<ColliderComponent>(secondEntity);

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

float CollisionSystem::getCollisionDepthX(PositionComponent& firstPosition, ColliderComponent& firstCollider,
                                          PositionComponent& secondPosition, ColliderComponent& secondCollider) {
    if (firstPosition.position->xPos < secondPosition.position->xPos) {
        return (firstPosition.position->xPos + firstCollider.widthCollisionRange) - secondPosition.position->xPos;
    } else {
        return (secondPosition.position->xPos + secondCollider.widthCollisionRange) - firstPosition.position->xPos;
    }
}

float CollisionSystem::getCollisionDepthY(PositionComponent& firstPosition, ColliderComponent& firstCollider,
                                          PositionComponent& secondPosition, ColliderComponent& secondCollider) {
    if (firstPosition.position->yPos < secondPosition.position->yPos) {
        return (firstPosition.position->yPos + firstCollider.heightCollisionRange) - secondPosition.position->yPos;
    } else {
        return (secondPosition.position->yPos + secondCollider.heightCollisionRange) - firstPosition.position->yPos;
    }
}

void CollisionSystem::resolveCollisionX(PositionComponent& firstPosition, ColliderComponent& firstCollider,
                                        PositionComponent& secondPosition, ColliderComponent& secondCollider,
                                        float collisionDepthX) {
    if (firstPosition.position->xPos < secondPosition.position->xPos) {
        firstPosition.position->xPos -= collisionDepthX / 2.0f;
        secondPosition.position->xPos += collisionDepthX / 2.0f;
    } else {
        firstPosition.position->xPos += collisionDepthX / 2.0f;
        secondPosition.position->xPos -= collisionDepthX / 2.0f;
    }
}

void CollisionSystem::resolveCollisionY(PositionComponent& firstPosition, ColliderComponent& firstCollider,
                                        PositionComponent& secondPosition, ColliderComponent& secondCollider,
                                        float collisionDepthY) {
    if (firstPosition.position->yPos < secondPosition.position->yPos) {
        firstPosition.position->yPos -= collisionDepthY / 2.0f;
        secondPosition.position->yPos += collisionDepthY / 2.0f;
    } else {
        firstPosition.position->yPos += collisionDepthY / 2.0f;
        secondPosition.position->yPos -= collisionDepthY / 2.0f;
    }
}

