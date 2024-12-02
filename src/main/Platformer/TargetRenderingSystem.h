#ifndef TARGETRENDERINGSYSTEM_H
#define TARGETRENDERINGSYSTEM_H
#include "../Rendering/DynamicRenderSystem.h"

class TargetRenderingSystem: public DynamicRenderSystem  {
public:
    explicit TargetRenderingSystem();

    void render(const std::shared_ptr<Renderer>& renderer, Camera camera) override;
};



#endif //TARGETRENDERINGSYSTEM_H
