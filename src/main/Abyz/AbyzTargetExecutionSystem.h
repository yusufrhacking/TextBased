#ifndef ABYZEXECUTIONSYSTEM_H
#define ABYZEXECUTIONSYSTEM_H
#include "../ECSObjects/UpdateSystem.h"



class AbyzTargetExecutionSystem: public UpdateSystem {
public:
    AbyzTargetExecutionSystem();
    void update(double deltaTime) override;
};



#endif //ABYZEXECUTIONSYSTEM_H
