#ifndef TEXTBASED_PLAYERKEYBOARDINPUTSYSTEM_H
#define TEXTBASED_PLAYERKEYBOARDINPUTSYSTEM_H
#include "MainPlayerComponent.h"
#include "../../../Positioning/MovementComponent.h"
#include "../../../Positioning/PositionComponent.h"
#include "../HighLevel/ECSManager.h"
#include "../ECSObjects/EventConsumerSystem.h"
#include "../../../Helpers/EventSystem/Events/GameKeyEvent.h"


class PlayerKeyboardInputSystem: public EventConsumerSystem {
private:
    void onKeyPressed(GameKeyEvent& event);
public:
    explicit PlayerKeyboardInputSystem();

};


#endif //TEXTBASED_PLAYERKEYBOARDINPUTSYSTEM_H
