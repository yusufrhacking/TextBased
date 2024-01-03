#include <spdlog/spdlog.h>
#include "VelocitySystem.h"
#include "CollisionCheckSystem.h"
#include "LiveComponent.h"
#include "VelocityComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;

VelocitySystem::VelocitySystem(){
    requireComponent<PositionComponent>();
    requireComponent<VelocityComponent>();
    requireComponent<LiveComponent>();
}

void VelocitySystem::update(double deltaTime) {
    for (Entity entity: getRelevantEntities()){
        auto& position = ecsManager->getComponentFromEntity<PositionComponent>(entity);
        const auto movement = ecsManager->getComponentFromEntity<VelocityComponent>(entity);

        double xChange = movement.velocity.x * deltaTime;
        double yChange = movement.velocity.y * deltaTime;

        position.shiftPosition(xChange, yChange);
        spdlog::trace("Entity {} moved {}, {} to {}, {}", entity.getId(), xChange, yChange, position.getPosition().x, position.getPosition().y);
    }
}

