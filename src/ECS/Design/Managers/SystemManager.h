#ifndef TEXTBASED_SYSTEMMANAGER_H
#define TEXTBASED_SYSTEMMANAGER_H
#include <typeindex>

#include "../Objects/Entity.h"
#include "../Objects/System.h"

using SystemsMap = std::unordered_map<std::type_index, std::shared_ptr<System>>;


class SystemManager {
private:
    SystemsMap systems;

    bool signaturesMatch(const ComponentSignature &entityComponentSignature,
                         const ComponentSignature &systemComponentSignature) ;

public:

    template <typename TSystem, typename ... TArgs>
    void addSystem(TArgs&& ... args);

    template <typename TSystem>
    void removeSystem();

    template <typename TSystem>
    bool hasSystem() const;

    template <typename TSystem>
    TSystem& getSystem() const;

    void addEntityToSystems(Entity entity, ComponentSignature entitySignature);
};

template<typename TSystem, typename... TArgs>
void SystemManager::addSystem(TArgs &&... args) {
    std::shared_ptr<TSystem> newSystem = std::make_shared<TSystem>(std::forward<TArgs>(args)...);
    systems.insert(std::make_pair(
            std::type_index(typeid(TSystem)),//The key in this case is the type of System, as a num
            newSystem));//THIS IS HARAM
}

template<typename TSystem>
void SystemManager::removeSystem() {
    auto systemToRemove = systems.find(std::type_index(typeid(TSystem)));
    systems.erase(systemToRemove);
}

template<typename TSystem>
bool SystemManager::hasSystem() const {
    return systems.find(std::type_index(typeid(TSystem))) != systems.end();
    // If the systems map does not find the system, it will return the "end"
    // So, if the systems map find result is not the "end", then it contains it
}

template<typename TSystem>
TSystem& SystemManager::getSystem() const {
    auto systemToReturn = systems.find(std::type_index(typeid(TSystem)));
    return *(std::static_pointer_cast<TSystem>(systemToReturn->second));
}


#endif //TEXTBASED_SYSTEMMANAGER_H
