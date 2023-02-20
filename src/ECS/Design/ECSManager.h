#ifndef TEXTBASED_ECSMANAGER_H
#define TEXTBASED_ECSMANAGER_H
#include <vector>
#include <bitset>
#include <set>
#include "Group.h"
#include "System.h"
#include <unordered_map>
#include <typeindex>
#include "Entity.h"

typedef std::vector<GenericGroup*> GroupList;
typedef std::bitset<NUM_OF_COMPONENTS> ComponentSignature;
typedef std::unordered_map<std::type_index, System*> systems;


class ECSManager {
private:
    int numOfEntities = 0;

    GroupList componentGroups;
    std::vector<ComponentSignature> entityComponentSignatures;
    std::vector<Entity> entitiesToBeAdded;
    std::vector<Entity> entitiesToBeKilled;

public:
    ECSManager() = default;

    Entity createEntity();

    void Update();

    void addEntityToSystem(Entity entity);
};


#endif
