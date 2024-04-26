#ifndef TEXTBASED_PROPOSITIONRENDERSYSTEM_H
#define TEXTBASED_PROPOSITIONRENDERSYSTEM_H
#include "../Rendering/DynamicRenderSystem.h"
#include "PropositionComponent.h"


class PropositionRenderSystem: public DynamicRenderSystem  {
public:
    PropositionRenderSystem();
    void render(const std::shared_ptr<Renderer>& renderer, Camera camera) override;

    GenericStyleComponent getStyleFromProposition(const PropositionComponent &component);
};


#endif //TEXTBASED_PROPOSITIONRENDERSYSTEM_H
