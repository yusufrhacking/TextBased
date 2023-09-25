#ifndef TEXTBASED_TERMINALHISTORYRENDERSYSTEM_H
#define TEXTBASED_TERMINALHISTORYRENDERSYSTEM_H
#include "../Rendering/DynamicRenderSystem.h"
#include "../TextCommands/AuthoredCommand.h"
#include "TerminalRenderer.h"
#include "../Rendering/FixedRenderSystem.h"

class TerminalHistoryRenderSystem: public FixedRenderSystem {
private:
    int maxLinesShown = 6;
    int typedTextInd = 0;
    int typedFramePerNewCharacter = 10;
    int typeNewCharacter = 0;
    std::string prevLine;
    TerminalRenderer terminalRenderer;
    Position startingTerminalPosition;
    void renderLines(const std::shared_ptr<Renderer>& renderer, const std::vector<AuthoredCommand>& authoredCommands);
    void renderAuthoredCommand(const std::shared_ptr<Renderer>& renderer, float lineCount, const AuthoredCommand& authoredCommand);
public:
    TerminalHistoryRenderSystem(Position startingTerminalPosition): startingTerminalPosition(startingTerminalPosition) {}
    void render(const std::shared_ptr<Renderer>& renderer) override;
    void render(const std::shared_ptr<Renderer>& renderer, const std::vector<AuthoredCommand>& authoredCommands);

    Type getType(Author author);

    void
    renderTypedLine(const std::shared_ptr<Renderer> &renderer, Position position, const std::string& commandText, Type type);

    bool isLowestLine(float lineCount);
};


#endif //TEXTBASED_TERMINALHISTORYRENDERSYSTEM_H
