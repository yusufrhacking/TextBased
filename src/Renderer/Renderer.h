#ifndef TEXTBASED_RENDERER_H
#define TEXTBASED_RENDERER_H
#include <SDL2/SDL.h>
#include "../Window/Window.h"
#include <SDl2/SDL_ttf.h>
#include "spdlog/spdlog.h"



static const int FONT_SIZE = 24;

class Renderer {
    SDL_Renderer* renderer;
    Window window;
    TTF_Font* font;




public:
    explicit Renderer(Window* window);
    void render();
    ~Renderer();

private:

};


#endif //TEXTBASED_RENDERER_H
