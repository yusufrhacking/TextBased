#include "Renderer.h"
#include <iostream>


Renderer::Renderer(Window *window) {
    this->window = *window;
    this->renderer = SDL_CreateRenderer(this->window.getWindow(), -1, 0);

    if (TTF_Init() < 0){
        spdlog::error("TFT INIT FAIL");
    }

    font = TTF_OpenFont("../../resources/Monaco.ttf", FONT_SIZE);
    if ( !font ) {
        spdlog::error("OPEN FONT FAIL");
    }


}

void Renderer::render() {
    SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
    SDL_RenderClear(renderer);
    SDL_Color color = {255, 255, 255};

    SDL_Surface* surface = TTF_RenderText_Blended(
            font,
            "Hello",
            color
            );

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    int width = 0;
    int height = 0;
    SDL_QueryTexture(texture, NULL, NULL, &width, &height);

    SDL_Rect dstRect = {50, 50, width, height};

    SDL_RenderCopy(renderer, texture, NULL, &dstRect);

    SDL_RenderPresent(renderer);
}

Renderer::~Renderer() {
    TTF_CloseFont( font );
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
}
