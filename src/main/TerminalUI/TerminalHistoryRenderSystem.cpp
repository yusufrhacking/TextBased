#include "TerminalHistoryRenderSystem.h"
#include "../TextCommands/CommandLogSystem.h"
#include "../HighLevel/ECSManager.h"
#include "LiveTerminalRenderSystem.h"
#include <spdlog/spdlog.h>
#include "../HighLevel/TerminalGlobals.h"


extern std::unique_ptr<ECSManager> ecsManager;

void TerminalHistoryRenderSystem::render(const std::shared_ptr<Renderer> &renderer) {
    auto authoredCommands = ecsManager->getSystem<CommandLogSystem>().getAuthoredCommands();
    renderLines(renderer, authoredCommands);
}

void TerminalHistoryRenderSystem::render(const std::shared_ptr<Renderer> &renderer,
                                         const std::vector<AuthoredCommand>& authoredCommands) {
    renderLines(renderer, authoredCommands);
}

void TerminalHistoryRenderSystem::renderLines(const std::shared_ptr<Renderer>& renderer, const std::vector<AuthoredCommand>& authoredCommands) {
    size_t totalCommands = authoredCommands.size();
    size_t start = totalCommands > maxLinesShown ? totalCommands - maxLinesShown : 0;

    for (size_t i = start; i < totalCommands; ++i) {
        const auto& authoredCommand = authoredCommands[i];
        renderAuthoredCommand(renderer, static_cast<float>(totalCommands - i), authoredCommand);
    }
}

void TerminalHistoryRenderSystem::renderAuthoredCommand(const std::shared_ptr<Renderer>& renderer, float lineCount, const AuthoredCommand& authoredCommand) {
    auto type = getType(authoredCommand.author);

    auto authorText = AuthorCommands::authorToText(authoredCommand.author);
    auto startingPosition = startingTerminalPosition + Position((float)0, (TERMINAL_LINE_VERTICAL_OFFSET * lineCount) * -1);

    startingPosition = terminalRenderer.renderAuthor(renderer, startingPosition, authorText, GenericStyleComponent(type));

    if (isLowestLine(lineCount) && type == Type::ENGINEER_TERMINAL_TEXT){
        renderTypedLine(renderer, startingPosition, authoredCommand.command.getFullCommandText(), type);
    }
    else{
        terminalRenderer.renderText(renderer, startingPosition, authoredCommand.command.getFullCommandText(), GenericStyleComponent(type));
    }
}

Type TerminalHistoryRenderSystem::getType(Author author) {
    switch (author) {
        case Author::PLAYER:
            return Type::PLAIN_TERMINAL_TEXT;
        case Author::ENGINEER:
            return Type::ENGINEER_TERMINAL_TEXT;
        case Author::BRICOLEUR:
            return Type::BRICOLEUR_TERMINAL_TEXT;
    }
}

void TerminalHistoryRenderSystem::renderTypedLine(const std::shared_ptr<Renderer> &renderer, Position position,
                                                  const std::string& commandText, Type type) {
    auto currentTime = std::chrono::steady_clock::now();
    auto timeDiff = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastUpdateTime);

    if (!prevLine.empty() && prevLine != commandText){
        typedTextInd = 0;
        typeNewCharacter = 0;
        lastUpdateTime = currentTime;
    }

    if (timeDiff.count() >= typingDelayMilliseconds) {
        if (typedTextInd < commandText.size()){
            typedTextInd++;
        }
        lastUpdateTime = currentTime;
    }

    std::string displayedText = commandText.substr(0, typedTextInd);
    terminalRenderer.renderText(renderer, position, displayedText, GenericStyleComponent(type));
    prevLine = commandText;
}

bool TerminalHistoryRenderSystem::isLowestLine(float lineCount) {
    return lineCount == 1;
}
