#include "Renderer.h"
#include "../../Objects/Position.h"
#include "../../ECS/Components/SpriteComponent.h"
#include <iostream>


Renderer::Renderer(SDL_Window* window) {
    this->renderer = SDL_CreateRenderer(window, -1, 0);
    if(this->renderer == nullptr){
        spdlog::error("RENDERER NOT CREATED");
        spdlog::error(SDL_GetError());
    }

    if (isImproperlyInitialized()){
        spdlog::error("TFT INIT FAIL");
    }
    font = TTF_OpenFont("../../resources/Monaco.ttf", FONT_SIZE);
    if (!isFontFound()) {
        spdlog::error("OPEN FONT FAIL");
    }
}

void Renderer::renderText(const std::shared_ptr<Position>& position, const SpriteComponent& sprite){
    SDL_SetRenderDrawColor(renderer, 30, 30, 30, 100);
    SDL_RenderClear(renderer);

    SDL_Color color = {255, 255, 255};

    SDL_Surface* surface = TTF_RenderText_Blended(
            font,
            sprite.text.c_str(),
            color
    );

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    int width = (int)sprite.width;
    int height = (int)sprite.height;
    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);

    SDL_Rect dstRect = {static_cast<int>(position->xPos), static_cast<int>(position->yPos), width, height};

    SDL_RenderCopy(renderer, texture, nullptr, &dstRect);

    spdlog::info("Have rendered copy");
}

void Renderer::render() {
    SDL_RenderPresent(renderer);
}

//void Renderer::renderDummyText() const {
//    SDL_Color color = {255, 255, 255};
//
//    SDL_Surface* surface = TTF_RenderText_Blended(
//            font,
//            "Robert C. Martin",
//            color
//            );
//
//    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
//    SDL_FreeSurface(surface);
//
//    int width = 0;
//    int height = 0;
//    SDL_QueryTexture(texture, NULL, NULL, &width, &height);
//
//    SDL_Rect dstRect = {50, 50, width, height};
//
//    SDL_RenderCopy(renderer, texture, NULL, &dstRect);
//}

Renderer::~Renderer() {
    TTF_CloseFont( font );
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
}


bool Renderer::isFontFound() const { return font; }

bool Renderer::isImproperlyInitialized() const { return TTF_Init() < 0; }