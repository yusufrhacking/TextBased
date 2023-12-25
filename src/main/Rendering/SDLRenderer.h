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
    SDL_Color white = {255, 255, 255, 255};
    SDL_Color faded_white = {255, 255, 255, 180};
    SDL_Color black = {0, 0, 0, 255};
    SDL_Color gray = {178, 190, 181, 255};
    SDL_Color matrix_green = {102, 255, 102, 255};
    SDL_Color faded_amber = {255, 176, 0, 180};



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
