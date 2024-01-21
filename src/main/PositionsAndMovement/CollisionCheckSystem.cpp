#include <spdlog/spdlog.h>
#include "CollisionCheckSystem.h"
#include "PositionComponent.h"
#include "CollisionEvent.h"
#include "DistanceCalculator.h"
#include "LiveComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

CollisionCheckSystem::CollisionCheckSystem() {
    requireComponent<PositionComponent>();
    requireComponent<TextComponent>();
    requireComponent<CollisionComponent>();
    requireComponent<LiveComponent>();
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

bool CollisionCheckSystem::checkAABBCollision(const Position firstPosition, EntitySize firstCollider,
                                              const Position secondPosition, EntitySize secondCollider) {
    return DistanceCalculator::checkAABBCollision(firstPosition, firstCollider,
                                                 secondPosition, secondCollider);
}




