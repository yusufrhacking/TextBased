#ifndef TEXTBASED_WINDOW_H
#define TEXTBASED_WINDOW_H
#include <SDL.h>
#include "../../../Helpers/Objects/Position.h"

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

        Position getMiddlePosition();

        void positionCamera(Position position);

        Position getCameraPosition();

    private:
        SDL_Window* window;
        SDL_Rect camera;
        int windowWidth;
        int windowHeight;
        void createWindow();

};


#endif //TEXTBASED_WINDOW_H
