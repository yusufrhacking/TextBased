#ifndef TEXTBASED_COMPONENTMANAGER_H
#define TEXTBASED_COMPONENTMANAGER_H


#include "../Objects/Entity.h"

class ComponentManager {
private:

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


#endif //TEXTBASED_COMPONENTMANAGER_H
