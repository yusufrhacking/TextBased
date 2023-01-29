#ifndef TEXTBASED_RENDERER_H
#define TEXTBASED_RENDERER_H
#include <SDL2/SDL.h>
#include "Window.h"



class Renderer {
    SDL_Renderer* renderer;
    Window window;


public:
    explicit Renderer(Window* window);
    void Render();
    ~Renderer();

private:

};


#endif //TEXTBASED_RENDERER_H
