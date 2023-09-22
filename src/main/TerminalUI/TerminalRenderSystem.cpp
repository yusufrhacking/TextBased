#include <spdlog/spdlog.h>
#include "TerminalRenderSystem.h"
#include "FixedPositionComponent.h"
#include "../Rendering/StyleComponent.h"
#include "../HighLevel/ECSManager.h"

extern std::unique_ptr<ECSManager> ecsManager;

float TerminalRenderSystem::TERMINAL_X_START = 30;
float TerminalRenderSystem::BOTTOM_WINDOW_OFFSET = 110;
float TerminalRenderSystem::TERMINAL_Y_START = (float)Window::windowHeight - (BOTTOM_WINDOW_OFFSET-TERMINAL_MONACO_HEIGHT_LINE_OF_TEXT);
float TerminalRenderSystem::TERMINAL_INIT_X_OFFSET = 35;
float TerminalRenderSystem::UNDERSCORE_Y_OFFSET = 3;
float TerminalRenderSystem::TEXT_OFFSET = 30;

TerminalRenderSystem::TerminalRenderSystem() {
    requireComponent<FixedPositionComponent>();
    requireComponent<StyleComponent>();
    requireComponent<TextComponent>();
    auto signature = getComponentSignature().getSignature();
    for (std::size_t index = 0; index < signature.size(); ++index) {
        if (signature[index]) spdlog::debug("Yes component {}", index);
    }


}

void TerminalRenderSystem::render(const std::shared_ptr<Renderer> &renderer, Camera camera) {
    for (auto entity : getRelevantEntities()){
        auto& positionComponent = ecsManager->getComponentFromEntity<FixedPositionComponent>(entity);
        const auto textComponent = ecsManager->getComponentFromEntity<TextComponent>(entity);
        const auto styleComponent = ecsManager->getComponentFromEntity<StyleComponent>(entity);
        renderer->renderText(camera, positionComponent.position, textComponent, styleComponent);
    }
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