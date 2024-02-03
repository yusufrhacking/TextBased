#ifndef LIFEGATESYSTEM_H
#define LIFEGATESYSTEM_H
#include "../ECSObjects/UpdateSystem.h"


class LifeGateSystem: public UpdateSystem {
public:
    LifeGateSystem();
    void update(double deltaTime) override;
};



#endif //LIFEGATESYSTEM_H
