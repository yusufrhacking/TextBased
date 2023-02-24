#include "./Game.h"
#include "spdlog/spdlog.h"

int main() {
    std::unique_ptr<Game> game = std::make_unique<Game>();

    game->initialize();
    game->run();
    game->close();
    SPDLOG_TRACE("Some trace message with param {}", 42);

}