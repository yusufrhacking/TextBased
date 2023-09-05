#ifndef TEXTBASED_AUTONOMOUSMOVEMENTSYSTEM_H
#define TEXTBASED_AUTONOMOUSMOVEMENTSYSTEM_H

#include "../../Design/Objects/System.h"
#include "PositionComponent.h"
#include "MovementComponent.h"
#include "../HighLevel/ECSManager.h"
#include "../ECSObjects/UpdateSystem.h"


class AutonomousMovementSystem: public UpdateSystem{
    public:
        explicit AutonomousMovementSystem();


        void update(double deltaTime) override;
};


#endif //TEXTBASED_AUTONOMOUSMOVEMENTSYSTEM_H
