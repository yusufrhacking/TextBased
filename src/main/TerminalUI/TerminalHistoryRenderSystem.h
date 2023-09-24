#ifndef TEXTBASED_TERMINALHISTORYRENDERSYSTEM_H
#define TEXTBASED_TERMINALHISTORYRENDERSYSTEM_H
#include "../Rendering/RenderSystem.h"
#include "../TextCommands/AuthoredCommand.h"
#include "TerminalRenderer.h"

class TerminalHistoryRenderSystem: public RenderSystem {
private:
    int maxLinesShown = 6;
    int typedTextInd = 0;
    int typeNewCharacterThreshold = 60;
    int typeNewCharacter = 0;
    std::string prevLine;
    TerminalRenderer terminalRenderer;
    Position startingTerminalPosition;
    void renderLines(const std::shared_ptr<Renderer>& renderer, const std::vector<AuthoredCommand>& authoredCommands);
    void renderAuthoredCommand(const std::shared_ptr<Renderer>& renderer, float lineCount, AuthoredCommand authoredCommand);
public:
    TerminalHistoryRenderSystem(Position startingTerminalPosition): startingTerminalPosition(startingTerminalPosition) {}
    void render(const std::shared_ptr<Renderer>& renderer, Camera camera) override;

    Style getStyle(Author author);

    void
    renderTypedLine(const std::shared_ptr<Renderer> &renderer, Position position, const std::string& commandText, Style style);
};


#endif //TEXTBASED_TERMINALHISTORYRENDERSYSTEM_H
