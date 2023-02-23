#ifndef TEXTBASED_WINDOW_H
#define TEXTBASED_WINDOW_H
#include <SDL2/SDL.h>

class Window {
    int windowWidth;
    int windowHeight;
    SDL_Window* window;

public:
    Window();
    SDL_Window* getWindow();
private:
    void createWindow();

    void showWindow() const;
};


#endif //TEXTBASED_WINDOW_H
