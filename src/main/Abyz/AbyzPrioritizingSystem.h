#ifndef ABYZPRIORITIZINGSYSTEM_H
#define ABYZPRIORITIZINGSYSTEM_H
#include "../ECSObjects/UpdateSystem.h"


class AbyzPrioritizingSystem: public UpdateSystem {
    std::chrono::steady_clock::time_point lastUpdateTime;
    int workDelayMilliseconds = 50;
public:
    AbyzPrioritizingSystem();
    void update(double deltaTime) override;
};



#endif //ABYZPRIORITIZINGSYSTEM_H
