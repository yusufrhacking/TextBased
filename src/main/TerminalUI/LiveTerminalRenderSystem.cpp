#include <spdlog/spdlog.h>

#include <ranges>
#include "TerminalTextUpdateEvent.h"
#include "LiveTerminalRenderSystem.h"
#include "../HighLevel/ECSManager.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

float LiveTerminalRenderSystem::TERMINAL_X_START = 30;
float LiveTerminalRenderSystem::BOTTOM_WINDOW_OFFSET = 110;
float LiveTerminalRenderSystem::TERMINAL_INIT_X_OFFSET = 35;
float LiveTerminalRenderSystem::UNDERSCORE_Y_OFFSET = 3;
float LiveTerminalRenderSystem::TEXT_OFFSET = 30;

LiveTerminalRenderSystem::LiveTerminalRenderSystem(Position startingTerminalPosition) {
    eventBus->listenToEvent<TerminalTextUpdateEvent>(this, &LiveTerminalRenderSystem::onTerminalRender);
    eventBus->listenToEvent<TakingInputFlipEvent>(this, &LiveTerminalRenderSystem::onTakingInputFlip);

    startingTerminalPosition = startingTerminalPosition;
}

void LiveTerminalRenderSystem::render(const std::shared_ptr<Renderer> &renderer, Camera camera) {
    renderLiveLine(renderer);
}

void LiveTerminalRenderSystem::renderLiveLine(const std::shared_ptr<Renderer> &renderer) {
    renderPromptSymbol(renderer);
    renderUnderscore(renderer);
    renderLiveText(renderer);
}

void LiveTerminalRenderSystem::renderPromptSymbol(const std::shared_ptr<Renderer> &renderer) {
    auto submittedPosition = startingTerminalPosition;
    renderer->renderText(unusedCamera, submittedPosition, TextComponent(">"), StyleComponent(Style::TERMINAL));
}

void LiveTerminalRenderSystem::renderLiveText(const std::shared_ptr<Renderer> &renderer) {
    auto terminalTextC = TextComponent(currentText);
    auto position = Position(TERMINAL_X_START + TEXT_OFFSET, TERMINAL_Y_START);
    renderer->renderText(unusedCamera, position, terminalTextC, StyleComponent(Style::TERMINAL));
}

void LiveTerminalRenderSystem::renderUnderscore(const std::shared_ptr<Renderer>& renderer) {
    if (!isTerminalLive){
        return;
    }

    float textXLength = (float)currentText.size() * TERMINAL_MONACO_TEXT_WIDTH_SCALER;
    auto submittedPosition = startingTerminalPosition + Position(TEXT_OFFSET + textXLength, UNDERSCORE_Y_OFFSET);

    if (showUnderscore > 30){
        renderer->renderText(unusedCamera, submittedPosition, TextComponent("_"), StyleComponent(Style::TERMINAL));
    }
    showUnderscore += 1;
    showUnderscore = showUnderscore % 60;
}

void LiveTerminalRenderSystem::onTerminalRender(TerminalTextUpdateEvent& event) {
    currentText = event.text;
}

void LiveTerminalRenderSystem::onTakingInputFlip(TakingInputFlipEvent& event) {
    isTerminalLive = !isTerminalLive;
}
