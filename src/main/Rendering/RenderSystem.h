#ifndef TEXTBASED_RENDERSYSTEM_H
#define TEXTBASED_RENDERSYSTEM_H
#include "Renderer.h"
#include "../Text/TextComponent.h"
#include "StyleComponent.h"
#include "../ECSObjects/System.h"

class RenderSystem: public System {
    public:
        explicit RenderSystem();

        void render(const std::shared_ptr<Renderer>& renderer, Camera camera);

    private:
};


#endif //TEXTBASED_RENDERSYSTEM_H
