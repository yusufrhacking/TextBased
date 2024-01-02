#ifndef ABYZEXECUTIONSYSTEM_H
#define ABYZEXECUTIONSYSTEM_H
#include "JourneyComponent.h"
#include "../ECSObjects/UpdateSystem.h"



class AbyzTargetExecutionSystem: public UpdateSystem {
public:
    AbyzTargetExecutionSystem();

    bool isJourneyCompleted(JourneyComponent&journeyComponent, EntitySize abyzSize);

    void update(double deltaTime) override;
};



#endif //ABYZEXECUTIONSYSTEM_H
