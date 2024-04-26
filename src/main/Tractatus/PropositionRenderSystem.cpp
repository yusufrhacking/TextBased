#include "PropositionRenderSystem.h"
#include "../HighLevel/ECSManager.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../PositionsAndMovement/LiveComponent.h"
#include "PropositionComponent.h"
extern std::unique_ptr<ECSManager> ecsManager;

PropositionRenderSystem::PropositionRenderSystem() {
    requireComponent<PositionComponent>();
    requireComponent<TextComponent>();
    requireComponent<PropositionComponent>();
    requireComponent<LiveComponent>();
}

void PropositionRenderSystem::render(const std::shared_ptr<Renderer> &renderer, Camera camera) {
    for (auto entity : getRelevantEntities()){
        auto& positionComponent = ecsManager->getComponentFromEntity<PositionComponent>(entity);
        const auto textComponent = ecsManager->getComponentFromEntity<TextComponent>(entity);
        renderer->renderDynamicText(camera, positionComponent.getPosition(), textComponent, GenericStyleComponent(RenderStyle::RED));
    }
}
