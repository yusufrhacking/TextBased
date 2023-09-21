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
                TEXT_C_FONT_SIZE, white, TTF_STYLE_NORMAL);
    terminalFont = FC_CreateFont();
    FC_LoadFont(terminalFont, renderer, "../../resources/Monaco.ttf",
                TERMINAL_FONT_SIZE, white, TTF_STYLE_NORMAL);
    letterFont = FC_CreateFont();
    FC_LoadFont(letterFont, renderer, "../../resources/Monaco.ttf",
                TEXT_C_FONT_SIZE, gray, TTF_STYLE_NORMAL);
    countFont = FC_CreateFont();
    FC_LoadFont(letterFont, renderer, "../../resources/Monaco.ttf",
                5, gray, TTF_STYLE_NORMAL);


    r = {50, 50, 50, 50};
}

void SDLRenderer::renderText(Camera camera, Position position, const TextComponent& sprite, const StyleComponent& style){
    auto cameraPos = camera.getCameraPosition();
    switch (style.getStyle()){
        case WHITE_MONACO_GENERIC:
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            FC_Draw(genericMonacoFont, renderer, position.xPos - cameraPos.xPos, position.yPos - cameraPos.yPos, sprite.text.c_str());
            break;
        case LETTER:
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            FC_Draw(letterFont, renderer, position.xPos - cameraPos.xPos, position.yPos - cameraPos.yPos, sprite.text.c_str());
            break;
        default: throw NoStyleException();
    }
}

void SDLRenderer::renderLetterbank(std::map<char, int> textmap) { //Actually we need this to work a little different because the letter count needs to be paired with the letters
    SDL_SetRenderDrawColor(renderer, white.r, white.g, white.b, white.a);
    renderLetterbankStart();
    renderLetterbankText(textmap);
}

void SDLRenderer::renderLetterbankStart() {

}

void SDLRenderer::renderLetterbankText(std::map<char, int> textmap) {

}



void SDLRenderer::renderTerminal(std::string text) {
    SDL_SetRenderDrawColor(renderer, white.r, white.g, white.b, white.a);
    renderTerminalLineStart();
    renderTerminalText(text);
    renderFlashingUnderscore(text);
    SDL_SetRenderDrawColor(renderer, black.r, black.g, black.b, black.a);
}

void SDLRenderer::renderTerminalLineStart() {
    FC_Draw(terminalFont, renderer, TERMINAL_X_START, TERMINAL_Y_START, ">");
}


void SDLRenderer::renderTerminalText(std::string text) {
    FC_Draw(terminalFont, renderer, TERMINAL_X_START + TEXT_OFFSET, TERMINAL_Y_START, text.c_str());
}

void SDLRenderer::renderFlashingUnderscore(std::string text) {
    float textXLength = (float)text.size() * TERMINAL_MONACO_TEXT_WIDTH_SCALER;
    if (showUnderscore > 30){
        FC_Draw(terminalFont, renderer, TERMINAL_X_START + TEXT_OFFSET + textXLength,
                TERMINAL_Y_START + UNDERSCORE_Y_OFFSET, "_");
    }
    showUnderscore += 1;
    showUnderscore = showUnderscore % 60;
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



