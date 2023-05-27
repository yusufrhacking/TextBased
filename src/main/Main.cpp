#include "Game/Game.h"
#include "spdlog/spdlog.h"

std::unique_ptr<ECSManager> ecsManager;
std::unique_ptr<EventBus> eventBus;
std::unique_ptr<Window> window;

int main() {
    ecsManager = std::make_unique<ECSManager>();
    eventBus = std::make_unique<EventBus>();
    spdlog::set_level(spdlog::level::trace);

    Game* game = new Game();

    game->initialize();
    game->run();
    game->close();
}