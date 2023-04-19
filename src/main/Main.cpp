#include "Game/Game.h"

int main() {
    Game* game = new Game();

    game->initialize();
    game->run();
    game->close();
}