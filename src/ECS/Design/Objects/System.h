#ifndef TEXTBASED_SYSTEM_H
#define TEXTBASED_SYSTEM_H
#include <bitset>
#include <set>
#include "Entity.h"
#include "Component.h"
#include "../../../Globals.h"


class System {
private:
    ComponentSignature componentSignature;
    std::set<Entity> entities;

public:
    System() = default;
    virtual ~System() = default;

    void addEntity(Entity entity);
    void removeEntity(Entity entity);
    std::set<Entity> getEntities() const;
    ComponentSignature getComponentSignature() const;

    virtual void update(double deltaTime) = 0;

    template <typename ComponentGeneric> void requireComponent();
};

template <typename TComponent>
void System::requireComponent() {
    const auto componentId = Component<TComponent>::getId();
    componentSignature.set(componentId);
}


#endif //TEXTBASED_SYSTEM_H
