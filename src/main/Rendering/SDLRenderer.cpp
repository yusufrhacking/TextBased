#include "SDLRenderer.h"
#include "../Camera/Camera.h"
#include "GenericStyleComponent.h"
#include "../Middlemarch/NovelTextComponent.h"

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

    redFont = FC_CreateFont();
    FC_LoadFont(redFont, renderer, "../../resources/Monaco.ttf",
        TEXT_C_FONT_SIZE, red, TTF_STYLE_NORMAL);

    goldFont = FC_CreateFont();
    FC_LoadFont(goldFont, renderer, "../../resources/Monaco.ttf",
        TEXT_C_FONT_SIZE, red, TTF_STYLE_NORMAL);
}

void SDLRenderer::renderDynamicText(Camera camera, Position position, const TextComponent& sprite, const GenericStyleComponent& style){
    auto cameraPos = camera.getCameraPosition();
    FC_Draw(styleToFont(style.getStyle()), renderer, position.x - cameraPos.x, position.y - cameraPos.y, sprite.text.c_str());
}

void SDLRenderer::renderFixedText(Position position, const TextComponent& sprite, const GenericStyleComponent& style){
    auto textWidth = sprite.getSurfaceSize().width;
    auto textHeight = sprite.getSurfaceSize().height;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    SDL_Rect backgroundRect;
    backgroundRect.x = (int)position.x;
    backgroundRect.y = (int)position.y;
    backgroundRect.w = (int)textWidth;
    backgroundRect.h = (int)textHeight;
    SDL_RenderFillRect(renderer, &backgroundRect);


    FC_Draw(styleToFont(style.getStyle()), renderer, position.x, position.y, sprite.text.c_str());
}

void SDLRenderer::renderNovelText(Camera camera, Position position, const TextComponent& sprite, const NovelTextComponent& novelStyle){
    auto textWidth = sprite.getSurfaceSize().width;
    auto textHeight = sprite.getSurfaceSize().height;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    SDL_Rect backgroundRect;
    backgroundRect.x = (int)position.x;
    backgroundRect.y = (int)position.y;
    backgroundRect.w = (int)textWidth;
    backgroundRect.h = (int)textHeight;
    SDL_RenderFillRect(renderer, &backgroundRect);

    FC_Draw(genericMonacoFont, renderer, position.x - camera.getCameraPosition().x, position.y - camera.getCameraPosition().y, sprite.text.c_str());
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

FC_Font* SDLRenderer::styleToFont(RenderStyle style) {
    switch (style) {
        case RenderStyle::WHITE_MONACO_GENERIC:
            return genericMonacoFont;
        case RenderStyle::GRAY_LETTER:
            return grayLetterFont;
        case RenderStyle::WHITE_TERMINAL:
            return whiteTerminalFont;
        case RenderStyle::GRAY_TERMINAL:
            return grayTerminalFont;
        case RenderStyle::GREEN_TERMINAL:
            return greenTerminalFont;
        case RenderStyle::AMBER_TERMINAL:
            return greenTerminalFont;
        case RenderStyle::WHITE_LETTER_IN_BANK:
            return whiteLetterBankFont;
        case RenderStyle::TINY_WHITE_NUMBER:
            return whiteNumberBankFont;
        case RenderStyle::GREEN_LETTER_IN_BANK:
            return greenLetterBankFont;
        case RenderStyle::TINY_GREEN_NUMBER:
            return greenNumberBankFont;
        case RenderStyle::RED:
            return redFont;
        case RenderStyle::GOLD:
            return goldFont;
        default:
            throw NoStyleException();
    }
}




