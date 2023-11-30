#ifndef UICONTROLLERSYSTEM_H
#define UICONTROLLERSYSTEM_H
#include "HideUIEvent.h"
#include "../ECSObjects/System.h"


class UIControllerSystem: public System {
public:
    UIControllerSystem();
private:
    void listenToEvents();
    void onUIEvent(HideUIEvent& event);
};



#endif //UICONTROLLERSYSTEM_H
