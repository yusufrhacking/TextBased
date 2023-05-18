#ifndef TEXTBASED_COLLIDERCOMPONENT_H
#define TEXTBASED_COLLIDERCOMPONENT_H
#include "../../Helpers/Objects/Size.h"

struct ColliderComponent{
    RenderedVal widthCollisionRange;
    RenderedVal heightCollisionRange;

    explicit ColliderComponent(Size surfaceSize){
        this->widthCollisionRange = surfaceSize.width;
        this->heightCollisionRange = surfaceSize.height;
    }

    explicit ColliderComponent(int width = 0, int height = 0){
        this->widthCollisionRange = width;
        this->heightCollisionRange = height;
    }
};

#endif
