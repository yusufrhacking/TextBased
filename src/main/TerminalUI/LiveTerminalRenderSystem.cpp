#include <spdlog/spdlog.h>

#include <ranges>
#include "TerminalTextUpdateEvent.h"
#include "LiveTerminalRenderSystem.h"
#include "../HighLevel/ECSManager.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;


LiveTerminalRenderSystem::LiveTerminalRenderSystem(Position startingTerminalPosition) {
    eventBus->listenToEvent<TerminalTextUpdateEvent>(this, &LiveTerminalRenderSystem::onTerminalRender);
    eventBus->listenToEvent<TakingInputFlipEvent>(this, &LiveTerminalRenderSystem::onTakingInputFlip);

    this->startingTerminalPosition = startingTerminalPosition;
}

void LiveTerminalRenderSystem::render(const std::shared_ptr<Renderer> &renderer) {
    renderLiveLine(renderer);
}

void LiveTerminalRenderSystem::renderLiveLine(const std::shared_ptr<Renderer> &renderer) {
    Type type = Type::PLAIN_TERMINAL_TEXT;
    auto style = StyleComponent(type);
    auto startingPosition = terminalRenderer.renderAuthor(renderer, startingTerminalPosition, AuthorCommands::authorToText(Author::PLAYER), style);
    startingPosition = terminalRenderer.renderPromptSymbol(renderer, startingPosition, style);
    startingPosition = terminalRenderer.renderText(renderer, startingPosition, currentText, style);
    terminalRenderer.renderUnderscore(renderer, startingPosition, currentText, isTerminalLive, style);
}

void LiveTerminalRenderSystem::onTerminalRender(TerminalTextUpdateEvent& event) {
    currentText = event.text;
}

void LiveTerminalRenderSystem::onTakingInputFlip(TakingInputFlipEvent& event) {
    isTerminalLive = !isTerminalLive;
}
