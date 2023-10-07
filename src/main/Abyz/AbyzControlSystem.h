#ifndef TEXTBASED_ABYZCONTROLSYSTEM_H
#define TEXTBASED_ABYZCONTROLSYSTEM_H


#include "../ECSObjects/UpdateSystem.h"



class AbyzControlSystem: public UpdateSystem {

public:
    AbyzControlSystem();
    void update(double deltaTime) override;
};


#endif //TEXTBASED_ABYZCONTROLSYSTEM_H
