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
        const auto& textComponent = ecsManager->getComponentFromEntity<TextComponent>(entity);
        const auto& propositionComponent = ecsManager->getComponentFromEntity<PropositionComponent>(entity);

        GenericStyleComponent style = getStyleFromProposition(propositionComponent);


        renderer->renderDynamicText(camera, positionComponent.getPosition(), textComponent, style);
    }
}

GenericStyleComponent PropositionRenderSystem::getStyleFromProposition(const PropositionComponent &component) {
    switch(component.layer){
        case TractatusLayer::ONE: return GenericStyleComponent(RenderStyle::WHITE_ONE);
        case TractatusLayer::TWO: return GenericStyleComponent(RenderStyle::WHITE_TWO);
        case TractatusLayer::THREE: return GenericStyleComponent(RenderStyle::WHITE_THREE);
        case TractatusLayer::FOUR: return GenericStyleComponent(RenderStyle::WHITE_FOUR);
        case TractatusLayer::FIVE: return GenericStyleComponent(RenderStyle::WHITE_FIVE);
        case TractatusLayer::SIX: return GenericStyleComponent(RenderStyle::WHITE_SIX);
        case TractatusLayer::SEVEN: return GenericStyleComponent(RenderStyle::WHITE_SEVEN);
        default: return GenericStyleComponent(RenderStyle::GREEN_TERMINAL);
    }}
