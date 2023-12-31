#ifndef ABYZRENDERINGSYSTEM_H
#define ABYZRENDERINGSYSTEM_H
#include "../Rendering/DynamicRenderSystem.h"


class AbyzRenderingSystem: public DynamicRenderSystem {
public:
    AbyzRenderingSystem();
    void render(const std::shared_ptr<Renderer>& renderer, Camera camera) override;
};



#endif //ABYZRENDERINGSYSTEM_H
