#include "CollisionSystem.h"

extern std::unique_ptr<ECSManager> ecsManager;

void CollisionSystem::update(double deltaTime) {

    for (Entity entity: getReleventEntities()){
        auto& position = ecsManager->getComponentFromEntity<PositionComponent>(entity);
        auto& collider = ecsManager->getComponentFromEntity<ColliderComponent>(entity);
    }
}

void CollisionSystem::aabbCollision(PositionComponent position, ColliderComponent collider) {


}
