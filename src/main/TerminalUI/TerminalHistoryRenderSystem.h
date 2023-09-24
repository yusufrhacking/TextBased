#ifndef TEXTBASED_TERMINALHISTORYRENDERSYSTEM_H
#define TEXTBASED_TERMINALHISTORYRENDERSYSTEM_H
#include "../Rendering/RenderSystem.h"
#include "../TextCommands/AuthoredCommand.h"
#include "TerminalRenderer.h"

class TerminalHistoryRenderSystem: public RenderSystem {
private:
    int maxLinesShown = 6;
    TerminalRenderer terminalRenderer;
    Position startingTerminalPosition;
    void renderLines(const std::shared_ptr<Renderer>& renderer, const std::vector<AuthoredCommand>& authoredCommands);
    void renderAuthoredCommand(const std::shared_ptr<Renderer>& renderer, float lineCount, AuthoredCommand authoredCommand);
public:
    TerminalHistoryRenderSystem(Position startingTerminalPosition): startingTerminalPosition(startingTerminalPosition) {}
    void render(const std::shared_ptr<Renderer>& renderer, Camera camera) override;

    Style getStyle(Author author);
};


#endif //TEXTBASED_TERMINALHISTORYRENDERSYSTEM_H
