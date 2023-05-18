#ifndef TEXTBASED_SDLRENDERER_H
#define TEXTBASED_SDLRENDERER_H
#include <SDL.h>
#include "../Window/Window.h"
#include <SDL_ttf.h>
#include "../../../Helpers/Objects/Position.h"
#include "../../../ECS/Components/TextComponent.h"
#include "../../../../../resources/SDL_FontCache.h"
#include "../../../ECS/Components/TextComponent.h"
#include <iostream>
#include "../../../../../resources/SDL_FontCache.h"
#include "../../../ECS/Components/StyleComponent.h"
#include <stdexcept>
#include "../../../Exceptions/NoStyleException.h"
#include "gmock/gmock.h"
#include "Renderer.h"

class SDLRenderer: public Renderer {
    SDL_Renderer* renderer;
    FC_Font* genericMonacoFont;

public:
    explicit SDLRenderer(SDL_Window* sdlWindow);
    ~SDLRenderer() override;
    void renderText(const std::shared_ptr<Position>& position, const TextComponent& sprite, const StyleComponent& style) override;
    void renderFrame() override;

private:
    bool isImproperlyInitialized() const;
};


#endif //TEXTBASED_SDLRENDERER_H
