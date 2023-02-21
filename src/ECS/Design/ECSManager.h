#ifndef TEXTBASED_ECSMANAGER_H
#define TEXTBASED_ECSMANAGER_H
#include <vector>
#include <bitset>
#include <set>
#include "Pool.h"
#include "System.h"
#include <unordered_map>
#include <typeindex>
#include "Entity.h"

typedef std::vector<GenericPool*> ComponentPoolsArr;
typedef std::bitset<NUM_OF_COMPONENTS> ComponentSignature;
typedef std::unordered_map<std::type_index, System*> systems;


class ECSManager {
private:
    int numOfEntities = 0;

    ComponentPoolsArr componentPools;
    std::vector<ComponentSignature> entityComponentSignatures;
    std::vector<Entity> entitiesToBeAdded;
    std::vector<Entity> entitiesToBeKilled;

public:
    ECSManager() = default;

    Entity createEntity();

    void Update();

    void addEntityToSystem(Entity entity);

    template <typename TComponent, typename ...TArgs>
    void addComponent(Entity entity, TArgs&& ... args);
private:
    bool isComponentUnitialized(const int componentId);

    bool isComponentPoolsResizeNeeded(const int componentId) const;
};

template <typename TComponent, typename ...TArgs>
void ECSManager::addComponent(Entity entity, TArgs &&...args) {
    const int componentId = Component<TComponent>::getId();
    const int entityId = entity.getId();

    if (isComponentPoolsResizeNeeded(componentId)){
        componentPools.resize(componentId + 1, nullptr);
    }

    if (isComponentUnitialized(componentId)){
        auto newComponentPool = new Pool<TComponent>();
        componentPools[componentId] = newComponentPool;
    }

    Pool<TComponent>* componentPool = componentPools[componentId];

    if (entityId >= componentPool->getSize()){
        componentPool->resize(numOfEntities);
    }

    TComponent newComponent(std::forward<TArgs>(args)...);

    componentPool->set(entityId, newComponent);

    entityComponentSignatures[entityId].set(componentId);

}

bool ECSManager::isComponentPoolsResizeNeeded(const int componentId) const { return componentId >= componentPools.size(); }

bool ECSManager::isComponentUnitialized(const int componentId) { return !componentPools[componentId]; }

#endif
