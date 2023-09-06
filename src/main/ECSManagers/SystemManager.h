#ifndef TEXTBASED_SYSTEMMANAGER_H
#define TEXTBASED_SYSTEMMANAGER_H
#include <memory>
#include <typeindex>
#include <unordered_map>
#include <vector>
#include "../ECSObjects/Entity.h"
#include "../ECSObjects/ComponentSignature.h"
#include "../ECSObjects/System.h"

using SystemsMap = std::unordered_map<std::type_index, std::shared_ptr<System>>;

class SystemManager {
    private:
        SystemsMap systems;

    public:
        template <typename TSystem, typename ... TArgs>
        void addSystem(TArgs&& ... args);

        template <typename TSystem>
        void removeSystem();

        template <typename TSystem>
        bool hasSystem() const;

        template <typename TSystem>
        TSystem& getSystem() const;

        template <typename TSystem>
        std::vector<std::shared_ptr<TSystem>> getSystemsOfType() const;

        void updateEntityInSystems(Entity entity, ComponentSignature entitySignature);

        void addNewEntityToSystem(Entity entity, ComponentSignature entitySignature);

};

template<typename TSystem, typename... TArgs>
void SystemManager::addSystem(TArgs &&... args) {
    std::shared_ptr<TSystem> newSystem = std::make_shared<TSystem>(std::forward<TArgs>(args)...);
    systems.insert(std::make_pair(
            std::type_index(typeid(TSystem)),
            newSystem));
}

template<typename TSystem>
void SystemManager::removeSystem() {
    auto systemToRemove = systems.find(std::type_index(typeid(TSystem)));
    systems.erase(systemToRemove);
}

template<typename TSystem>
bool SystemManager::hasSystem() const {
    return systems.find(std::type_index(typeid(TSystem))) != systems.end();
}

template<typename TSystem>
TSystem& SystemManager::getSystem() const {
    auto systemToReturn = systems.find(std::type_index(typeid(TSystem)));
    return *(std::static_pointer_cast<TSystem>(systemToReturn->second));
}

template<typename TSystem>
std::vector<std::shared_ptr<TSystem>> SystemManager::getSystemsOfType() const {
    std::vector<std::shared_ptr<TSystem>> systemsOfType;

    for (const auto& systemKeyPair : systems){
        auto system = systemKeyPair.second;

        auto isSystemOfType = dynamic_pointer_cast<TSystem>(system);

        if (isSystemOfType){
            systemsOfType.push_back(std::static_pointer_cast<TSystem>(system));
        }
    }
    return systemsOfType;
}


#endif
