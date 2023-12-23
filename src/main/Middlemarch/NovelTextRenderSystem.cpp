#include "NovelTextRenderSystem.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../HighLevel/ECSManager.h"

extern std::unique_ptr<ECSManager> ecsManager;

NovelTextRenderSystem::NovelTextRenderSystem() {
    requireComponent<TextComponent>();
    requireComponent<NovelTextComponent>();
    requireComponent<PositionComponent>();
}

void NovelTextRenderSystem::render(const std::shared_ptr<Renderer> &renderer) {
    for(auto entity: getRelevantEntities()){
        auto positionComponent = ecsManager->getComponentFromEntity<PositionComponent>(entity);
        auto textComponent = ecsManager->getComponentFromEntity<TextComponent>(entity);
        auto novelTextComponent = ecsManager->getComponentFromEntity<NovelTextComponent>(entity);

        renderer->renderNovelText(positionComponent.getPosition(), textComponent, novelTextComponent);
    }
}


