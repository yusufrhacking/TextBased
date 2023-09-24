#include "TerminalHistoryRenderSystem.h"
#include "../TextCommands/CommandLogSystem.h"
#include "../HighLevel/ECSManager.h"
#include "LiveTerminalRenderSystem.h"
#include <__ranges/reverse_view.h>

extern std::unique_ptr<ECSManager> ecsManager;

void TerminalHistoryRenderSystem::render(const std::shared_ptr<Renderer> &renderer, Camera camera) {
    auto authoredCommands = ecsManager->getSystem<CommandLogSystem>().getAuthoredCommands();
    renderLines(renderer, authoredCommands);
}

void TerminalHistoryRenderSystem::renderLines(const std::shared_ptr<Renderer>& renderer, const std::vector<AuthoredCommand>& authoredCommands) {
    float lineCount = 1;
    for (auto & authoredCommand : std::ranges::reverse_view(authoredCommands)){
        renderAuthoredCommand(renderer, lineCount, authoredCommand);
        lineCount++;
        if (lineCount > 6){
            return;
        }
    }
}

void TerminalHistoryRenderSystem::renderAuthoredCommand(const std::shared_ptr<Renderer>& renderer, float lineCount, AuthoredCommand authoredCommand) {
    auto authorText = AuthorCommands::authorToText(authoredCommand.author);
    auto commandText = authoredCommand.command.getFullCommandText();
    auto terminalTextC = TextComponent(commandText);

    auto position = startingTerminalPosition + Position(TEXT_OFFSET, TERMINAL_LINE_VERTICAL_OFFSET * lineCount);


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