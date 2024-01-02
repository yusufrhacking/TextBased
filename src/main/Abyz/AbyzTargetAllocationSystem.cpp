#include "AbyzTargetingSystem.h"

#include "AbyzPrefab.h"
#include "AbyzTargetingComponent.h"
#include "JourneyComponent.h"
#include "PriorityTargetComponent.h"
#include "../PositionsAndMovement/LiveComponent.h"
#include "../PositionsAndMovement/PositionComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;

AbyzTargetingSystem::AbyzTargetingSystem() {
    requireComponent<PriorityTargetComponent>();
    requireComponent<PositionComponent>();
    requireComponent<LiveComponent>();
    requireComponent<TextComponent>();
}

void AbyzTargetingSystem::update(double deltaTime) {
    for(auto target: getRelevantEntities()) {
        auto targetPosition = ecsManager->getComponentFromEntity<PositionComponent>(target).getPosition();


        Entity abyz = ecsManager->createEntity();
        ecsManager->addComponentToEntity<TextComponent>(abyz, "Abyz");
        ecsManager->addComponentToEntity<PositionComponent>(abyz, targetPosition + Position(0, 400));
        ecsManager->addComponentToEntity<LiveComponent>(abyz);
        ecsManager->addComponentToEntity<AbyzComponent>(abyz);
        ecsManager->addComponentToEntity<AbyzTargetingComponent>(abyz, AbyzTargetingComponent(target));

        JourneyComponent journeyComponent{Velocity(MONACO_HEIGHT_OF_A_LINE_OF_TEXT, MONACO_RENDERED_TEXT_WIDTH_SCALER), 0, 400};
        ecsManager->addComponentToEntity<JourneyComponent>(abyz, journeyComponent);


        ecsManager->removeComponentFromEntity<PriorityTargetComponent>(target);
    }
}
