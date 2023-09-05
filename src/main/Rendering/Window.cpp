#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-pro-type-member-init"
#include "Window.h"
#include "../TheCanon/Page.h"
#include <SDL.h>
#include <stdexcept>

int Window::windowWidth = 0;
int Window::windowHeight = 0;

Window::Window() {
    createWindow();
}

Window::~Window() {
    SDL_DestroyWindow(window);
}


void Window::createWindow() {
    initializeWindowSize();
    window = SDL_CreateWindow(
            nullptr,
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            windowWidth,
            windowHeight,
            0
    );

    if (window == nullptr){
        throw std::runtime_error(SDL_GetError());
    }
}


SDL_Window *Window::getWindow() {
    return window;
}

Position Window::getTopLeftPosition() {
    Position TOP_LEFT_POSITION = {0, 0};
    return TOP_LEFT_POSITION;
}

Position Window::getBottomLeftPosition() {
    Position BOTTOM_LEFT_POSITION = {0, windowHeight};
    return BOTTOM_LEFT_POSITION;
}

Position Window::getTopRightPosition() {
    Position TOP_RIGHT_POSITION = {(windowWidth), 0};
    return TOP_RIGHT_POSITION;
}

Position Window::getBottomRightPosition() {
    Position BOTTOM_RIGHT_POSITION = {(windowWidth), (windowHeight)};
    return BOTTOM_RIGHT_POSITION;
}

Position Window::getMiddlePosition() {
    Position MIDDLE = {(windowWidth)/2, (windowHeight)/2};
    return MIDDLE;
}

Position Window::deriveRelativeTopLeft(Position position){
    auto newXPos = (position.xPos - (float)((int)position.xPos % windowWidth));
    auto newYPos = (position.yPos - (float)((int)position.yPos % windowHeight));
    Position topLeft = {newXPos, newYPos};
    return topLeft;
}

void Window::initializeWindowSize() {
    if (windowWidth == 0 || windowHeight == 0) {
        SDL_DisplayMode displayMode;
        SDL_GetCurrentDisplayMode(0, &displayMode);
        windowWidth = displayMode.w;
        windowHeight = displayMode.h;
        Page::pageWidth = windowWidth;
        Page::pageHeight = windowHeight;
    }
}


#pragma clang diagnostic pop