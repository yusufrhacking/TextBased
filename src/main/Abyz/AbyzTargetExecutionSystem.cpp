#include "AbyzTargetExecutionSystem.h"

#include "AbyzPrefab.h"
#include "AbyzTargetingComponent.h"
#include "JourneyComponent.h"
#include "../PositionsAndMovement/DistanceCalculator.h"
#include "../PositionsAndMovement/LiveComponent.h"
#include "../PositionsAndMovement/PositionComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;

AbyzTargetExecutionSystem::AbyzTargetExecutionSystem() {
    requireComponent<AbyzTargetingComponent>();
    requireComponent<PositionComponent>();
    requireComponent<LiveComponent>();
    requireComponent<TextComponent>();
    requireComponent<AbyzComponent>();
    requireComponent<JourneyComponent>();
}

void AbyzTargetExecutionSystem::update(double deltaTime) {
    for(auto abyz: getRelevantEntities()) {
        auto& positionComponent = ecsManager->getComponentFromEntity<PositionComponent>(abyz);
        const auto& journeyComponent = ecsManager->getComponentFromEntity<JourneyComponent>(abyz);

        double xChange = journeyComponent.velocity.xVelocity * deltaTime;
        double yChange = journeyComponent.velocity.yVelocity * deltaTime;

        positionComponent.shiftPosition(xChange, yChange);

        const auto& abyzSize = ecsManager->getComponentFromEntity<TextComponent>(abyz).getSurfaceSize();
        const auto& abyzPosition = positionComponent.getPosition();

        auto targetComponent = ecsManager->getComponentFromEntity<AbyzTargetingComponent>(abyz);

        auto& secondPosition = ecsManager->getComponentFromEntity<PositionComponent>(targetComponent.target);
        auto& secondText = ecsManager->getComponentFromEntity<TextComponent>(targetComponent.target);

        bool isAABCollision = DistanceCalculator::checkAABBCollision(abyzPosition, abyzSize,
                                                 secondPosition.getPosition(), secondText.getSurfaceSize());
         //JourneyComponent says how far to go + how fast --> this is generated from some cool entity calculations when the jit is created
        // multiply that stuff by delta time to figure out how far to send this time, and then if the journey is done
        //remove live component from the stored, targeted entity and add it to the Abyz's pouch or something
        //this is the next step
    }
}
