#include "MovementSystem.h"

void MovementSystem::Update() {
    // Loop all entities the system cares about
    for (Entity entity: getEntities()){
        auto& component1 = manager.getComponent<PositionComponent>(entity);
    }
}

MovementSystem::MovementSystem(ECSManager &manager) : manager(manager) {
    requireComponent<PositionComponent>();
    requireComponent<MovementComponent>();
    manager = ECSManager::getInstance();
    //requireComponent<PositionComponent>();

}
