#ifndef TEXTBASED_SYSTEM_H
#define TEXTBASED_SYSTEM_H
#include <bitset>
#include <vector>
#include "Entity.h"
#include "Component.h"

const unsigned int NUM_OF_COMPONENTS = 64;

typedef std::bitset<NUM_OF_COMPONENTS> ComponentSignature;

//The system works on components with specific signatures
class System {
private:
    ComponentSignature componentSignature;
    std::vector<Entity> entities;

public:
    System() = default;
    virtual ~System() = default;

    void addEntity(Entity entity);
    void removeEntity(Entity entity);
    std::vector<Entity> getEntities(Entity entity) const;
    ComponentSignature getComponentSignature() const;

    //Templates should be implemented in the header file
    template <typename ComponentGeneric> void requireComponent();
};

template <typename ComponentGeneric>
void System::requireComponent() {
    const auto componentId = Component<ComponentGeneric>::getId();
    componentSignature.set(componentId);
}


#endif //TEXTBASED_SYSTEM_H
