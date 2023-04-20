#ifndef TEXTBASED_COMPONENTMANAGER_H
#define TEXTBASED_COMPONENTMANAGER_H


#include "../Objects/Entity.h"
#include "../Objects/Component.h"
#include "../Objects/Pool.h"
#include "../../../Globals.h"
#include <bitset>
#include <stdexcept>

using ComponentPoolsArr = std::vector<std::shared_ptr<GenericPool>>;

class ComponentManager {
    private:
        ComponentPoolsArr componentPools;
        std::vector<ComponentSignature> entityComponentSignatures;

        template<typename TComponent>
        std::shared_ptr<Pool<TComponent>> getValidPool(int componentId, int entityId);

        [[nodiscard]] bool isComponentPoolsResizeNeeded(int componentId) const;

        [[nodiscard]] bool isComponentUninitialized(int componentId);




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

    if (entityId >= entityComponentSignatures.size()){
        entityComponentSignatures.resize(entityId * 2 + 1);
    }

    entityComponentSignatures[entityId].set(componentId);

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
        componentPool->resize(componentPool->getSize() + 1);
    }
    return componentPool;
}

template <typename TComponent>
void ComponentManager::removeComponent(Entity entity){
    const int componentId = Component<TComponent>::getId();
    const int entityId = entity.getId();

    bool isComponentPresent = entityComponentSignatures[entityId].test(componentId);

    if (!isComponentPresent){
        throw std::runtime_error("Entity does not have requested component to remove");
    }

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
    bool isComponentPresent = entityComponentSignatures[entityId].test(componentId);

    if (!isComponentPresent){
        throw std::runtime_error("Entity does not have requested component to remove");
    }

    return componentPool->get(entityId);
}

#endif
