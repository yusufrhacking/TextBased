#ifndef TEXTBASED_RENDERCONTROLLERSYSTEM_H
#define TEXTBASED_RENDERCONTROLLERSYSTEM_H


#include "Renderer.h"
#include "../ECSObjects/System.h"

class RenderControllerSystem: public System {
public:
    RenderControllerSystem() = default;
    void render(const std::shared_ptr<Renderer>& renderer, Camera camera);
};


#endif //TEXTBASED_RENDERCONTROLLERSYSTEM_H
