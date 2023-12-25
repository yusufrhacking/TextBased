#include "RenderControllerSystem.h"
#include "../HighLevel/ECSManager.h"
#include "EntityRenderSystem.h"
#include "FixedRenderSystem.h"
#include "DynamicRenderSystem.h"
#include "../TerminalUI/LiveTerminalRenderSystem.h"
#include "../TerminalUI/TerminalHistoryRenderSystem.h"
#include "../Lettering/LetterBankRenderSystem.h"
#include "../TextCommands/CommandLogSystem.h"
#include "../Inventory/InventoryRenderSystem.h"
#include "../MainPlayer/MainPlayerAccessSystem.h"
#include "../Inventory/InventoryComponent.h"
#include "../PlayerDialogueSystem/PlayerSideTextSystem.h"
#include "../Health/HealthBarRenderSystem.h"
#include "../Middlemarch/NovelTextRenderSystem.h"

extern std::unique_ptr<ECSManager> ecsManager;

void RenderControllerSystem::render(const std::shared_ptr<Renderer> &renderer, Camera camera) {
    ecsManager->getSystem<EntityRenderSystem>().render(renderer, camera);

    // auto authoredCommands = ecsManager->getSystem<CommandLogSystem>().getAuthoredCommands();
    // ecsManager->getSystem<TerminalHistoryRenderSystem>().render(renderer, authoredCommands);
    // ecsManager->getSystem<LiveTerminalRenderSystem>().render(renderer);
    // if (ecsManager->hasSystem<LetterBankRenderSystem>()) {
    //     ecsManager->getSystem<LetterBankRenderSystem>().render(renderer);
    // }

    if (ecsManager->hasSystem<PlayerSideTextSystem>()){
        ecsManager->getSystem<PlayerSideTextSystem>().render(renderer, camera);
    }

    if (ecsManager->getSystem<MainPlayerAccessSystem>().hasMainPlayer()){
        auto mainPlayer = ecsManager->getSystem<MainPlayerAccessSystem>().getMainPlayer();
        auto inventory = ecsManager->getComponentFromEntity<InventoryComponent>(mainPlayer).inventory;
        if (ecsManager->hasSystem<InventoryRenderSystem>()) {
            ecsManager->getSystem<InventoryRenderSystem>().render(renderer, inventory);
        }

        if (ecsManager->hasSystem<HealthBarRenderSystem>()){
            auto healthComponent = ecsManager->getComponentFromEntity<HealthComponent>(mainPlayer);
            ecsManager->getSystem<HealthBarRenderSystem>().render(renderer, healthComponent);
        }
    }

    if (ecsManager->hasSystem<NovelTextRenderSystem>()){
        ecsManager->getSystem<NovelTextRenderSystem>().render(renderer, camera);
    }
}

RenderControllerSystem::RenderControllerSystem() {
    Position startingTerminalPosition = {TERMINAL_X_START,(float)Window::windowHeight - (BOTTOM_WINDOW_OFFSET - TERMINAL_MONACO_HEIGHT_LINE_OF_TEXT)};
    ecsManager->addSystem<EntityRenderSystem>();
    ecsManager->addSystem<LiveTerminalRenderSystem>(startingTerminalPosition);
    ecsManager->addSystem<TerminalHistoryRenderSystem>(startingTerminalPosition);
    ecsManager->addSystem<InventoryRenderSystem>();
    ecsManager->addSystem<HealthBarRenderSystem>();
    ecsManager->addSystem<NovelTextRenderSystem>();
    // ecsManager->addSystem<PlayerSideTextSystem>();
}
