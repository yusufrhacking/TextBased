#ifndef JUMPINGCOMPONENT_H
#define JUMPINGCOMPONENT_H

struct JumpingComponent {
    float jumpSpeed;
    bool onGround = false;
    JumpingComponent() = default;
    explicit JumpingComponent(float jumpHeight): jumpSpeed(jumpHeight){}
};

#endif //JUMPINGCOMPONENT_H
