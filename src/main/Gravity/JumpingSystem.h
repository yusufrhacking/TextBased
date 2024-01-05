#ifndef JUMPINGSYSTEM_H
#define JUMPINGSYSTEM_H
#include "../ECSObjects/System.h"
#include "../TextInput/GameKeyEvent.h"
#include "../PositionsAndMovement/Velocity.h"

struct EntityJump {
    Entity entity;
    Velocity jump;

    EntityJump(Entity entity, Velocity shift): entity(entity), jump(shift){}
};

class JumpingSystem: public System {
    void onKeyPressed(GameKeyEvent& event);
    std::vector<EntityJump> jumps{};
public:
    JumpingSystem();
    void update();

};



#endif //JUMPINGSYSTEM_H
