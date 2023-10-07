#ifndef TEXTBASED_ABYZCONTROLSYSTEM_H
#define TEXTBASED_ABYZCONTROLSYSTEM_H


#include "../ECSObjects/UpdateSystem.h"
#include "AbyzComponent.h"
#include "../PositionsAndMovement/PositionComponent.h"


class AbyzControlSystem: public UpdateSystem {

public:
    AbyzControlSystem();
    void update(double deltaTime) override;

    void chase(AbyzComponent &abyz, const Position &playerPosition, const Position &currentPosition);

    void tryToAttackPlayer(AbyzComponent &abyz, Entity abyzEntity, Entity mainPlayer);
};


#endif //TEXTBASED_ABYZCONTROLSYSTEM_H
