#ifndef TEXTBASED_AUTONOMOUSMOVEMENTSYSTEM_H
#define TEXTBASED_AUTONOMOUSMOVEMENTSYSTEM_H

#include "PositionComponent.h"
#include "MovementComponent.h"
#include "../HighLevel/ECSManager.h"
#include "../ECSObjects/UpdateSystem.h"


class VelocitySystem: public UpdateSystem{
    public:
        explicit VelocitySystem();


        void update(double deltaTime) override;
};


#endif //TEXTBASED_AUTONOMOUSMOVEMENTSYSTEM_H
