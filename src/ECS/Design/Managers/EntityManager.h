#ifndef TEXTBASED_ENTITYMANAGER_H
#define TEXTBASED_ENTITYMANAGER_H


#include "../Objects/Entity.h"

class EntityManager {
private:
    int numOfEntities = 0;
    std::vector<Entity> entitiesToBeAdded;
    std::vector<Entity> entitiesToBeKilled;

public:
    int getNumOfEntities();
    Entity createEntity();
    std::vector<Entity> getEntitiesToBeAdded();
    std::vector<Entity> getEntitiesToBeKilled();



};


#endif //TEXTBASED_ENTITYMANAGER_H
