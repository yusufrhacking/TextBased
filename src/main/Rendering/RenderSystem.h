#ifndef TEXTBASED_RENDERSYSTEM_H
#define TEXTBASED_RENDERSYSTEM_H

#include "Renderer.h"
#include "../ECS/Design/Objects/System.h"
#include "../Positioning/PositionComponent.h"
#include "../Text/TextComponent.h"
#include "StyleComponent.h"
#include "../../Game/GameSystems/Camera/Camera.h"

class RenderSystem: public System {
    public:
        explicit RenderSystem();

        void render(const std::shared_ptr<Renderer>& renderer, Camera camera);

    private:
};


#endif //TEXTBASED_RENDERSYSTEM_H
