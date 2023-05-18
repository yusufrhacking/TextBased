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
#include "../../../Game/GameSystems/Renderer/Renderer.h"
#include "../../Systems/RenderSystem.h"
#include "../../Systems/UpdateSystems/UpdateSystem.h"
#include "../../../Helpers/EventSystem/EventBus/EventBus.h"

class ECSManager {
    private:
        std::shared_ptr<EntityManager> entityManager;
        std::shared_ptr<ComponentManager> componentManager;
        std::shared_ptr<SystemManager> systemManager;
        std::shared_ptr<EventBus> eventBus;
        void removeDeadEntities();
        void addNewEntities();
        void runUpdateSystems(double deltaTime) const;
        void runEventProducerSystems();

public:
        ECSManager() {
            entityManager = std::make_shared<EntityManager>();
            componentManager = std::make_shared<ComponentManager>();
            systemManager = std::make_shared<SystemManager>();
            eventBus = std::make_shared<EventBus>();
        }

        ~ECSManager() = default;

        Entity createEntity();
        void killEntity(Entity entity);

        void update(double deltaTime);

        void render(std::shared_ptr<Renderer> renderer);

        void setup();

        template <typename TComponent, typename... TArgs>
        void addComponentToEntity(Entity entity, TArgs &&...args);

        template <typename T>
        void removeComponentFromEntity(Entity entity);

        template <typename TComponent>
        TComponent& getComponentFromEntity(Entity entity) const;

        template <typename TSystem, typename... TArgs>
        void addSystem(TArgs &&...args);

        template <typename TSystem>
        void removeSystem();

        template <typename TSystem>
        bool hasSystem() const;

        template <typename TSystem>
        TSystem& getSystem() const;

};

template <typename TComponent, typename... TArgs>
void ECSManager::addComponentToEntity(Entity entity, TArgs &&...args) {
    int componentId = Component<TComponent>::getId();

    componentManager->addComponentToEntity<TComponent>(entity, std::forward<TArgs>(args)...);

    auto signature = entityManager->getSignature(entity);
    signature.set(componentId, true);
    entityManager->setSignature(entity, signature);

    systemManager->updateEntityInSystems(entity, signature);
}

template <typename TComponent>
void ECSManager::removeComponentFromEntity(Entity entity){
    int componentId = Component<TComponent>::getId();

    componentManager->removeComponent<TComponent>(entity);

    auto signature = entityManager->getSignature(entity);
    signature.set(componentId, false);
    entityManager->setSignature(entity, signature);

    systemManager->updateEntityInSystems(entity, signature);
}

template <typename TComponent>
TComponent& ECSManager::getComponentFromEntity(Entity entity) const {
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
    return systemManager->getSystem<TSystem>();
}


#endif
