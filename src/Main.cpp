#include "Game/Game.h"
#include "spdlog/spdlog.h"

int main() {
    spdlog::set_level(spdlog::level::debug);
    Game* game = new Game();

    game->initialize();
    game->run();
    game->close();
//    SPDLOG_TRACE("Some trace message with param {}", 42);
    SPDLOG_DEBUG("Some debug message");
}