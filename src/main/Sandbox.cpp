#include "HighLevel/Game.h"
#include "spdlog/spdlog.h"

std::unique_ptr<ECSManager> ecsManager;
std::unique_ptr<EventBus> eventBus;

int main() {
    ecsManager = std::make_unique<ECSManager>(Game::startingTopLeftPosition);
    eventBus = std::make_unique<EventBus>();
    spdlog::set_level(spdlog::level::trace);

    Game* game = new Game();

    game->initialize();
    game->run();
    game->close();
}