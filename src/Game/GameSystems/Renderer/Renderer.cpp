#include "Renderer.h"


const static SDL_Color color = {255, 255, 255};


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
    FC_LoadFont(fcFont, renderer, "../../resources/Monaco.ttf", FONT_SIZE, FC_MakeColor(255,255,255,255), TTF_STYLE_NORMAL);
//    font = TTF_OpenFont("../../resources/Monaco.ttf", FONT_SIZE);
//    if (!isFontFound()) {
//        spdlog::error("OPEN FONT FAIL");
//    }
}

void Renderer::renderText(const std::shared_ptr<Position>& position, const SpriteComponent& sprite){
    SDL_SetRenderDrawColor(renderer, 30, 30, 30, 100);

    FC_Draw(fcFont, renderer, position->xPos, position->yPos, sprite.text.c_str());


//    SDL_Surface* surface = TTF_RenderText_Blended_Wrapped(
//            font,
//            sprite.text.c_str(),
//            color,
//            0
//    );
//
//    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
//    SDL_FreeSurface(surface);
//    int width = 0;
//    int height = 0;
//    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
//
//    SDL_Rect dstRect = {static_cast<int>(position->xPos), static_cast<int>(position->yPos), width, height};
//    SDL_RenderCopy(renderer, texture, nullptr, &dstRect);
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