#ifndef TEXTBASED_ABYZCONTROLSYSTEM_H
#define TEXTBASED_ABYZCONTROLSYSTEM_H


#include "../ECSObjects/UpdateSystem.h"
#include "AbyzComponent.h"


class AbyzControlSystem: public UpdateSystem {

public:
    AbyzControlSystem();
    void update(double deltaTime) override;

    void chase(AbyzComponent &abyz, const Position &playerPosition, const Position &currentPosition);
};


#endif //TEXTBASED_ABYZCONTROLSYSTEM_H
