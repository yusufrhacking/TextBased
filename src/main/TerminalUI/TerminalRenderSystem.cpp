#include <spdlog/spdlog.h>
#include "TerminalTextUpdateEvent.h"
#include "TerminalRenderSystem.h"
#include "FixedPositionComponent.h"
#include "../Rendering/StyleComponent.h"
#include "../HighLevel/ECSManager.h"
#include "TerminalUnderscoreComponent.h"
#include "../TextCommands/CommandLogSystem.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

float TerminalRenderSystem::TERMINAL_X_START = 30;
float TerminalRenderSystem::BOTTOM_WINDOW_OFFSET = 110;
float TerminalRenderSystem::TERMINAL_INIT_X_OFFSET = 35;
float TerminalRenderSystem::UNDERSCORE_Y_OFFSET = 3;
float TerminalRenderSystem::TEXT_OFFSET = 30;

TerminalRenderSystem::TerminalRenderSystem() {
    requireComponent<FixedPositionComponent>();
    requireComponent<StyleComponent>();
    requireComponent<TextComponent>();
    eventBus->listenToEvent<TerminalTextUpdateEvent>(this, &TerminalRenderSystem::onTerminalRender);
    eventBus->listenToEvent<TakingInputFlipEvent>(this, &TerminalRenderSystem::onTakingInputFlip);
}

void TerminalRenderSystem::render(const std::shared_ptr<Renderer> &renderer, Camera camera) {
    renderHistoricLines(renderer);
    renderLiveLine(renderer);
}

void TerminalRenderSystem::renderLiveLine(const std::shared_ptr<Renderer> &renderer) {
    for (auto entity : this->getRelevantEntities()){
        if (ecsManager->hasComponent<TerminalUnderscoreComponent>(entity)) {
            this->renderUnderscore(entity, renderer);
        } else{
            auto& positionComponent = ecsManager->getComponentFromEntity<FixedPositionComponent>(entity);
            const auto textComponent = ecsManager->getComponentFromEntity<TextComponent>(entity);
            const auto styleComponent = ecsManager->getComponentFromEntity<StyleComponent>(entity);
            renderer->renderText(unusedCamera, positionComponent.position, textComponent, styleComponent);
        }
    }
    auto terminalTextC = TextComponent(this->currentText);
    auto position = Position(TERMINAL_X_START + TEXT_OFFSET, this->TERMINAL_Y_START);
    renderer->renderText(unusedCamera, position, terminalTextC, StyleComponent(Style::TERMINAL));
}

void TerminalRenderSystem::renderHistoricLines(const std::shared_ptr<Renderer> &sharedPtr) {
    if (!ecsManager->hasSystem<CommandLogSystem>()){
        return;
    }
    auto commands = ecsManager->getSystem<CommandLogSystem>().getCommands();
    for (auto command : commands){

    }
}


void TerminalRenderSystem::renderUnderscore(Entity entity, const std::shared_ptr<Renderer>& renderer) {
    if (!isTerminalLive){
        return;
    }

    auto& positionComponent = ecsManager->getComponentFromEntity<FixedPositionComponent>(entity);
    const auto textComponent = ecsManager->getComponentFromEntity<TextComponent>(entity);
    const auto styleComponent = ecsManager->getComponentFromEntity<StyleComponent>(entity);

    float textXLength = (float)currentText.size() * TERMINAL_MONACO_TEXT_WIDTH_SCALER;
    if (showUnderscore > 30){
        Position submittedPosition = positionComponent.position + Position(TEXT_OFFSET + textXLength, UNDERSCORE_Y_OFFSET);
        auto unusedCamera = Camera(Position(0,0));
        renderer->renderText(unusedCamera, submittedPosition, textComponent, styleComponent);
    }
    showUnderscore += 1;
    showUnderscore = showUnderscore % 60;
}

void TerminalRenderSystem::onTerminalRender(TerminalTextUpdateEvent& event) {
    currentText = event.text;
}

void TerminalRenderSystem::onTakingInputFlip(TakingInputFlipEvent& event) {
    isTerminalLive = !isTerminalLive;
}




/*
 *
void SDLRenderer::renderTerminalLineStart() {
    FC_Draw(terminalFont, renderer, TERMINAL_X_START, TERMINAL_Y_START, ">");
}


void SDLRenderer::renderTerminalText(const std::string& text) {
    FC_Draw(terminalFont, renderer, TERMINAL_X_START + TEXT_OFFSET, TERMINAL_Y_START, text.c_str());
}

void SDLRenderer::renderFlashingUnderscore(const std::string& text) {
    float textXLength = (float)text.size() * TERMINAL_MONACO_TEXT_WIDTH_SCALER;
    if (showUnderscore > 30){
        FC_Draw(terminalFont, renderer, TERMINAL_X_START + TEXT_OFFSET + textXLength,
                TERMINAL_Y_START + UNDERSCORE_Y_OFFSET, "_");
    }
    showUnderscore += 1;
    showUnderscore = showUnderscore % 60;
}
 */