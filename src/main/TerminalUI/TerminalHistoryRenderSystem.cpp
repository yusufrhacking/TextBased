#include "TerminalHistoryRenderSystem.h"


void TerminalHistoryRenderSystem::render(const std::shared_ptr<Renderer> &renderer, Camera camera) {

}

void TerminalHistoryRenderSystem::renderLines(std::vector<AuthoredCommand> commands) {

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

