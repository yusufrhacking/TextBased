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

void LiveTerminalRenderSystem::render(const std::shared_ptr<Renderer> &renderer, Camera camera) {
    renderLiveLine(renderer);
}

void LiveTerminalRenderSystem::renderLiveLine(const std::shared_ptr<Renderer> &renderer) {
    auto startingPosition = terminalRenderer.renderAuthor(renderer, startingTerminalPosition, AuthorCommands::authorToText(Author::PLAYER));
    startingPosition = terminalRenderer.renderPromptSymbol(renderer, startingPosition);
    startingPosition = terminalRenderer.renderLiveText(renderer, startingPosition, currentText);
    terminalRenderer.renderUnderscore(renderer, startingPosition, currentText);
}

void LiveTerminalRenderSystem::onTerminalRender(TerminalTextUpdateEvent& event) {
    currentText = event.text;
}

void LiveTerminalRenderSystem::onTakingInputFlip(TakingInputFlipEvent& event) {
    isTerminalLive = !isTerminalLive;
}
