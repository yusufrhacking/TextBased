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
    whiteTerminalFont = FC_CreateFont();
    FC_LoadFont(whiteTerminalFont, renderer, "../../resources/Monaco.ttf",
                TERMINAL_FONT_SIZE, white, TTF_STYLE_NORMAL);
    grayTerminalFont = FC_CreateFont();
    FC_LoadFont(grayTerminalFont, renderer, "../../resources/Monaco.ttf",
                TERMINAL_FONT_SIZE, faded_white, TTF_STYLE_NORMAL);
    grayLetterFont = FC_CreateFont();
    FC_LoadFont(grayLetterFont, renderer, "../../resources/Monaco.ttf",
                TEXT_C_FONT_SIZE, gray, TTF_STYLE_BOLD);
    whiteLetterBankFont = FC_CreateFont();
    FC_LoadFont(whiteLetterBankFont, renderer, "../../resources/Monaco.ttf",
                TEXT_C_FONT_SIZE, white, TTF_STYLE_BOLD);
    greenLetterBankFont = FC_CreateFont();
    FC_LoadFont(greenLetterBankFont, renderer, "../../resources/Monaco.ttf",
                TEXT_C_FONT_SIZE, matrix_green, TTF_STYLE_BOLD);

    greenTerminalFont = FC_CreateFont();
    FC_LoadFont(greenTerminalFont, renderer, "../../resources/Monaco.ttf",
                TERMINAL_FONT_SIZE, matrix_green, TTF_STYLE_NORMAL);
    amberTerminalFont = FC_CreateFont();
    FC_LoadFont(amberTerminalFont, renderer, "../../resources/Monaco.ttf",
                TERMINAL_FONT_SIZE, faded_amber, TTF_STYLE_NORMAL);
    whiteNumberBankFont = FC_CreateFont();
    FC_LoadFont(whiteNumberBankFont, renderer, "../../resources/Monaco.ttf",
                10, white, TTF_STYLE_NORMAL);
    greenNumberBankFont = FC_CreateFont();
    FC_LoadFont(greenNumberBankFont, renderer, "../../resources/Monaco.ttf",
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
        case Style::GRAY_LETTER:
            return grayLetterFont;
        case Style::WHITE_TERMINAL:
            return whiteTerminalFont;
        case Style::GRAY_TERMINAL:
            return grayTerminalFont;
        case Style::GREEN_TERMINAL:
            return greenTerminalFont;
        case Style::AMBER_TERMINAL:
            return greenTerminalFont;
        case Style::WHITE_LETTER_IN_BANK:
            return whiteLetterBankFont;
        case Style::TINY_WHITE_NUMBER:
            return whiteNumberBankFont;
        case Style::GREEN_LETTER_IN_BANK:
            return greenLetterBankFont;
        case Style::TINY_GREEN_NUMBER:
            return greenNumberBankFont;
        default:
            throw NoStyleException();
    }
}




