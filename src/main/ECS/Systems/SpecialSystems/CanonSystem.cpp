#include "CanonSystem.h"
#include "../../Components/PositionComponent.h"
#include "../../Design/Managers/ECSManager.h"

extern std::unique_ptr<ECSManager> ecsManager;

CanonSystem::CanonSystem(Canon &canon) : canon(canon) {
    requireComponent<PositionComponent>();
}

void CanonSystem::placeAllEntities(){
    for (auto entity : getRelevantEntities()){
        placeEntity(entity);
    }
}

void CanonSystem::placeEntity(Entity entity){
    auto mapPosition = ecsManager->getComponentFromEntity<PositionComponent>(entity).getMapPosition();
    canon.placeEntity(entity, mapPosition);
}

void CanonSystem::update() {
    for (auto entity : getRelevantEntities()){
        auto mapPosition = ecsManager->getComponentFromEntity<PositionComponent>(entity).getMapPosition();

        canon.removeEntity(entity);

        canon.ensurePageExists(mapPosition);
        canon.placeEntity(entity, mapPosition);
    }
}

void CanonSystem::placeEntities(std::vector<Entity> entities) {
    for (auto entity : entities){
        placeEntity(entity);
    }
}
