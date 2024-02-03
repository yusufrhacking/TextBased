#ifndef SUPREMEPOWERRENDERSYSTEM_H
#define SUPREMEPOWERRENDERSYSTEM_H

#include "../Rendering/DynamicRenderSystem.h"


class SupremePowerRenderSystem: public DynamicRenderSystem {
public:
    explicit SupremePowerRenderSystem();

    void render(const std::shared_ptr<Renderer>& renderer, Camera camera) override;
};



#endif //SUPREMEPOWERRENDERSYSTEM_H
