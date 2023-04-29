#include "ComponentManager.h"

bool ComponentManager::isComponentPoolsResizeNeeded(const int componentId) const { return componentId >= componentPools.size(); }

bool ComponentManager::isComponentUninitialized(const int componentId) { return !componentPools[componentId]; }

void ComponentManager::clearEntity(Entity entity) {
    entityComponentSignatures[entity.getId()].reset();
}
