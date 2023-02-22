#ifndef TEXTBASED_ENTITYMANAGER_H
#define TEXTBASED_ENTITYMANAGER_H

#include <bitset>

#include "../Objects/Entity.h"
#include "../Objects/System.h"

typedef std::bitset<MAX_COMPONENTS> ComponentSignature;

class EntityManager {

private:
    int numOfEntities = 0;
    std::vector<Entity> entitiesToBeAdded;
    std::vector<Entity> entitiesToBeRemoved;

public:
    Entity createEntity();

    int getNumOfEntities() const;

    std::vector<Entity> getEntitiesToBeAdded();

    std::vector<Entity> getEntitiesToBeRemoved();

};


#endif //TEXTBASED_ENTITYMANAGER_H
