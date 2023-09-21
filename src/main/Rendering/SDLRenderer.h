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
#include "StyleComponent.h"
#include <stdexcept>
#include "NoStyleException.h"
#include "gmock/gmock.h"
#include "Renderer.h"

class SDLRenderer: public Renderer {
    SDL_Renderer* renderer;
    SDL_Rect r;
    FC_Font* genericMonacoFont;
    FC_Font* terminalFont;
    FC_Font* letterFont;
    FC_Font* countFont;
    SDL_Color white = {255, 255, 255, 255};
    SDL_Color black = {0, 0, 0, 255};
    SDL_Color gray = {178, 190, 181, 255};
    const float TERMINAL_X_START = 30;
    const float BOTTOM_WINDOW_OFFSET = 110;
    const float TERMINAL_Y_START = (float)Window::windowHeight - (BOTTOM_WINDOW_OFFSET-TERMINAL_MONACO_HEIGHT_LINE_OF_TEXT);
    const float LETTERBANK_Y_START = (float) Window::windowHeight - (TERMINAL_MONACO_HEIGHT_LINE_OF_TEXT); //Need to mess with this
    const float LETTERBANK_X_START = 30;
    int showUnderscore = 0;
    const float TERMINAL_INIT_X_OFFSET = 35;
    const float UNDERSCORE_Y_OFFSET = 3;
    const float TEXT_OFFSET = 30;



public:
    explicit SDLRenderer(SDL_Window* sdlWindow);
    ~SDLRenderer() override;
    void renderText(Camera camera, Position position, const TextComponent& sprite, const StyleComponent& style) override;
    void renderPresent() override;
    void renderClear() override;
    void renderTerminal(std::string text) override;

private:
    bool isImproperlyInitialized() const;

    void renderTerminalLineStart();

    void renderFlashingUnderscore(std::string text);

    void renderTerminalText(std::string text);

    void renderLetterbank(std::map<char, int> textmap);

    void renderLetterbankStart();

    void renderLetterbankText(std::map<char, int> textmap);
};


#endif //TEXTBASED_SDLRENDERER_H
