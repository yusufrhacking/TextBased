#ifndef SPAWNABYZSYSTEM_H
#define SPAWNABYZSYSTEM_H
#include "../ECSObjects/UpdateSystem.h"

class SpawnAbyzSystem: public UpdateSystem {
public:
    SpawnAbyzSystem();
    void update(double deltaTime) override;
};



#endif //SPAWNABYZSYSTEM_H
