#ifndef TEXTBASED_DYNAMICRENDERSYSTEM_H
#define TEXTBASED_DYNAMICRENDERSYSTEM_H

#include "../ECSObjects/System.h"
#include "../Camera/Camera.h"
#include "Renderer.h"

class DynamicRenderSystem: public System{
public:
    virtual void render(const std::shared_ptr<Renderer>& renderer, Camera camera) = 0;
};

#endif //TEXTBASED_DYNAMICRENDERSYSTEM_H
