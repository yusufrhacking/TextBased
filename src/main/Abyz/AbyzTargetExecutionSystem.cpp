#include "AbyzTargetExecutionSystem.h"

#include "PlainAbyzPrefab.h"
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

bool AbyzTargetExecutionSystem::isJourneyCompleted(JourneyComponent& journeyComponent, EntitySize abyzSize) {
    return abs(journeyComponent.totalXTraveled) >= (abs(journeyComponent.goalXChange)-abyzSize.width) &&
           abs(journeyComponent.totalYTraveled) >= (abs(journeyComponent.goalYChange)-abyzSize.height);
}

void AbyzTargetExecutionSystem::update(double deltaTime) {
    for(auto abyz: getRelevantEntities()) {
        auto& positionComponent = ecsManager->getComponentFromEntity<PositionComponent>(abyz);
        auto& journeyComponent = ecsManager->getComponentFromEntity<JourneyComponent>(abyz);
        const auto& abyzSize = ecsManager->getComponentFromEntity<TextComponent>(abyz).getSurfaceSize();

        double xChange = journeyComponent.velocity.x * deltaTime;
        double yChange = journeyComponent.velocity.y * deltaTime;

        positionComponent.shiftPosition(xChange, yChange);

        journeyComponent.totalXTraveled += xChange;
        journeyComponent.totalYTraveled += yChange;
        if (isJourneyCompleted(journeyComponent, abyzSize)) {
            const auto& targetComponent = ecsManager->getComponentFromEntity<AbyzTargetingComponent>(abyz);
            ecsManager->killEntity(targetComponent.target);
            ecsManager->killEntity(abyz);
        }
        //
        // const auto& abyzSize = ecsManager->getComponentFromEntity<TextComponent>(abyz).getSurfaceSize();
        // const auto& abyzPosition = positionComponent.getPosition();
        //
        //
        //
        // Entity target = targetComponent.target;
        //
        // auto& secondPosition = ecsManager->getComponentFromEntity<PositionComponent>(target);
        // auto& secondText = ecsManager->getComponentFromEntity<TextComponent>(target);
        //
        // bool isAABBCollision = DistanceCalculator::checkAABBCollision(abyzPosition, abyzSize,
        //                                          secondPosition.getPosition(), secondText.getSurfaceSize());
        //
        // if (isAABBCollision) {
        //
        // }
         //JourneyComponent says how far to go + how fast --> this is generated from some cool entity calculations when the jit is created
        // multiply that stuff by delta time to figure out how far to send this time, and then if the journey is done
        //remove live component from the stored, targeted entity and add it to the Abyz's pouch or something
        //this is the next step
    }
}
