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
    FC_Font* genericMonacoFont;
    FC_Font* terminalFont;
    FC_Font* letterFont;
    SDL_Color white = {255, 255, 255, 255};
    SDL_Color black = {0, 0, 0, 255};
    SDL_Color gray = {178, 190, 181, 255};



public:
    explicit SDLRenderer(SDL_Window* sdlWindow);
    ~SDLRenderer() override;
    void renderText(Camera camera, Position position, const TextComponent& sprite, const StyleComponent& style) override;
    void renderPresent() override;
    void renderClear() override;
    void renderTerminal(std::string text) override;

private:
    bool isImproperlyInitialized() const;

};


#endif //TEXTBASED_SDLRENDERER_H
