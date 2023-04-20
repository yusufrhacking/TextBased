#ifndef TEXTBASED_WINDOW_H
#define TEXTBASED_WINDOW_H
#include <SDL.h>
#include "../../../Objects/Position.h"

class Window {

    public:
        Window();
        ~Window();
        SDL_Window* getWindow();
        int getWindowWidth();
        int getWindowHeight();

        [[nodiscard]] Position getTopLeftPosition() const;

        [[nodiscard]] Position getBottomLeftPosition() const;

        [[nodiscard]] Position getTopRightPosition() const;

        [[nodiscard]] Position getBottomRightPosition() const;

    private:
        SDL_Window* window;
        int windowWidth;
        int windowHeight;
        void createWindow();

};


#endif //TEXTBASED_WINDOW_H
