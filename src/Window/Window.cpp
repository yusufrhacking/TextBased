#include "Window.h"
#include <SDL2/SDL.h>
#include <spdlog/spdlog.h>

Window::Window() {
    createWindow();

    showWindow();

}

void Window::showWindow() const {
    SDL_Surface *window_surface = SDL_GetWindowSurface(window);

    if(!window_surface)
    {
        spdlog::error("Window surface initialization failed");
    }

    SDL_UpdateWindowSurface(window);
}

void Window::createWindow() {
    SDL_DisplayMode displayMode;
    SDL_GetCurrentDisplayMode(0, &displayMode);
    windowWidth = displayMode.w;
    windowHeight = displayMode.h;

    window = SDL_CreateWindow(
            nullptr,
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            windowWidth,
            windowHeight,
            0
    );

    if (window == NULL){
        spdlog::error("Window initialization failed");
    }
}

SDL_Window *Window::getWindow() {
    return window;
}


