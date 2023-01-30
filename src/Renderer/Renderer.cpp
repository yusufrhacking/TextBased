#include "Renderer.h"


Renderer::Renderer(Window *window) {
    this->window = *window;
    this->renderer = SDL_CreateRenderer(this->window.getWindow(), -1, 0);

    if (TTF_Init() < 0){
        return;
    }

    font = TTF_OpenFont("../resources/Monaco.ttf", 24);
    if ( !font ) {
        return;
    }
}

void Renderer::Render() {
    SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);
}

Renderer::~Renderer() {
    SDL_DestroyRenderer(renderer);
}
