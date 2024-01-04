#ifndef JUMPINGCOMPONENT_H
#define JUMPINGCOMPONENT_H

struct JumpingComponent {
    float jumpHeight;
    bool onGround = false;
    JumpingComponent() = default;
    explicit JumpingComponent(float jumpHeight): jumpHeight(jumpHeight){}
};

#endif //JUMPINGCOMPONENT_H
