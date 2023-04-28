#ifndef TEXTBASED_RENDERER_H
#define TEXTBASED_RENDERER_H


#include "../../../ECS/Components/TextComponent.h"
#include "../../../ECS/Components/StyleComponent.h"

class Renderer {
    public:
        virtual ~Renderer() = default;
        virtual void renderText(const std::shared_ptr<Position>& position, const TextComponent& sprite, const StyleComponent& style) = 0;
        virtual void renderFrame() = 0;

};



#endif //TEXTBASED_RENDERER_H
