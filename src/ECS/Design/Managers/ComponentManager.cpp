#include "ComponentManager.h"



bool ComponentManager::isComponentPoolsResizeNeeded(const int componentId) const { return componentId >= componentPools.size(); }

bool ComponentManager::isComponentUninitialized(const int componentId) { return !componentPools[componentId]; }