#ifndef TEXTBASED_PLAYERKEYBOARDINPUTSYSTEM_H
#define TEXTBASED_PLAYERKEYBOARDINPUTSYSTEM_H
#include "../../Components/MainPlayerComponent.h"
#include "../../Components/MovementComponent.h"
#include "../../Components/PositionComponent.h"
#include "../../Design/Managers/ECSManager.h"
#include "EventConsumerSystem.h"
#include "../../../Helpers/EventSystem/Events/KeyEvent.h"


class PlayerKeyboardInputSystem: public EventConsumerSystem {
private:
    void onKeyPressed(KeyEvent& event);
public:
    explicit PlayerKeyboardInputSystem();

};


#endif //TEXTBASED_PLAYERKEYBOARDINPUTSYSTEM_H