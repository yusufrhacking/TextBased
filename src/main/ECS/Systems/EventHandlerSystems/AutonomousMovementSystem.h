#ifndef TEXTBASED_AUTONOMOUSMOVEMENTSYSTEM_H
#define TEXTBASED_AUTONOMOUSMOVEMENTSYSTEM_H

#include "../../Design/Objects/System.h"
#include "../../Components/PositionComponent.h"
#include "../../Components/MovementComponent.h"
#include "../../Design/Managers/ECSManager.h"
#include "../UpdateSystems/UpdateSystem.h"


class AutonomousMovementSystem: public UpdateSystem{
    public:
        explicit AutonomousMovementSystem();


        void update(double deltaTime) override;
};


#endif //TEXTBASED_AUTONOMOUSMOVEMENTSYSTEM_H
