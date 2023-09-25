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
    unusedLetterBankFont = FC_CreateFont();
    FC_LoadFont(unusedLetterBankFont, renderer, "../../resources/Monaco.ttf",
                TEXT_C_FONT_SIZE, white, TTF_STYLE_BOLD);
    usedLetterBankFont = FC_CreateFont();
    FC_LoadFont(usedLetterBankFont, renderer, "../../resources/Monaco.ttf",
                TEXT_C_FONT_SIZE, matrix_green, TTF_STYLE_BOLD);
    diegeticFont = FC_CreateFont();
    FC_LoadFont(diegeticFont, renderer, "../../resources/Monaco.ttf",
                TERMINAL_FONT_SIZE, matrix_green, TTF_STYLE_NORMAL);
    unusedTinyNumberFont = FC_CreateFont();
    FC_LoadFont(unusedTinyNumberFont, renderer, "../../resources/Monaco.ttf",
                10, white, TTF_STYLE_NORMAL);
    usedTinyNumberFont = FC_CreateFont();
    FC_LoadFont(usedTinyNumberFont, renderer, "../../resources/Monaco.ttf",
                10, matrix_green, TTF_STYLE_NORMAL);
}

void SDLRenderer::renderDynamicText(Camera camera, Position position, const TextComponent& sprite, const StyleComponent& style){
    auto cameraPos = camera.getCameraPosition();
    FC_Draw(styleToFont(style.getStyle()), renderer, position.xPos - cameraPos.xPos, position.yPos - cameraPos.yPos, sprite.text.c_str());
}

void SDLRenderer::renderFixedText(Position position, const TextComponent& sprite, const StyleComponent& style){
    FC_Draw(styleToFont(style.getStyle()), renderer, position.xPos, position.yPos, sprite.text.c_str());
}

void SDLRenderer::renderTerminal(std::string text) {
    SDL_SetRenderDrawColor(renderer, white.r, white.g, white.b, white.a);
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

FC_Font* SDLRenderer::styleToFont(Style style) {
    switch (style) {
        case Style::WHITE_MONACO_GENERIC:
            return genericMonacoFont;
        case Style::LETTER:
            return letterFont;
        case Style::TERMINAL:
            return terminalFont;
        case Style::OLD_TERMINAL_COMMAND:
            return fadedTerminalFont;
        case Style::ENGINEER_TERMINAL:
            return diegeticFont;
        case Style::UNUSED_LETTER_BANK:
            return unusedLetterBankFont;
        case Style::UNUSED_TINY_NUMBER:
            return unusedTinyNumberFont;
        case Style::USED_LETTER_BANK:
            return usedLetterBankFont;
        case Style::USED_TINY_NUMBER:
            return usedTinyNumberFont;
        default:
            throw NoStyleException();
    }
}




