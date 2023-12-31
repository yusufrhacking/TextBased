#ifndef ABYZRUNNINGSYSTEM_H
#define ABYZRUNNINGSYSTEM_H
#include "../ECSObjects/UpdateSystem.h"


class AbyzRunningSystem: public UpdateSystem {
public:
    AbyzRunningSystem();
    void update(double deltaTime) override;
};



#endif //ABYZRUNNINGSYSTEM_H
