#include "./Game.h"
#include "spdlog/spdlog.h"

int main() {
    Game* game = new Game();

    game->initialize();
    game->run();
    game->close();
    SPDLOG_TRACE("Some trace message with param {}", 42);

}