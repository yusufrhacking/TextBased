#ifndef SPAWNABYZSYSTEM_H
#define SPAWNABYZSYSTEM_H
#include "../ECSObjects/UpdateSystem.h"

class SpawnAbyzSystem: public UpdateSystem {
    float currentWaitingTimeMilliseconds = 2000;
public:
    SpawnAbyzSystem();

    void spawnAbyz(std::set<Entity>::value_type entity);

    void update(double deltaTime) override;
};



#endif //SPAWNABYZSYSTEM_H
