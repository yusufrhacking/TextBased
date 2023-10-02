#ifndef TEXTBASED_PENDINGDEATHSYSTEM_H
#define TEXTBASED_PENDINGDEATHSYSTEM_H


#include "../ECSObjects/UpdateSystem.h"

class PendingDeathSystem: public UpdateSystem {
public:
    PendingDeathSystem();
    void update(double deltaTime) override;
};


#endif //TEXTBASED_PENDINGDEATHSYSTEM_H
