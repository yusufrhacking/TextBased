#ifndef TEXTBASED_RENDERER_H
#define TEXTBASED_RENDERER_H
#include <SDL2/SDL.h>
#include "../Window/Window.h"
#include <SDL_ttf.h>
#include "spdlog/spdlog.h"
#include "../../Objects/Position.h"
#include "../../ECS/Components/SpriteComponent.h"


static const int FONT_SIZE = 10;

class Renderer {
    SDL_Renderer* renderer;
    SDL_Window* window;
    TTF_Font* font;


public:
    explicit Renderer(SDL_Window* window);
    ~Renderer();
    void renderText(const std::shared_ptr<Position>& position, SpriteComponent sprite);

private:
    bool isImproperlyInitialized() const;

    bool isFontFound() const;

};


#endif //TEXTBASED_RENDERER_H
