#include "SDLRenderer.h"
#include "../Camera/Camera.h"
#include "StyleComponent.h"

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
                TEXT_C_FONT_SIZE, white, TTF_STYLE_NORMAL);
    terminalFont = FC_CreateFont();
    FC_LoadFont(terminalFont, renderer, "../../resources/Monaco.ttf",
                TERMINAL_FONT_SIZE, white, TTF_STYLE_NORMAL);
    fadedTerminalFont = FC_CreateFont();
    FC_LoadFont(fadedTerminalFont, renderer, "../../resources/Monaco.ttf",
                TERMINAL_FONT_SIZE, faded_white, TTF_STYLE_NORMAL);
    letterFont = FC_CreateFont();
    FC_LoadFont(letterFont, renderer, "../../resources/Monaco.ttf",
                TEXT_C_FONT_SIZE, gray, TTF_STYLE_BOLD);
    diegeticFont = FC_CreateFont();
    FC_LoadFont(diegeticFont, renderer, "../../resources/Monaco.ttf",
                TERMINAL_FONT_SIZE, matrix_green, TTF_STYLE_NORMAL);
}

void SDLRenderer::renderText(Camera camera, Position position, const TextComponent& sprite, const StyleComponent& style){
    auto cameraPos = camera.getCameraPosition();
    switch (style.getStyle()){
        case Style::WHITE_MONACO_GENERIC:
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            FC_Draw(genericMonacoFont, renderer, position.xPos - cameraPos.xPos, position.yPos - cameraPos.yPos, sprite.text.c_str());
            break;
        case Style::LETTER:
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            FC_Draw(letterFont, renderer, position.xPos - cameraPos.xPos, position.yPos - cameraPos.yPos, sprite.text.c_str());
            break;
        case Style::TERMINAL:
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            FC_Draw(terminalFont, renderer, position.xPos, position.yPos, sprite.text.c_str());
            break;
        case Style::OLD_TERMINAL_COMMAND:
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            FC_Draw(fadedTerminalFont, renderer, position.xPos, position.yPos, sprite.text.c_str());
            break;
        case Style::ENGINEER_TERMINAL:
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            FC_Draw(diegeticFont, renderer, position.xPos, position.yPos, sprite.text.c_str());
            break;
        default: throw NoStyleException();
    }
}

void SDLRenderer::renderTerminal(std::string text) {
    SDL_SetRenderDrawColor(renderer, white.r, white.g, white.b, white.a);
//    renderTerminalLineStart();
//    renderTerminalText(text);
//    renderFlashingUnderscore(text);
    SDL_SetRenderDrawColor(renderer, black.r, black.g, black.b, black.a);
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



