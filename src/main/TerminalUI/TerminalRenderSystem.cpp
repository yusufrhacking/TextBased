#include "TerminalRenderSystem.h"
#include "FixedPositionComponent.h"
#include "../Rendering/StyleComponent.h"
#include "../HighLevel/ECSManager.h"

extern std::unique_ptr<ECSManager> ecsManager;

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
        renderer->renderText(camera, positionComponent.position, textComponent, styleComponent);
    }
}
