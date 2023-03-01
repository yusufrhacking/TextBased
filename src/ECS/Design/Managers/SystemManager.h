#ifndef TEXTBASED_SYSTEMMANAGER_H
#define TEXTBASED_SYSTEMMANAGER_H


#include "../Objects/Entity.h"

class SystemManager {

    template <typename TSystem, typename ... TArgs>
    void addSystem(TArgs&& ... args);

    template <typename TSystem>
    void removeSystem();

    template <typename TSystem>
    bool hasSystem() const;

    template <typename TSystem>
    TSystem& getSystem() const;

    void addEntityToSystems(Entity entity);
};


#endif //TEXTBASED_SYSTEMMANAGER_H
