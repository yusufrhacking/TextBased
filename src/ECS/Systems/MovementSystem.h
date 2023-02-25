#ifndef TEXTBASED_MOVEMENTSYSTEM_H
#define TEXTBASED_MOVEMENTSYSTEM_H

#include "../Design/Objects/System.h"
#include "../Components/PositionComponent.h"
#include "../Components/MovementComponent.h"

class MovementSystem: public System{
public:
    MovementSystem(){
        requireComponent<PositionComponent>();
        requireComponent<MovementComponent>();
        //requireComponent<PositionComponent>();
    }

    void Update() {
        // Loop all entities the system cares about
        for (Entity entity: getEntities()){

        }
    }
};


#endif //TEXTBASED_MOVEMENTSYSTEM_H
