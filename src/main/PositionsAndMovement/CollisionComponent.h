#ifndef TEXTBASED_COLLISIONCOMPONENT_H
#define TEXTBASED_COLLISIONCOMPONENT_H
#include "Size.h"

struct CollisionComponent{
    RenderedVal widthCollisionRange;
    RenderedVal heightCollisionRange;

    explicit CollisionComponent(Size surfaceSize){
        this->widthCollisionRange = surfaceSize.width;
        this->heightCollisionRange = surfaceSize.height;
    }

    explicit CollisionComponent(int width = 0, int height = 0){
        this->widthCollisionRange = width;
        this->heightCollisionRange = height;
    }
};

#endif
