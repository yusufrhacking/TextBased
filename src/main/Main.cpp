#include "HighLevel/Game.h"
#include "spdlog/spdlog.h"

std::unique_ptr<ECSManager> ecsManager;
std::unique_ptr<EventBus> eventBus;

int main() {
    ecsManager = std::make_unique<ECSManager>();
    eventBus = std::make_unique<EventBus>();
    spdlog::set_level(spdlog::level::debug);

    Game* game = new Game();

    game->initialize();
    game->run();
    game->close();
}
