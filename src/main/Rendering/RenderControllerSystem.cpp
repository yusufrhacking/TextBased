#include "RenderControllerSystem.h"
#include "../HighLevel/ECSManager.h"
#include "FixedRenderSystem.h"
#include "DynamicRenderSystem.h"

extern std::unique_ptr<ECSManager> ecsManager;

void RenderControllerSystem::render(const std::shared_ptr<Renderer> &renderer, Camera camera) {
    for(const auto& system: ecsManager->getSystemsOfType<FixedRenderSystem>()){
        system->render(renderer);
    }
    for(const auto& system: ecsManager->getSystemsOfType<DynamicRenderSystem>()){
        system->render(renderer, camera);
    }
}
