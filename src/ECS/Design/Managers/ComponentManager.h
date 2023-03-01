#ifndef TEXTBASED_COMPONENTMANAGER_H
#define TEXTBASED_COMPONENTMANAGER_H


#include "../Objects/Entity.h"
#include "../Objects/Component.h"
#include "../Objects/Pool.h"
#include "../../../Constants.h"
#include <bitset>

using ComponentPoolsArr = std::vector<std::shared_ptr<GenericPool>>;
using ComponentSignature = std::bitset<NUM_OF_COMPONENTS>;


class ComponentManager {
private:
    ComponentPoolsArr componentPools;
    std::vector<ComponentSignature> entityComponentSignatures;

    template<typename TComponent>
    std::shared_ptr<Pool<TComponent>> getValidPool(int componentId, int entityId);

    bool isComponentPoolsResizeNeeded(int componentId) const;

    bool isComponentUninitialized(int componentId);




public:
    template <typename TComponent, typename ...TArgs>
    void addComponentToEntity(Entity entity, TArgs&& ... args);

    template <typename T>
    void removeComponent(Entity entity);

    template <typename T>
    bool hasComponent(Entity entity);

    template <typename TComponent>
    TComponent& getComponent(Entity entity) const;
};

template <typename TComponent, typename ...TArgs>
void ComponentManager::addComponentToEntity(Entity entity, TArgs &&...args) {
    const int componentId = Component<TComponent>::getId();
    const int entityId = entity.getId();

    std::shared_ptr<Pool<TComponent>> componentPool = getValidPool<TComponent>(componentId, entityId);

    TComponent newComponent(std::forward<TArgs>(args)...);

    componentPool->set(entityId, newComponent);

    entityComponentSignatures[entityId].set(componentId);

    spdlog::info("Component " + std::to_string(componentId) + " was added to Entity " + std::to_string(entityId));
}

template<typename TComponent>
std::shared_ptr<Pool<TComponent>> ComponentManager::getValidPool(const int componentId, const int entityId) {
    if (isComponentPoolsResizeNeeded(componentId)){
        componentPools.resize(componentId + 1, nullptr);
    }

    if (isComponentUninitialized(componentId)){
        auto newComponentPool = std::make_shared<Pool<TComponent>>();
        componentPools[componentId] = newComponentPool;
    }

    std::shared_ptr<Pool<TComponent>> componentPool = std::static_pointer_cast<Pool<TComponent>>(componentPools[componentId]);

    if (entityId >= componentPool->getSize()){
        componentPool->resize(componentPool->getSize() * 2);
    }
    return componentPool;
}

template <typename TComponent>
void ComponentManager::removeComponent(Entity entity){
    const int componentId = Component<TComponent>::getId();
    const int entityId = entity.getId();

    entityComponentSignatures[entityId].set(componentId, false);
}

template <typename TComponent>
bool ComponentManager::hasComponent(Entity entity){
    const int componentId = Component<TComponent>::getId();
    const int entityId = entity.getId();

    return entityComponentSignatures[entityId].test(componentId);
}

template <typename TComponent>
TComponent& ComponentManager::getComponent(Entity entity) const {
    const auto componentId = Component<TComponent>::getId();
    const auto entityId = entity.getId();
    auto componentPool = std::static_pointer_cast<Pool<TComponent>>(componentPools[componentId]);
    return componentPool->get(entityId);
}

bool ComponentManager::isComponentPoolsResizeNeeded(const int componentId) const { return componentId >= componentPools.size(); }

bool ComponentManager::isComponentUninitialized(const int componentId) { return !componentPools[componentId]; }




#endif //TEXTBASED_COMPONENTMANAGER_H
