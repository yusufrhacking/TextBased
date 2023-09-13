#include "CollisionHandleSystem.h"
#include "../HighLevel/ECSManager.h"
#include "CollisionComponent.h"
#include "PositionComponent.h"
#include "../MainPlayer/TiedChildComponent.h"
#include "LiveComponent.h"
#include <stdexcept>

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

CollisionHandleSystem::CollisionHandleSystem() {
    requireComponent<CollisionComponent>();
    requireComponent<LiveComponent>();
    listenToEvents();
}

void CollisionHandleSystem::onCollision(CollisionEvent &event) {
    auto entityA = event.a;
    auto entityB = event.b;
    auto& aPositionComponent = ecsManager->getComponentFromEntity<PositionComponent>(entityA);
    auto& bPositionComponent = ecsManager->getComponentFromEntity<PositionComponent>(entityB);

    auto aLastFrameMoved = aPositionComponent.getFrameLastMoved();
    auto bLastFrameMoved = bPositionComponent.getFrameLastMoved();

    auto aEntities = getChildEntities(entityA);
    auto bEntities = getChildEntities(entityB);

    if (aLastFrameMoved > bLastFrameMoved) {
        revertPosition(entityA, aEntities);
    } else if (aLastFrameMoved == bLastFrameMoved) {
        revertPosition(entityA, aEntities);
        revertPosition(entityB, bEntities);
    } else {
        revertPosition(entityB, bEntities);
    }
}

std::vector<Entity> CollisionHandleSystem::getChildEntities(const Entity& entity) {
    try {
        auto& childrenComponent = ecsManager->getComponentFromEntity<TiedChildComponent>(entity);
        return childrenComponent.entities;
    } catch (...) {
        return {};
    }
}

void CollisionHandleSystem::revertPosition(const Entity& entity, const std::vector<Entity>& childEntities) {
    auto& positionComponent = ecsManager->getComponentFromEntity<PositionComponent>(entity);
    positionComponent.revertPosition();

    for (const auto& child : childEntities) {
        auto& childPositionComponent = ecsManager->getComponentFromEntity<PositionComponent>(child);
        childPositionComponent.revertPosition();
    }
}

void CollisionHandleSystem::listenToEvents() {
    eventBus->listenToEvent<CollisionEvent>(this, &CollisionHandleSystem::onCollision);
}
