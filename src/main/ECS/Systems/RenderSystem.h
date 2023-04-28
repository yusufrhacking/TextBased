#ifndef TEXTBASED_RENDERSYSTEM_H
#define TEXTBASED_RENDERSYSTEM_H

#include "../../Game/GameSystems/Renderer/Renderer.h"
#include "../Design/Objects/System.h"
#include "../Components/PositionComponent.h"
#include "../Components/TextComponent.h"
#include "../Components/StyleComponent.h"

class RenderSystem: public System {
    public:
        explicit RenderSystem();

        void render(const std::shared_ptr<Renderer>& renderer);

    private:
};


#endif //TEXTBASED_RENDERSYSTEM_H
