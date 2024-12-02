#ifndef RIGHTLEFTMOVEMENTSYSTEM_H
#define RIGHTLEFTMOVEMENTSYSTEM_H
#include "../ECSObjects/UpdateSystem.h"
#include "../TextInput/GameKeyEvent.h"
#include "../PositionsAndMovement/Velocity.h"

enum class MoveDirection {
    LEFT = -1,
    RIGHT = 1
};

struct RightLeftShift {
    Entity entity;
    int intDirection;

    RightLeftShift(Entity entity, MoveDirection direction): entity(entity) {
        switch (direction) {
            case MoveDirection::LEFT:
                intDirection = -1; break;
            case MoveDirection::RIGHT:
                intDirection = 1; break;
        }
    }
};

class RightLeftMovementSystem: public UpdateSystem {
    void onKeyPressed(GameKeyEvent& event);
    std::vector<RightLeftShift> moves{};
public:
    RightLeftMovementSystem();
    void update(double deltaTime) override;
};



#endif //RIGHTLEFTMOVEMENTSYSTEM_H
