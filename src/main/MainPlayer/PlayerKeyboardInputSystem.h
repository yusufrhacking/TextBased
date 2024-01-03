#ifndef TEXTBASED_PLAYERKEYBOARDINPUTSYSTEM_H
#define TEXTBASED_PLAYERKEYBOARDINPUTSYSTEM_H
#include "KeyboardMovementComponent.h"
#include "../HighLevel/ECSManager.h"
#include "../ECSObjects/EventConsumerSystem.h"
#include "../TextInput/GameKeyEvent.h"


class PlayerKeyboardInputSystem: public EventConsumerSystem {
private:
    void onKeyPressed(GameKeyEvent& event);
public:
    explicit PlayerKeyboardInputSystem();

};


#endif //TEXTBASED_PLAYERKEYBOARDINPUTSYSTEM_H
