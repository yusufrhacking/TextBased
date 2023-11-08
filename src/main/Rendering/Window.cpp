#include <spdlog/spdlog.h>
#include "SDL_video.h"
#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-pro-type-member-init"
#include "Window.h"


int Window::windowWidth = 0;
int Window::windowHeight = 0;

Window::Window() {
    createWindow();
}

Window::~Window() {
    SDL_DestroyWindow(window);
}


void Window::createWindow() {
    window = SDL_CreateWindow(
            nullptr,
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            0,
            0,
            SDL_WINDOW_FULLSCREEN_DESKTOP
    );
    initializeWindowSize();

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

Position Window::deriveRelativeTopRight(Position position){
    Position topRight = deriveRelativeTopLeft(position) + Window::getTopRightPosition();
    return topRight;
}

Position Window::deriveRelativeBottomRight(Position position){
    Position bottomRight = deriveRelativeTopLeft(position) + Window::getBottomRightPosition();
    return bottomRight;
}

Position Window::deriveRelativeBottomLeft(Position position){
    Position bottomLeft = deriveRelativeTopLeft(position) + Window::getBottomLeftPosition();
    return bottomLeft;
}

void Window::initializeWindowSize() {
    if (windowWidth == 0 || windowHeight == 0) {
        SDL_DisplayMode displayMode;
        SDL_GetCurrentDisplayMode(0, &displayMode);
        windowWidth = displayMode.w;
        windowHeight = displayMode.h;
//        windowWidth = 1470;
//        windowHeight = 956;
        spdlog::info("Window Size: {}, {}", windowWidth, windowHeight);

//
//
//        SDL_Rect r{};
//
//        spdlog::info("Rect Size: {}", SDL_GetDisplayUsableBounds(0, &r));
        Page::pageWidth = windowWidth;
        Page::pageHeight = windowHeight;
    }
}


#pragma clang diagnostic pop