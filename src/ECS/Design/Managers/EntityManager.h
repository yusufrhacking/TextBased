#ifndef TEXTBASED_ENTITYMANAGER_H
#define TEXTBASED_ENTITYMANAGER_H


#include "../Objects/Entity.h"
#include "../../../Globals.h"

class EntityManager {
private:
    int numOfEntities = 0;
    std::vector<Entity> entitiesToBeAdded;
    std::vector<Entity> entitiesToBeKilled;
    std::array<ComponentSignature, MAX_ENTITIES> signatures;

public:
    int getNumOfEntities() const;
    Entity createEntity();
    std::vector<Entity> getEntitiesToBeAdded();
    std::vector<Entity> getEntitiesToBeKilled();
    ComponentSignature getSignature(Entity entity);
    void setSignature(Entity entity, ComponentSignature signature);
    void clearEntitiesToBeAdded();
    void clearEntitiesToBeKilled();

};


#endif //TEXTBASED_ENTITYMANAGER_H
