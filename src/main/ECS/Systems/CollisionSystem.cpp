#include "CollisionSystem.h"

extern std::unique_ptr<ECSManager> ecsManager;

void CollisionSystem::update(double deltaTime) {

    for (Entity entity: getReleventEntities()){
        auto& position = ecsManager->getComponent<PositionComponent>(entity);
        auto& collider = ecsManager->getComponent<ColliderComponent>(entity);
    }
}

void CollisionSystem::aabbCollision(PositionComponent position, ColliderComponent collider) {


}
