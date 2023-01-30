#ifndef TEXTBASED_RENDERER_H
#define TEXTBASED_RENDERER_H
#include <SDL2/SDL.h>
#include "../Window/Window.h"
#include <SDl2/SDL_ttf.h>



class Renderer {
    SDL_Renderer* renderer;
    Window window;
    TTF_Font* font;


public:
    explicit Renderer(Window* window);
    void Render();
    ~Renderer();

private:

};


#endif //TEXTBASED_RENDERER_H
