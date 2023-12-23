#ifndef TEXTBASED_ENTITYRENDERSYSTEM_H
#define TEXTBASED_ENTITYRENDERSYSTEM_H
#include "DynamicRenderSystem.h"
#include "Renderer.h"
#include "../Text/TextComponent.h"
#include "GenericStyleComponent.h"
#include "../ECSObjects/System.h"

class EntityRenderSystem: public DynamicRenderSystem {
    public:
        explicit EntityRenderSystem();

        void render(const std::shared_ptr<Renderer>& renderer, Camera camera) override;

    private:
};


#endif //TEXTBASED_ENTITYRENDERSYSTEM_H
