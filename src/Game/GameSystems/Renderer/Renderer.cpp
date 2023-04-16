#include "Renderer.h"


const static SDL_Color textColor = {255, 255, 255};


Renderer::Renderer(SDL_Window* sdlWindow) {
    this->renderer = SDL_CreateRenderer(sdlWindow, -1, 0);
    if(this->renderer == nullptr){
        spdlog::error("RENDERER NOT CREATED");
        spdlog::error(SDL_GetError());
    }

    if (isImproperlyInitialized()){
        spdlog::error("TFT INIT FAIL");
    }

    fcFont = FC_CreateFont();
    FC_LoadFont(fcFont, renderer, "../../resources/Monaco.ttf",
                FONT_SIZE, FC_MakeColor(255,255,255,255), TTF_STYLE_NORMAL);
}

void Renderer::renderText(const std::shared_ptr<Position>& position, const SpriteComponent& sprite){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    FC_Draw(fcFont, renderer, position->xPos, position->yPos, sprite.text.c_str());
}

void Renderer::renderFrame() {
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
}

Renderer::~Renderer() {
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
}


bool Renderer::isFontFound() const { return font; }

bool Renderer::isImproperlyInitialized() const { return TTF_Init() < 0; }