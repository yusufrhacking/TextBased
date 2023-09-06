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
    SDL_Color white = {255, 255, 255, 255};
    SDL_Color black = {0, 0, 0, 255};
    const float TERMINAL_X_START = 30;
    const float TERMINAL_Y_START = (float)Window::windowHeight - 110;
    int showUnderscore = 0;
    const float TERMINAL_INIT_X_OFFSET = 35;
    const float TERMINAL_INIT_Y_OFFSET = 3;



public:
    explicit SDLRenderer(SDL_Window* sdlWindow);
    ~SDLRenderer() override;
    void renderText(Camera camera, Position position, const TextComponent& sprite, const StyleComponent& style) override;
    void renderPresent() override;
    void renderClear() override;
    void renderTerminal() override;

private:
    bool isImproperlyInitialized() const;

    void renderTerminalLine();

    void renderFlashingUnderscore();
};


#endif //TEXTBASED_SDLRENDERER_H
