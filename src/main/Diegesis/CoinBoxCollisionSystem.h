#ifndef TEXTBASED_COINBOXCOLLISIONSYSTEM_H
#define TEXTBASED_COINBOXCOLLISIONSYSTEM_H

#include "../ECSObjects/System.h"
#include "../PositionsAndMovement/RightLeftCollisionEvent.h"
#include "../PositionsAndMovement/TopBottomCollisionEvent.h"



class CoinBoxCollisionSystem: public System {
public:
    CoinBoxCollisionSystem();

    void listenToEvents();

    void onTopBottomCollision(TopBottomCollisionEvent& event);

    void createCoin(Entity boxEntity);
};


#endif //TEXTBASED_COINBOXCOLLISIONSYSTEM_H
