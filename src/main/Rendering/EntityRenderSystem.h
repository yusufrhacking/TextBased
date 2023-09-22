#ifndef TEXTBASED_ENTITYRENDERSYSTEM_H
#define TEXTBASED_ENTITYRENDERSYSTEM_H
#include "Renderer.h"
#include "../Text/TextComponent.h"
#include "StyleComponent.h"
#include "../ECSObjects/System.h"
#include "RenderSystem.h"

class EntityRenderSystem: public RenderSystem {
    public:
        explicit EntityRenderSystem();

        void render(const std::shared_ptr<Renderer>& renderer, Camera camera) override;

    private:
};


#endif //TEXTBASED_ENTITYRENDERSYSTEM_H
