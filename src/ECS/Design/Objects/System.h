#ifndef TEXTBASED_SYSTEM_H
#define TEXTBASED_SYSTEM_H
#include <bitset>
#include <set>
#include "Entity.h"
#include "Component.h"
#include "../../../Constants.h"

using ComponentSignature =  std::bitset<NUM_OF_COMPONENTS>;

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

    template <typename ComponentGeneric> void requireComponent();
};

template <typename TComponent>
void System::requireComponent() {
    const auto componentId = Component<TComponent>::getId();
    componentSignature.set(componentId);
}


#endif //TEXTBASED_SYSTEM_H
