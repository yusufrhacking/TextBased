#include <spdlog/spdlog.h>
#include "TerminalRenderSystem.h"
#include "FixedPositionComponent.h"
#include "../Rendering/StyleComponent.h"
#include "../HighLevel/ECSManager.h"
#include "TerminalUnderscoreComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;

float TerminalRenderSystem::TERMINAL_X_START = 30;
float TerminalRenderSystem::BOTTOM_WINDOW_OFFSET = 110;
float TerminalRenderSystem::TERMINAL_INIT_X_OFFSET = 35;
float TerminalRenderSystem::UNDERSCORE_Y_OFFSET = 3;
float TerminalRenderSystem::TEXT_OFFSET = 30;

TerminalRenderSystem::TerminalRenderSystem() {
    requireComponent<FixedPositionComponent>();
    requireComponent<StyleComponent>();
    requireComponent<TextComponent>();
}

void TerminalRenderSystem::render(const std::shared_ptr<Renderer> &renderer, Camera camera) {
    for (auto entity : getRelevantEntities()){
        auto& positionComponent = ecsManager->getComponentFromEntity<FixedPositionComponent>(entity);
        const auto textComponent = ecsManager->getComponentFromEntity<TextComponent>(entity);
        const auto styleComponent = ecsManager->getComponentFromEntity<StyleComponent>(entity);
        if (ecsManager->hasComponent<TerminalUnderscoreComponent>(entity)){
            float textXLength = (float)currentText.size() * TERMINAL_MONACO_TEXT_WIDTH_SCALER;
            if (showUnderscore > 30){
                Position submittedPosition = positionComponent.position + Position(TEXT_OFFSET + textXLength, UNDERSCORE_Y_OFFSET);
                renderer->renderText(camera, submittedPosition, textComponent, styleComponent);
            }
            showUnderscore += 1;
            showUnderscore = showUnderscore % 60;
        } else{
            renderer->renderText(camera, positionComponent.position, textComponent, styleComponent);
        }
    }
//    handleUnderscore(const std::string& text);
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