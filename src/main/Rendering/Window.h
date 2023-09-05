#ifndef TEXTBASED_WINDOW_H
#define TEXTBASED_WINDOW_H
#include <SDL.h>
#include "../Positioning/Position.h"
#include <memory>

class Window {

    public:
        Window();
        ~Window();
        SDL_Window* getWindow();
        static int windowWidth;
        static int windowHeight;

        static void initializeWindowSize();

        [[nodiscard]] static Position getTopLeftPosition() ;

        [[nodiscard]] static Position getBottomLeftPosition() ;

        [[nodiscard]] static Position getTopRightPosition() ;

        [[nodiscard]] static Position getBottomRightPosition() ;

        static Position getMiddlePosition();

        static Position deriveRelativeTopLeft(Position position);


private:
        SDL_Window* window;
        void createWindow();

};


#endif //TEXTBASED_WINDOW_H
