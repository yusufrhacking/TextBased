#include "RenderControllerSystem.h"
#include "../HighLevel/ECSManager.h"
#include "EntityRenderSystem.h"
#include "FixedRenderSystem.h"
#include "DynamicRenderSystem.h"
#include "../TerminalUI/LiveTerminalRenderSystem.h"
#include "../TerminalUI/TerminalHistoryRenderSystem.h"
#include "../Lettering/LetterBankRenderSystem.h"
#include "../TextCommands/CommandLogSystem.h"

extern std::unique_ptr<ECSManager> ecsManager;

void RenderControllerSystem::render(const std::shared_ptr<Renderer> &renderer, Camera camera) {
    ecsManager->getSystem<EntityRenderSystem>().render(renderer, camera);

    auto authoredCommands = ecsManager->getSystem<CommandLogSystem>().getAuthoredCommands();
    ecsManager->getSystem<TerminalHistoryRenderSystem>().render(renderer, authoredCommands);
    ecsManager->getSystem<LiveTerminalRenderSystem>().render(renderer);
    if (ecsManager->hasSystem<LetterBankRenderSystem>()) ecsManager->getSystem<LetterBankRenderSystem>().render(renderer);
}

RenderControllerSystem::RenderControllerSystem() {
    Position startingTerminalPosition = {TERMINAL_X_START,(float)Window::windowHeight - (BOTTOM_WINDOW_OFFSET - TERMINAL_MONACO_HEIGHT_LINE_OF_TEXT)};
    ecsManager->addSystem<EntityRenderSystem>();
    ecsManager->addSystem<LiveTerminalRenderSystem>(startingTerminalPosition);
    ecsManager->addSystem<TerminalHistoryRenderSystem>(startingTerminalPosition);
}