#ifndef JUMPINGCOMPONENT_H
#define JUMPINGCOMPONENT_H

struct JumpingComponent {
    float jumpHeight;
    JumpingComponent() = default;
    explicit JumpingComponent(float jumpHeight): jumpHeight(jumpHeight){}
};

#endif //JUMPINGCOMPONENT_H
