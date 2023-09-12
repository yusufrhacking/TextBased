#include <spdlog/spdlog.h>
#include "CollisionCheckSystem.h"
#include "PositionComponent.h"
#include "CollisionEvent.h"

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
        auto& firstText = ecsManager->getComponentFromEntity<TextComponent>(first);

        for (auto secondIterator = firstIterator; secondIterator != relevantEntities.end(); secondIterator++){
            Entity second = *secondIterator;

            if (first == second){
                continue;
            }

            auto& secondPosition = ecsManager->getComponentFromEntity<PositionComponent>(second);
            auto& secondText = ecsManager->getComponentFromEntity<TextComponent>(second);

            bool isAABCollision = checkAABBCollision(firstPosition.getPosition(), firstText.getSurfaceSize(),
                                                     secondPosition.getPosition(), secondText.getSurfaceSize());

            if (isAABCollision){
                spdlog::trace("COLLISION between entities {} and {}", first.getId(), second.getId());
                eventBus->emitEvent<CollisionEvent>(first, second, deltaTime);
            }

        }
    }
}

bool CollisionCheckSystem::checkAABBCollision(const Position firstPosition, Size firstCollider,
                                              const Position secondPosition, Size secondCollider) {
    bool firstXOverlap = firstPosition.xPos < (secondPosition.xPos + secondCollider.width);
    bool secondXOverlap = (firstPosition.xPos + firstCollider.width) > secondPosition.xPos;
    bool xOverlap = firstXOverlap && secondXOverlap;

    bool firstYOverlap = firstPosition.yPos < secondPosition.yPos + secondCollider.height;
    bool secondYOverlap = firstPosition.yPos + firstCollider.height > secondPosition.yPos;
    bool yOverlap = firstYOverlap && secondYOverlap;

    return xOverlap && yOverlap;
}




