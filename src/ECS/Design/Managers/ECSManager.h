#ifndef TEXTBASED_ECSMANAGER_H
#define TEXTBASED_ECSMANAGER_H
#include <vector>
#include <bitset>
#include <set>
#include "../Objects/Pool.h"
#include "../Objects/System.h"
#include <unordered_map>
#include <typeindex>
#include "../Objects/Entity.h"


typedef std::vector<std::shared_ptr<GenericPool>> ComponentPoolsArr;
typedef std::bitset<NUM_OF_COMPONENTS> ComponentSignature;
typedef std::unordered_map<std::type_index, std::shared_ptr<System>> SystemsMap;


class ECSManager {
private:
    int numOfEntities = 0;

    ComponentPoolsArr componentPools;
    std::vector<ComponentSignature> entityComponentSignatures;
    std::vector<Entity> entitiesToBeAdded;
    std::vector<Entity> entitiesToBeKilled;
    SystemsMap systems;

    ECSManager() {
        spdlog::info("ECS manager constructed");
    }

public:

    static ECSManager& getInstance(){
        static ECSManager theInstance;
        return theInstance;
    }

    ~ECSManager() {
        spdlog::info("ECS manager destroyed");
    }

    //Refactor in an Entity manager class
    Entity createEntity();

    void update();

    //Refactor in a componentManager class
    template <typename TComponent, typename ...TArgs>
    void addComponentToEntity(Entity entity, TArgs&& ... args);

    template <typename T>
    void removeComponent(Entity entity);

    template <typename T>
    bool hasComponent(Entity entity);

    template <typename TComponent>
    TComponent& getComponent(Entity entity) const;

    template <typename TSystem, typename ... TArgs>
    void addSystem(TArgs&& ... args);

    template <typename TSystem>
    void removeSystem();

    template <typename TSystem>
    bool hasSystem() const;

    template <typename TSystem>
    TSystem& getSystem() const;

    void addEntityToSystems(Entity entity);


private:
    bool isComponentUnitialized(int componentId);

    bool isComponentPoolsResizeNeeded(int componentId) const;

    template<typename TComponent>
    std::shared_ptr<Pool<TComponent>> getValidPool(int componentId, int entityId);


    bool signaturesMatch(const std::bitset<64> &entityComponentSignature,
                    const ComponentSignature &systemComponentSignature) const;
};

template <typename TComponent, typename ...TArgs>
void ECSManager::addComponentToEntity(Entity entity, TArgs &&...args) {
    const int componentId = Component<TComponent>::getId();
    const int entityId = entity.getId();

    std::shared_ptr<Pool<TComponent>> componentPool = getValidPool<TComponent>(componentId, entityId);

    TComponent newComponent(std::forward<TArgs>(args)...);

    componentPool->set(entityId, newComponent);

    entityComponentSignatures[entityId].set(componentId);

    spdlog::info("Component " + std::to_string(componentId) + " was added to Entity " + std::to_string(entityId));
}

template<typename TComponent>
std::shared_ptr<Pool<TComponent>> ECSManager::getValidPool(const int componentId, const int entityId) {
    if (isComponentPoolsResizeNeeded(componentId)){
        componentPools.resize(componentId + 1, nullptr);
    }

    if (isComponentUnitialized(componentId)){
        auto newComponentPool = std::make_shared<Pool<TComponent>>();
        componentPools[componentId] = newComponentPool;
    }

    std::shared_ptr<Pool<TComponent>> componentPool = std::static_pointer_cast<Pool<TComponent>>(componentPools[componentId]);

    if (entityId >= componentPool->getSize()){
        componentPool->resize(numOfEntities);
    }
    return componentPool;
}

template <typename TComponent>
void ECSManager::removeComponent(Entity entity){
    const int componentId = Component<TComponent>::getId();
    const int entityId = entity.getId();

    entityComponentSignatures[entityId].set(componentId, false);
}

template <typename TComponent>
bool ECSManager::hasComponent(Entity entity){
    const int componentId = Component<TComponent>::getId();
    const int entityId = entity.getId();

    return entityComponentSignatures[entityId].test(componentId);
}

template <typename TComponent>
TComponent& ECSManager::getComponent(Entity entity) const {
    const auto componentId = Component<TComponent>::getId();
    const auto entityId = entity.getId();
    auto componentPool = std::static_pointer_cast<Pool<TComponent>>(componentPools[componentId]);
    return componentPool->get(entityId);
}

template<typename TSystem, typename... TArgs>
void ECSManager::addSystem(TArgs &&... args) {
    std::shared_ptr<TSystem> newSystem = std::make_shared<TSystem>(std::forward<TArgs>(args)...);
    systems.insert(std::make_pair(
            std::type_index(typeid(TSystem)),//The key in this case is the type of System, as a num
            newSystem));//THIS IS HARAM
}

template<typename TSystem>
void ECSManager::removeSystem() {
    auto systemToRemove = systems.find(std::type_index(typeid(TSystem)));
    systems.erase(systemToRemove);
}

template<typename TSystem>
bool ECSManager::hasSystem() const {
    return systems.find(std::type_index(typeid(TSystem))) != systems.end();
    // If the systems map does not find the system, it will return the "end"
    // So, if the systems map find result is not the "end", then it contains it
}

template<typename TSystem>
TSystem& ECSManager::getSystem() const {
    std::shared_ptr<TSystem> systemToReturn = systems.find(std::type_index(typeid(TSystem)));
    return *(std::static_pointer_cast<TSystem>(systemToReturn->second));
}
//MAKE EVENTUALLY
//std::type_index ECSManager::getKeyIndex(TSystem?) const {
//
//}


#endif
