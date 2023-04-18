#ifndef TEXTBASED_COLLIDERCOMPONENT_H
#define TEXTBASED_COLLIDERCOMPONENT_H
#include "../../Objects/Size.h"

struct ColliderComponent{
    RenderedVal width;
    RenderedVal height;

    explicit ColliderComponent(Size surfaceSize){
        this->width = surfaceSize.width;
        this->height = surfaceSize.height;
    }

    explicit ColliderComponent(int width = 0, int height = 0){
        this->width = width;
        this->height = height;
    }
};

#endif
