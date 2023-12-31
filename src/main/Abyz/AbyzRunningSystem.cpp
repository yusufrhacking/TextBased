#include "AbyzRunningSystem.h"

#include "AbyzPrefab.h"
#include "AbyzTargetComponent.h"
#include "../PositionsAndMovement/LiveComponent.h"
#include "../PositionsAndMovement/PositionComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;

AbyzRunningSystem::AbyzRunningSystem() {
    requireComponent<AbyzTargetComponent>();
    requireComponent<PositionComponent>();
    requireComponent<LiveComponent>();
    requireComponent<TextComponent>();
}

void AbyzRunningSystem::update(double deltaTime) {
    for(auto entity: getRelevantEntities()) {
        auto position = ecsManager->getComponentFromEntity<PositionComponent>(entity).getPosition();
        AbyzPrefab{position + Position(0, 400)};
        ecsManager->removeComponentFromEntity<AbyzTargetComponent>(entity);
    }
}
