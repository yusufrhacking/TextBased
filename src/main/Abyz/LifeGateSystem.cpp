#include "LifeGateSystem.h"

#include "LifeGateComponent.h"
#include "../HighLevel/ECSManager.h"
#include "../PositionsAndMovement/PositionComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;


LifeGateSystem::LifeGateSystem() {
    requireComponent<LifeGateComponent>();
    requireComponent<PositionComponent>();
}

void LifeGateSystem::update(double deltaTime) {
    for(auto entity: getRelevantEntities()) {
        auto position = ecsManager->getComponentFromEntity<PositionComponent>(entity).getPosition();
        auto lifeGate = ecsManager->getComponentFromEntity<LifeGateComponent>(entity);
        if(position.y > lifeGate.mustBeAboveYPos) {
            ecsManager->killEntity(entity);
        }
    }
}
