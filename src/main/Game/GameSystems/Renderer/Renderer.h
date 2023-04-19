#ifndef TEXTBASED_RENDERER_H
#define TEXTBASED_RENDERER_H
#include <SDL2/SDL.h>
#include "../Window/Window.h"
#include <SDL_ttf.h>
#include "../../../Objects/Position.h"
#include "../../../ECS/Components/TextComponent.h"
#include "../../../../../resources/SDL_FontCache.h"
#include "../../../Objects/Position.h"
#include "../../../ECS/Components/TextComponent.h"
#include <iostream>
#include "../../../../../resources/SDL_FontCache.h"
#include "../../../ECS/Components/StyleComponent.h"
#include <stdexcept>
#include "../../../Exceptions/NoStyleException.h"


class Renderer {
    SDL_Renderer* renderer;
    FC_Font* genericMonacoFont;

    public:
        explicit Renderer(SDL_Window* sdlWindow);
        ~Renderer();
        void renderText(const std::shared_ptr<Position>& position, const TextComponent& sprite, const StyleComponent& style);
        void renderFrame();

    private:
        bool isImproperlyInitialized() const;

};


#endif //TEXTBASED_RENDERER_H
