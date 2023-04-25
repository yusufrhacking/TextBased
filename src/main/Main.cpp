#include "Game/Game.h"

std::unique_ptr<ECSManager> ecsManager;

int main() {
    ecsManager = std::make_unique<ECSManager>();
    Game* game = new Game();

    game->initialize();
    game->run();
    game->close();
}