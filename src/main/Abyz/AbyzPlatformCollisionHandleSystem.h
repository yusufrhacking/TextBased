#ifndef ABYZPLATFORMCOLLISIONHANDLESYSTEM_H
#define ABYZPLATFORMCOLLISIONHANDLESYSTEM_H

#include "../ECSObjects/System.h"
#include "../PositionsAndMovement/RightLeftCollisionEvent.h"
#include "../PositionsAndMovement/TopBottomCollisionEvent.h"


class AbyzPlatformCollisionHandleSystem: public System {
public:
    AbyzPlatformCollisionHandleSystem();

    void onRightLeftCollision(RightLeftCollisionEvent& event);

    void listenToEvents();
    void onTopBottomCollision(TopBottomCollisionEvent& event);
};



#endif //ABYZPLATFORMCOLLISIONHANDLESYSTEM_H
