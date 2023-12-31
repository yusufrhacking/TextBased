#ifndef ABYZPRIORITIZINGSYSTEM_H
#define ABYZPRIORITIZINGSYSTEM_H
#include "../ECSObjects/UpdateSystem.h"


class AbyzPrioritizingSystem: public UpdateSystem {
public:
    AbyzPrioritizingSystem();
    void update(double deltaTime) override;
};



#endif //ABYZPRIORITIZINGSYSTEM_H
