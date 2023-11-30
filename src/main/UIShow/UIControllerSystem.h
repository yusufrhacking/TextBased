#ifndef UICONTROLLERSYSTEM_H
#define UICONTROLLERSYSTEM_H
#include "HideUIEvent.h"
#include "ShowUIEvent.h"
#include "../ECSObjects/System.h"


class UIControllerSystem: public System {
public:
    UIControllerSystem();
private:
    void listenToEvents();
    void onHideEvent(HideUIEvent& event);
    void onShowEvent(ShowUIEvent& event);
};



#endif //UICONTROLLERSYSTEM_H
