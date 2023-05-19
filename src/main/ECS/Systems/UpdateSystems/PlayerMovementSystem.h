#ifndef TEXTBASED_PLAYERMOVEMENTSYSTEM_H
#define TEXTBASED_PLAYERMOVEMENTSYSTEM_H
#include "../../Components/PlayerMovementComponent.h"
#include "../../Components/MovementComponent.h"
#include "../../Components/PositionComponent.h"
#include "../../Design/Managers/ECSManager.h"
#include "../EventHandlerSystems/EventConsumerSystem.h"
#include "../../../Helpers/EventSystem/Events/KeyEvent.h"


class PlayerMovementSystem: public EventConsumerSystem {
private:
    void onKeyPressed(KeyEvent& event);
public:
    explicit PlayerMovementSystem();


};


#endif //TEXTBASED_PLAYERMOVEMENTSYSTEM_H
