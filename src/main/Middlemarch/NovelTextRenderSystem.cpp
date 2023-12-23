#include "NovelTextRenderSystem.h"
#include "../PositionsAndMovement/PositionComponent.h"

NovelTextRenderSystem::NovelTextRenderSystem() {
    requireComponent<TextComponent>();
    requireComponent<NovelTextComponent>();
    requireComponent<PositionComponent>();
}

void NovelTextRenderSystem::render(const std::shared_ptr<Renderer> &renderer) {
    for(auto entity: getRelevantEntities()){


        renderer->renderNovelText()

    }
}


