#include "SubjectRenderSystem.h"

#include "SubjectComponent.h"
#include "../HighLevel/ECSManager.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../PositionsAndMovement/LiveComponent.h"

extern std::unique_ptr<ECSManager> ecsManager;

SubjectRenderSystem::SubjectRenderSystem() {
    requireComponent<PositionComponent>();
    requireComponent<TextComponent>();
    requireComponent<SubjectComponent>();
    requireComponent<LiveComponent>();
}

void SubjectRenderSystem::render(const std::shared_ptr<Renderer>& renderer, Camera camera){
    for (auto entity : getRelevantEntities()){
        auto& positionComponent = ecsManager->getComponentFromEntity<PositionComponent>(entity);
        const auto textComponent = ecsManager->getComponentFromEntity<TextComponent>(entity);
        renderer->renderDynamicText(camera, positionComponent.getPosition(), textComponent, GenericStyleComponent(RenderStyle::GOLD));
    }
}