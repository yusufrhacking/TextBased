#include "CanonRegisteringSystem.h"
#include "../HighLevel/ECSManager.h"
#include "../PositionsAndMovement/PositionComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;

CanonRegisteringSystem::CanonRegisteringSystem(Canon &canon) : canon(canon) {
    requireComponent<PositionComponent>();
}

void CanonRegisteringSystem::placeAllEntities(){
    for (auto entity : getRelevantEntities()){
        placeEntity(entity);
    }
}

void CanonRegisteringSystem::placeEntity(Entity entity){
    auto mapPosition = ecsManager->getComponentFromEntity<PositionComponent>(entity).getMapPosition();
    canon.placeEntity(entity, mapPosition);
}

void CanonRegisteringSystem::update() {
    for (auto entity : getRelevantEntities()){
        auto mapPosition = ecsManager->getComponentFromEntity<PositionComponent>(entity).getMapPosition();

        canon.removeEntity(entity);

        canon.ensurePageExists(mapPosition);
        canon.placeEntity(entity, mapPosition);
    }
}

void CanonRegisteringSystem::placeEntities(std::vector<Entity> entities) {
    for (auto entity : entities){
        if (ecsManager->hasComponent<PositionComponent>(entity)){
            auto mapPosition = ecsManager->getComponentFromEntity<PositionComponent>(entity).getMapPosition();
            canon.ensurePageExists(mapPosition);
            placeEntity(entity);
        }
    }
}
