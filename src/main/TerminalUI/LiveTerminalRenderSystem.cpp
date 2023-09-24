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
    auto startingPosition = renderPlayerName(renderer, startingTerminalPosition);
    startingPosition = renderPromptSymbol(renderer, startingPosition);
    startingPosition = renderLiveText(renderer, startingPosition);
    renderUnderscore(renderer, startingPosition);
}

Position LiveTerminalRenderSystem::renderPlayerName(const std::shared_ptr<Renderer> &renderer, Position startingPosition) {
    auto playerNameText = AuthorCommands::authorToText(Author::PLAYER);
    renderer->renderText(unusedCamera, startingPosition, TextComponent(playerNameText), StyleComponent(Style::TERMINAL));
    return startingPosition + Position(playerNameText.size() * TERMINAL_MONACO_TEXT_WIDTH_SCALER + 10, 0);
}

Position LiveTerminalRenderSystem::renderPromptSymbol(const std::shared_ptr<Renderer> &renderer, Position startingPosition) {
    auto submittedPosition = startingPosition;
    renderer->renderText(unusedCamera, submittedPosition, TextComponent(">"), StyleComponent(Style::TERMINAL));
    return startingPosition + Position(TEXT_OFFSET, (float)0);
}

Position LiveTerminalRenderSystem::renderLiveText(const std::shared_ptr<Renderer> &renderer, Position startingPosition) {
    auto terminalTextC = TextComponent(currentText);
    renderer->renderText(unusedCamera, startingPosition, terminalTextC, StyleComponent(Style::TERMINAL));

    float textXLength = (float)currentText.size() * TERMINAL_MONACO_TEXT_WIDTH_SCALER;
    return startingPosition + Position(textXLength, (float)0);
}

Position LiveTerminalRenderSystem::renderUnderscore(const std::shared_ptr<Renderer>& renderer, Position startingPosition) {
    if (!isTerminalLive){
        return {};
    }

    auto submittedPosition = startingPosition + Position((float)0, UNDERSCORE_Y_OFFSET);

    if (showUnderscore > 30){
        renderer->renderText(unusedCamera, submittedPosition, TextComponent("_"), StyleComponent(Style::TERMINAL));
    }
    showUnderscore += 1;
    showUnderscore = showUnderscore % 60;
    return submittedPosition;
}

void LiveTerminalRenderSystem::onTerminalRender(TerminalTextUpdateEvent& event) {
    currentText = event.text;
}

void LiveTerminalRenderSystem::onTakingInputFlip(TakingInputFlipEvent& event) {
    isTerminalLive = !isTerminalLive;
}
