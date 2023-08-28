#ifndef TEXTBASED_ECSMANAGER_H
#define TEXTBASED_ECSMANAGER_H
#include <memory>
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
#include "../../../Game/GameSystems/Camera/Camera.h"


class ECSManager {
    private:
        std::shared_ptr<EntityManager> entityManager;
        std::shared_ptr<ComponentManager> componentManager;
        std::shared_ptr<SystemManager> systemManager;
        Camera currentCamera = Camera(Position());

public:
        ECSManager();

        ~ECSManager() = default;

        Entity createEntity();
        void killEntity(Entity entity);


        void removeDeadEntities();
        std::vector<Entity> addNewEntities();

        void runFirstSystems() const;
        void runTimedSystems(double deltaTime) const;
        void runCameraSystem();

        void render(std::shared_ptr<Renderer> renderer);


        template <typename TComponent>
        bool hasComponent(Entity entity) const;

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

    void removeEntity(const Entity &entity);
};

template<typename TComponent>
bool ECSManager::hasComponent(Entity entity) const {
    return componentManager->hasComponent<TComponent>(entity);
}

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
