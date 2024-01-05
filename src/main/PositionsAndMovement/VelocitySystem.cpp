#include <spdlog/spdlog.h>
#include "VelocitySystem.h"
#include "CollisionCheckSystem.h"
#include "LiveComponent.h"
#include "VelocityComponent.h"
#include "../MainPlayer/UnprocessedMovementSystem.h"

extern std::unique_ptr<ECSManager> ecsManager;

VelocitySystem::VelocitySystem(){
    requireComponent<PositionComponent>();
    requireComponent<VelocityComponent>();
    requireComponent<LiveComponent>();
}

void VelocitySystem::update(double deltaTime) {
    for (Entity entity: getRelevantEntities()){
        auto& position = ecsManager->getComponentFromEntity<PositionComponent>(entity);
        const auto velocity = ecsManager->getComponentFromEntity<VelocityComponent>(entity).velocity;

        double xChange = velocity.x * deltaTime;
        double yChange = velocity.y * deltaTime;

        spdlog::info("Velocity! {}, {}", velocity.x, velocity.y);
        if (velocity.y < 0) {
            spdlog::info("Changes: {}, {}", xChange, yChange);
            spdlog::info("Curr Position: {}, {}", position.getPosition().x, position.getPosition().y);
        }

        ecsManager->getSystem<UnprocessedMovementSystem>().queueMovement(UnprocessedMovement(entity, xChange, yChange));

        // position.shiftPosition(xChange, yChange);
        // spdlog::trace("Entity {} moved {}, {} to {}, {}", entity.getId(), xChange, yChange, position.getPosition().x, position.getPosition().y);
    }
}

