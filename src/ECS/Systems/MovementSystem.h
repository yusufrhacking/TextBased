#ifndef TEXTBASED_MOVEMENTSYSTEM_H
#define TEXTBASED_MOVEMENTSYSTEM_H

#include "../Design/Objects/System.h"
#include "../Components/TransformComponent.h"
#include "../Components/MovementComponent.h"
#include "../Design/Managers/ECSManager.h"
#include "UpdateSystem.h"


class MovementSystem: public UpdateSystem{
public:

    explicit MovementSystem();


    void update(double deltaTime) override;
};


#endif //TEXTBASED_MOVEMENTSYSTEM_H
