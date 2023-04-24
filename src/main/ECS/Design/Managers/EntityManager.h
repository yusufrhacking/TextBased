#ifndef TEXTBASED_ENTITYMANAGER_H
#define TEXTBASED_ENTITYMANAGER_H
#include <queue>
#include <vector>
#include <array>
#include "../Objects/Entity.h"
#include "../../../Globals.h"

class EntityManager {
    private:
        int numOfEntities = 0;
        std::vector<Entity> entitiesToBeAdded;
        std::vector<Entity> entitiesToBeRemoved;
        std::array<ComponentSignature, MAX_ENTITIES> signatures;
        std::priority_queue<int, std::vector<int>, std::greater<>> freedEntityIDs;

public:
        [[nodiscard]] int getNumOfEntities() const;
        Entity createEntity();
        void killEntity(Entity entity);
        std::vector<Entity> getEntitiesToBeAdded();
        std::vector<Entity> getEntitiesToBeKilled();
        ComponentSignature getSignature(Entity entity);
        void setSignature(Entity entity, ComponentSignature signature);
        void clearEntitiesToBeAdded();
        void clearEntitiesToBeRemoved();
        void freeEntityID(int id);

};


#endif
