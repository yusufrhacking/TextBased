#include "CollisionHandleSystem.h"
#include "../HighLevel/ECSManager.h"
#include "CollisionComponent.h"
#include "PositionComponent.h"
#include "../MainPlayer/TiedChildComponent.h"
#include "LiveComponent.h"
#include <stdexcept>

#include "VelocityComponent.h"

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
        zeroOutVelocity(entityA, event.collisionDirection);
    } else if (aLastFrameMoved == bLastFrameMoved) {
        revertPosition(entityA, aEntities);
        zeroOutVelocity(entityA, event.collisionDirection);
        revertPosition(entityB, bEntities);
        zeroOutVelocity(entityB, event.collisionDirection);
    } else {
        revertPosition(entityB, bEntities);
        zeroOutVelocity(entityB, event.collisionDirection);
    }

}

std::set<Entity> CollisionHandleSystem::getChildEntities(const Entity& entity) {
    try {
        auto& childrenComponent = ecsManager->getComponentFromEntity<TiedChildComponent>(entity);
        return childrenComponent.entities;
    } catch (...) {
        return {};
    }
}

void CollisionHandleSystem::revertPosition(const Entity& entity, const std::set<Entity>& childEntities) {
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

void CollisionHandleSystem::zeroOutVelocity(Entity entity, CollisionDirection collisionDirection) {
    if (!ecsManager->hasComponent<VelocityComponent>(entity)) {
        return;
    }

    auto& velocity = ecsManager->getComponentFromEntity<VelocityComponent>(entity).velocity;

    switch (collisionDirection) {
        case CollisionDirection::UP:
                if (velocity.yVelocity > 0) {
                    velocity.yVelocity = 0;
                }
        break;
        case CollisionDirection::DOWN:
                if (velocity.yVelocity < 0) {
                    velocity.yVelocity = 0;
                }
        break;
        case CollisionDirection::LEFT:
                if (velocity.xVelocity > 0) {
                    velocity.xVelocity = 0;
                }
        break;
        case CollisionDirection::RIGHT:
                if (velocity.xVelocity < 0) {
                    velocity.xVelocity = 0;
                }
        break;
        default:
            break;
    }
}

