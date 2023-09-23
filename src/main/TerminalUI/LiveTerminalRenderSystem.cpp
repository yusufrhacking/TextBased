#include <spdlog/spdlog.h>

#include <ranges>
#include "TerminalTextUpdateEvent.h"
#include "LiveTerminalRenderSystem.h"
#include "FixedPositionComponent.h"
#include "../Rendering/StyleComponent.h"
#include "../HighLevel/ECSManager.h"
#include "TerminalUnderscoreComponent.h"
#include "../TextCommands/CommandLogSystem.h"

extern std::unique_ptr<ECSManager> ecsManager;
extern std::unique_ptr<EventBus> eventBus;

float LiveTerminalRenderSystem::TERMINAL_X_START = 30;
float LiveTerminalRenderSystem::BOTTOM_WINDOW_OFFSET = 110;
float LiveTerminalRenderSystem::TERMINAL_INIT_X_OFFSET = 35;
float LiveTerminalRenderSystem::UNDERSCORE_Y_OFFSET = 3;
float LiveTerminalRenderSystem::TEXT_OFFSET = 30;

LiveTerminalRenderSystem::LiveTerminalRenderSystem() {
    eventBus->listenToEvent<TerminalTextUpdateEvent>(this, &LiveTerminalRenderSystem::onTerminalRender);
    eventBus->listenToEvent<TakingInputFlipEvent>(this, &LiveTerminalRenderSystem::onTakingInputFlip);

    startingTerminalPosition = Position(TERMINAL_X_START,
                                                 (float)Window::windowHeight - (LiveTerminalRenderSystem::BOTTOM_WINDOW_OFFSET - TERMINAL_MONACO_HEIGHT_LINE_OF_TEXT));
}

void LiveTerminalRenderSystem::render(const std::shared_ptr<Renderer> &renderer, Camera camera) {
//    renderHistoricLines(renderer);
    renderLiveLine(renderer);
}

void LiveTerminalRenderSystem::renderLiveLine(const std::shared_ptr<Renderer> &renderer) {
    renderUnderscore(renderer);
    for (auto entity : getRelevantEntities()){
        if (ecsManager->hasComponent<TerminalUnderscoreComponent>(entity)) {
            renderUnderscore(entity, renderer);
        } else{
            auto& positionComponent = ecsManager->getComponentFromEntity<FixedPositionComponent>(entity);
            const auto textComponent = ecsManager->getComponentFromEntity<TextComponent>(entity);
            const auto styleComponent = ecsManager->getComponentFromEntity<StyleComponent>(entity);
            renderer->renderText(unusedCamera, positionComponent.position, textComponent, styleComponent);
        }
    }
    auto terminalTextC = TextComponent(currentText);
    auto position = Position(TERMINAL_X_START + TEXT_OFFSET, TERMINAL_Y_START);
    renderer->renderText(unusedCamera, position, terminalTextC, StyleComponent(Style::TERMINAL));
}

void LiveTerminalRenderSystem::renderHistoricLines(const std::shared_ptr<Renderer> &renderer) {
    if (!ecsManager->hasSystem<CommandLogSystem>()) {
        return;
    }
    auto authoredCommands = ecsManager->getSystem<CommandLogSystem>().getAuthoredCommands();

    float lineCount = 1;
    for (auto & authoredCommand : std::ranges::reverse_view(authoredCommands)){
        renderAuthoredCommand(renderer, lineCount, authoredCommand);

        lineCount++;
        if (lineCount > 6){
            return;
        }
    }
}

void LiveTerminalRenderSystem::renderAuthoredCommand(const std::shared_ptr<Renderer> &renderer, float lineCount,
                                                     AuthoredCommand authoredCommand) const {
    auto authorText = AuthorCommands::authorToText(authoredCommand.author);
    auto commandText = authoredCommand.command.getFullCommandText();
    auto terminalTextC = TextComponent(commandText);

    float xPosition = TERMINAL_X_START + TEXT_OFFSET + (float)authorText.size()*TERMINAL_MONACO_TEXT_WIDTH_SCALER;
    float yPosition = TERMINAL_Y_START - (TERMINAL_LINE_VERTICAL_OFFSET * lineCount);
    auto position = Position(xPosition, yPosition);


    switch (authoredCommand.author){
        case Author::PLAYER:
            renderer->renderText(unusedCamera, position, terminalTextC,
                                 StyleComponent(Style::OLD_TERMINAL_COMMAND));
            break;
        case Author::ENGINEER:
            renderer->renderText(unusedCamera, position, terminalTextC,
                                 StyleComponent(Style::ENGINEER_TERMINAL));
            break;
        case Author::BRICOLEUR: break;
    }
}


void LiveTerminalRenderSystem::renderUnderscore(const std::shared_ptr<Renderer>& renderer) {
    if (!isTerminalLive){
        return;
    }

    float textXLength = (float)currentText.size() * TERMINAL_MONACO_TEXT_WIDTH_SCALER;
    auto submittedPosition = startingTerminalPosition + Position(TEXT_OFFSET + textXLength, UNDERSCORE_Y_OFFSET);

    if (showUnderscore > 30){
        renderer->renderText(unusedCamera, submittedPosition, TextComponent("_"), StyleComponent(Style::TERMINAL));
    }
    showUnderscore += 1;
    showUnderscore = showUnderscore % 60;
}

void LiveTerminalRenderSystem::onTerminalRender(TerminalTextUpdateEvent& event) {
    currentText = event.text;
}

void LiveTerminalRenderSystem::onTakingInputFlip(TakingInputFlipEvent& event) {
    isTerminalLive = !isTerminalLive;
}