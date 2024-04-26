#ifndef TEXTBASED_PROPOSITIONRENDERSYSTEM_H
#define TEXTBASED_PROPOSITIONRENDERSYSTEM_H
#include "../Rendering/DynamicRenderSystem.h"


class PropositionRenderSystem: public DynamicRenderSystem  {
public:
    PropositionRenderSystem();
    void render(const std::shared_ptr<Renderer>& renderer, Camera camera) override;

};


#endif //TEXTBASED_PROPOSITIONRENDERSYSTEM_H
