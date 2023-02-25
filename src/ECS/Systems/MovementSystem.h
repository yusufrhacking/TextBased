#ifndef TEXTBASED_MOVEMENTSYSTEM_H
#define TEXTBASED_MOVEMENTSYSTEM_H

#include "../Design/Objects/System.h"
#include "../Components/PositionComponent.h"
#include "../Components/MovementComponent.h"
#include "../Design/Managers/ECSManager.h"

class MovementSystem: public System{
public:
    ECSManager& manager;

    explicit MovementSystem(ECSManager &manager);


    void update();
};


#endif //TEXTBASED_MOVEMENTSYSTEM_H
