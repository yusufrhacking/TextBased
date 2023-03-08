#ifndef TEXTBASED_RENDERER_H
#define TEXTBASED_RENDERER_H
#include <SDL2/SDL.h>
#include "../Window/Window.h"
#include <SDL_ttf.h>
#include "spdlog/spdlog.h"
#include "../../../Objects/Position.h"
#include "../../../ECS/Components/SpriteComponent.h"


static const int FONT_SIZE = 10;

class Renderer {
    SDL_Renderer* renderer;
    TTF_Font* font;


public:
    explicit Renderer(SDL_Window* sdlWindow);
    ~Renderer();
    void renderText(const std::shared_ptr<Position>& position, const SpriteComponent& sprite);
    void renderFrame();

private:
    bool isImproperlyInitialized() const;

    bool isFontFound() const;

};


#endif //TEXTBASED_RENDERER_H
