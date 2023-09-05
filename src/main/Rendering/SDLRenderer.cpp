#include "SDLRenderer.h"
#include "../Camera/Camera.h"

const static SDL_Color textColor = {255, 255, 255};


SDLRenderer::SDLRenderer(SDL_Window *sdlWindow){
    this->renderer = SDL_CreateRenderer(sdlWindow, -1, 0);
    if(this->renderer == nullptr){
        throw std::runtime_error(SDL_GetError());
    }

    if (isImproperlyInitialized()){
        throw std::runtime_error("TTF INIT FAIL");
    }

    genericMonacoFont = FC_CreateFont();
    FC_LoadFont(genericMonacoFont, renderer, "../../resources/Monaco.ttf",
                FONT_SIZE, FC_MakeColor(255,255,255,255), TTF_STYLE_NORMAL);

    r = {50, 50, 50, 50};
}

void SDLRenderer::renderText(Camera camera, Position position, const TextComponent& sprite, const StyleComponent& style){
    auto cameraPos = camera.getCameraPosition();
    switch (style.getStyle()){
        case WHITE_MONACO_GENERIC:
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            FC_Draw(genericMonacoFont, renderer, position.xPos - cameraPos.xPos, position.yPos - cameraPos.yPos, sprite.text.c_str());
            break;
        default: throw NoStyleException();
    }
}

void SDLRenderer::renderClear() {
    SDL_RenderClear(renderer);
}

void SDLRenderer::renderPresent() {
    SDL_RenderPresent(renderer);
}

SDLRenderer::~SDLRenderer() {
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
}

bool SDLRenderer::isImproperlyInitialized() const { return TTF_Init() < 0; }


