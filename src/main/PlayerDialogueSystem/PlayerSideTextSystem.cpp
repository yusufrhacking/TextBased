#include "PlayerSideTextSystem.h"
#include "../HighLevel/ECSManager.h"
#include "../MainPlayer/MainPlayerAccessSystem.h"
#include "../MainPlayer/MainPlayerComponent.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../TextCommands/CommandLogSystem.h"


extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;
TextComponent textComponent("");

PlayerSideTextSystem::PlayerSideTextSystem() {
    listenToEvents();
    requireComponent<MainPlayerComponent>();
}

void PlayerSideTextSystem::listenToEvents() {
    eventBus->listenToEvent<TextCommandEvent>(this, &PlayerSideTextSystem::onCommand);
}

void PlayerSideTextSystem::onCommand(TextCommandEvent &event) {
    commands.emplace_back(Author::PLAYER, event.command);
    textComponent.text = event.command.getFullCommandText();
    isTextVisible = true;
    frameCounter = 0;
}

void PlayerSideTextSystem::render(const std::shared_ptr<Renderer>& renderer, Camera camera) {
    if (!isTextVisible) {
        return;
    }

    frameCounter++;

    if (frameCounter >= 180) {
        isTextVisible = false;
        textComponent.text = "";
        return;
    }

    Entity player = ecsManager->getSystem<MainPlayerAccessSystem>().getMainPlayer();
    auto& positionComponent = ecsManager->getComponentFromEntity<PositionComponent>(player);
    auto styleComponent = GenericStyleComponent(Type::PLAYER_SIDE_TEXT);
    Position pos = Position(0, 25);
    renderer->renderDynamicText(camera, positionComponent.getPosition() + pos, textComponent, styleComponent);
}



//Position PlayerSideTextSystem::getPlayerPosition() {
//    Entity player = ecsManager->getSystem<MainPlayerAccessSystem>().getMainPlayer();
//    PositionComponent position_component = ecsManager->getComponentFromEntity<PositionComponent>(player);
//    Position position = position_component.getPosition();
//    return position;
//}

