#include "TerminalHistoryRenderSystem.h"
#include "../TextCommands/CommandLogSystem.h"
#include "../HighLevel/ECSManager.h"
#include "LiveTerminalRenderSystem.h"
#include <__ranges/reverse_view.h>
#include <spdlog/spdlog.h>

extern std::unique_ptr<ECSManager> ecsManager;

void TerminalHistoryRenderSystem::render(const std::shared_ptr<Renderer> &renderer) {
    auto authoredCommands = ecsManager->getSystem<CommandLogSystem>().getAuthoredCommands();
    renderLines(renderer, authoredCommands);
}

void TerminalHistoryRenderSystem::renderLines(const std::shared_ptr<Renderer>& renderer, const std::vector<AuthoredCommand>& authoredCommands) {
    float lineCount = 1;
    for (auto & authoredCommand : std::ranges::reverse_view(authoredCommands)){
        renderAuthoredCommand(renderer, lineCount, authoredCommand);
        lineCount++;
        if ((int)lineCount > maxLinesShown){
            return;
        }
    }
}

void TerminalHistoryRenderSystem::renderAuthoredCommand(const std::shared_ptr<Renderer>& renderer, float lineCount, AuthoredCommand authoredCommand) {
    Style style = getStyle(authoredCommand.author);

    auto authorText = AuthorCommands::authorToText(authoredCommand.author);
    auto startingPosition = startingTerminalPosition + Position((float)0, (TERMINAL_LINE_VERTICAL_OFFSET * lineCount) * -1);

    startingPosition = terminalRenderer.renderAuthor(renderer, startingPosition, authorText, style);
    startingPosition = terminalRenderer.renderPromptSymbol(renderer, startingPosition, style);

    if (isLowestLine(lineCount) && style == Style::ENGINEER_TERMINAL){
        renderTypedLine(renderer, startingPosition, authoredCommand.command.getFullCommandText(), style);
    }
    else{
        terminalRenderer.renderText(renderer, startingPosition, authoredCommand.command.getFullCommandText(), style);
    }
}

Style TerminalHistoryRenderSystem::getStyle(Author author) {
    switch (author) {
        case Author::PLAYER:
            return Style::OLD_TERMINAL_COMMAND;
        case Author::ENGINEER:
            return Style::ENGINEER_TERMINAL;
        case Author::BRICOLEUR:
            return Style::ENGINEER_TERMINAL;
    }
}

void TerminalHistoryRenderSystem::renderTypedLine(const std::shared_ptr<Renderer> &renderer, Position position,
                                                  const std::string& commandText, Style style) {
    if (!prevLine.empty() && prevLine != commandText){
        typedTextInd = 0;
        typeNewCharacter = 0;
    }
    if (typeNewCharacter > typedFramePerNewCharacter){
        if (typedTextInd < commandText.size()){
            typedTextInd++;
        }
        typeNewCharacter = 0;
    }
    std::string displayedText = commandText.substr(0, typedTextInd);
    terminalRenderer.renderText(renderer, position, displayedText, style);
    typeNewCharacter++;
    prevLine = commandText;
}

bool TerminalHistoryRenderSystem::isLowestLine(float lineCount) {
    return lineCount == 1;
}
