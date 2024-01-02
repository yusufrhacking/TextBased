#ifndef ABYZRUNNINGSYSTEM_H
#define ABYZRUNNINGSYSTEM_H
#include "../ECSObjects/UpdateSystem.h"


class AbyzTargetAllocationSystem: public UpdateSystem {
public:
    AbyzTargetAllocationSystem();
    void update(double deltaTime) override;
};



#endif //ABYZRUNNINGSYSTEM_H
