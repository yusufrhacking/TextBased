#ifndef TEXTBASED_RENDERSYSTEM_H
#define TEXTBASED_RENDERSYSTEM_H

#include "../ECSObjects/System.h"
#include "../Camera/Camera.h"
#include "Renderer.h"

class RenderSystem: public System{
public:
    virtual void render(const std::shared_ptr<Renderer>& renderer, Camera camera) = 0;
};

#endif //TEXTBASED_RENDERSYSTEM_H
