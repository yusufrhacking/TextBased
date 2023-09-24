#include "LetterBankRenderSystem.h"
#include "../HighLevel/ECSManager.h"
#include "CharacterDepositEvent.h"
#include "CharacterStorageSystem.h"

extern std::unique_ptr<ECSManager> ecsManager;

void LetterBankRenderSystem::render(const std::shared_ptr<Renderer> &renderer, Camera camera) {
    renderLetterBox(renderer);
    auto letterAllocations = ecsManager->getSystem<CharacterStorageSystem>().getAlphabet();
}

void LetterBankRenderSystem::renderLetterBox(const std::shared_ptr<Renderer> &renderer) {
    renderer->renderText(unusedCamera, letterBoxPosition, TextComponent(letterBankText), StyleComponent(Style::WHITE_MONACO_GENERIC));
}
