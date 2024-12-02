#ifndef TEXTBASED_SDLRENDERER_H
#define TEXTBASED_SDLRENDERER_H
#include <SDL.h>
#include "Window.h"
#include <SDL_ttf.h>
#include "../Text/TextComponent.h"
#include "../../../resources/SDL_FontCache.h"
#include "../Text/TextComponent.h"
#include <iostream>
#include "../../../resources/SDL_FontCache.h"
#include "GenericStyleComponent.h"
#include <stdexcept>
#include "NoStyleException.h"
#include "gmock/gmock.h"
#include "Renderer.h"
#include "../Middlemarch/NovelTextComponent.h"

class SDLRenderer: public Renderer {
    SDL_Renderer* renderer;
    FC_Font* genericMonacoFont;
    FC_Font* whiteTerminalFont;
    FC_Font* grayTerminalFont;
    FC_Font* grayLetterFont;
    FC_Font* whiteLetterBankFont;
    FC_Font* greenLetterBankFont;
    FC_Font* greenTerminalFont;
    FC_Font* amberTerminalFont;
    FC_Font* whiteNumberBankFont;
    FC_Font* greenNumberBankFont;
    FC_Font* redFont;
    FC_Font* goldFont;
    FC_Font* violetFont;

    SDL_Color white = {255, 255, 255, 255};
    SDL_Color faded_white = {255, 255, 255, 180};
    SDL_Color black = {0, 0, 0, 255};
    SDL_Color gray = {178, 190, 181, 255};
    SDL_Color matrix_green = {102, 255, 102, 255};
    SDL_Color amber = {255, 191, 0, 255};
    SDL_Color red = {255, 0, 0, 255};
    SDL_Color gold = {255, 225, 64, 255};
    SDL_Color violet = {127, 0, 180, 255};

    SDL_Color whiteTwo = {220, 220, 220, 255};
    SDL_Color whiteThree = {185, 185, 185, 255};
    SDL_Color whiteFour = {150, 150, 150, 255};
    SDL_Color whiteFive = {115, 115, 115, 255};
    SDL_Color whiteSix = {80, 80, 80, 255};
    SDL_Color whiteSeven = {45, 45, 45, 255};

    FC_Font* whiteTwoFont;
    FC_Font* whiteThreeFont;
    FC_Font* whiteFourFont;
    FC_Font* whiteFiveFont;
    FC_Font* whiteSixFnt;
    FC_Font* whiteSevenFont;



public:
    explicit SDLRenderer(SDL_Window* sdlWindow);
    ~SDLRenderer() override;
    void renderDynamicText(Camera camera, Position position, const TextComponent& sprite, const GenericStyleComponent& style) override;
    void renderFixedText(Position position, const TextComponent& sprite, const GenericStyleComponent& style) override;
    void renderPresent() override;
    void renderClear() override;
    void renderTerminal(std::string text) override;
    void renderNovelText(Camera camera, Position position, const TextComponent &sprite, const NovelTextComponent &style) override;

private:
    FC_Font* styleToFont(RenderStyle style);
    bool isImproperlyInitialized() const;

};


#endif //TEXTBASED_SDLRENDERER_H
