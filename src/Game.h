#ifndef TEXTBASED_GAME_H
#define TEXTBASED_GAME_H
#include <SDL2/SDL.h>
#include "Renderer.h"



class Game{

private:
        bool isRunning;
        Window* window;
        Renderer* renderer;
        void createWindow();


public:

    void initialize();

    void run();

    void close();

    int windowWidth;
    int windowHeight;

    void Setup();

    void ProcessInput();

    void Update();

};


#endif //TEXTBASED_GAME_H
