#ifndef TEXTBASED_COLLISIONEVENT_H
#define TEXTBASED_COLLISIONEVENT_H

#include "../EventSystem/Event.h"
#include "DistanceCalculator.h"

class CollisionEvent: public Event{
public:
    Entity a;
    Entity b;
    double deltaTime;
    CollisionAxis collisionAxis;
    CollisionDirection collisionDirection;
    // CollisionEvent(Entity a, Entity b, double deltaTime):
    //         a(a), b(b), deltaTime(deltaTime) {collisionAxis = CollisionAxis::NONE; collisionDirection = CollisionDirection::NONE;}
    // CollisionEvent(Entity a, Entity b, double deltaTime, CollisionAxis collisionAxis):
    //         a(a), b(b), deltaTime(deltaTime), collisionAxis(collisionAxis) {collisionDirection = CollisionDirection::NONE;}
    CollisionEvent(Entity a, Entity b, double deltaTime, CollisionAxis collisionAxis, CollisionDirection collisionDirection):
            a(a), b(b), deltaTime(deltaTime), collisionAxis(collisionAxis), collisionDirection(collisionDirection) {}
};

#endif //TEXTBASED_COLLISIONEVENT_H
