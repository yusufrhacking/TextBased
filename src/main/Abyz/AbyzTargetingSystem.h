#ifndef ABYZRUNNINGSYSTEM_H
#define ABYZRUNNINGSYSTEM_H
#include "../ECSObjects/UpdateSystem.h"


class AbyzTargetingSystem: public UpdateSystem {
public:
    AbyzTargetingSystem();
    void update(double deltaTime) override;
};



#endif //ABYZRUNNINGSYSTEM_H
