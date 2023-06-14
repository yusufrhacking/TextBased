#include "Game/Game.h"
#include "Game/GameSystems/Camera/Camera.h"
#include "spdlog/spdlog.h"

std::unique_ptr<ECSManager> ecsManager;
std::unique_ptr<EventBus> eventBus;
std::unique_ptr<Window> window;
std::unique_ptr<Camera> camera;

int main() {
    ecsManager = std::make_unique<ECSManager>();
    eventBus = std::make_unique<EventBus>();
    camera = std::make_unique<Camera>(Game::startingTopLeftPosition);
    spdlog::set_level(spdlog::level::info);

    Game* game = new Game();

    game->initialize();
    game->run();
    game->close();
}