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
#include "EntityManager.h"
#include "ComponentManager.h"
#include "SystemManager.h"
#include "../../../GameSystems/Renderer/Renderer.h"
#include "../../Systems/RenderSystem.h"


//using ComponentPoolsArr = std::vector<std::shared_ptr<GenericPool>>;
//using ComponentSignature = std::bitset<NUM_OF_COMPONENTS>;
//using SystemsMap = std::unordered_map<std::type_index, std::shared_ptr<System>>;


class ECSManager {
private:
//    int numOfEntities = 0;
//
//    ComponentPoolsArr componentPools;
//    std::vector<ComponentSignature> entityComponentSignatures;
//
//    std::vector<Entity> entitiesToBeAdded;
//    std::vector<Entity> entitiesToBeKilled;
//
//    SystemsMap systems;

    std::unique_ptr<EntityManager> entityManager;
    std::unique_ptr<ComponentManager> componentManager;
    std::unique_ptr<SystemManager> systemManager;

//


public:
//
//    static ECSManager& getInstance(){
//        static ECSManager theInstance;
//        return theInstance;
//    }

    ECSManager() {
        entityManager = std::make_unique<EntityManager>();
        componentManager = std::make_unique<ComponentManager>();
        systemManager = std::make_unique<SystemManager>();
        spdlog::debug("ECS manager constructed");
    }

    ~ECSManager() {
        spdlog::debug("ECS manager destroyed");
    }

    Entity createEntity();

    void update(double deltaTime);

    void render(std::shared_ptr<Renderer> renderer);


    //Refactor in a componentManager class
    template <typename TComponent, typename... TArgs>
    void addComponentToEntity(Entity entity, TArgs &&...args);

    template <typename T>
    void removeComponent(Entity entity);


    template <typename TComponent>
    TComponent& getComponent(Entity entity) const;

    template <typename TSystem, typename... TArgs>
    void addSystem(TArgs &&...args);

    template <typename TSystem>
    void removeSystem();

    template <typename TSystem>
    bool hasSystem() const;

    template <typename TSystem>
    TSystem& getSystem() const;

    void addNewEntities();

    void updateSystems(double deltaTime) const;

};

template <typename TComponent, typename... TArgs>
void ECSManager::addComponentToEntity(Entity entity, TArgs &&...args) {
    int componentId = Component<TComponent>::getId();

    componentManager->addComponentToEntity<TComponent>(entity, std::forward<TArgs>(args)...);

    auto signature = entityManager->getSignature(entity);
    signature.set(componentId, true);
    entityManager->setSignature(entity, signature);

    systemManager->updateEntityInSystems(entity, signature);
    spdlog::debug("Component " + std::to_string(componentId) + " was added to Entity " + std::to_string(entity.getId()));
}

template <typename TComponent>
void ECSManager::removeComponent(Entity entity){
    int componentId = Component<TComponent>::getId();

    componentManager->removeComponent<TComponent>(entity);

    auto signature = entityManager->getSignature(entity);
    signature.set(componentId, false);
    entityManager->setSignature(entity, signature);

    systemManager->updateEntityInSystems(entity, signature);
}

template <typename TComponent>
TComponent& ECSManager::getComponent(Entity entity) const {
    return componentManager->getComponent<TComponent>(entity);
}

template<typename TSystem, typename... TArgs>
void ECSManager::addSystem(TArgs &&... args) {
    systemManager->addSystem<TSystem>(std::forward<TArgs>(args)...);
}

template<typename TSystem>
void ECSManager::removeSystem() {
    systemManager->template removeSystem<TSystem>();
}

template<typename TSystem>
bool ECSManager::hasSystem() const {
    return systemManager->template hasSystem<TSystem>();
}

template<typename TSystem>
TSystem& ECSManager::getSystem() const {
    systemManager->getSystem<TSystem>();
}


#endif
