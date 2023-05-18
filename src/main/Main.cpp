#include "Game/Game.h"

std::unique_ptr<ECSManager> ecsManager;
std::unique_ptr<EventBus> eventBus;

int main() {
    ecsManager = std::make_unique<ECSManager>();
    eventBus = std::make_unique<EventBus>();

    Game* game = new Game();

    game->initialize();
    game->run();
    game->close();
}