#ifndef TEXTBASED_RENDERER_H
#define TEXTBASED_RENDERER_H
#include <SDL2/SDL.h>
#include "../Window/Window.h"
#include <SDl2/SDL_ttf.h>
#include "spdlog/spdlog.h"



static const int FONT_SIZE = 10;

class Renderer {
    SDL_Renderer* renderer;
    SDL_Window* window;
    TTF_Font* font;


public:
    explicit Renderer(SDL_Window* window);
    void render();
    ~Renderer();

private:
    void renderDummyText() const;

    bool isImproperlyInitialized() const;

    bool isFontFound() const;
};


#endif //TEXTBASED_RENDERER_H
