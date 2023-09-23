#ifndef TEXTBASED_TERMINALHISTORYRENDERSYSTEM_H
#define TEXTBASED_TERMINALHISTORYRENDERSYSTEM_H
#include "../Rendering/RenderSystem.h"
#include "../TextCommands/AuthoredCommand.h"

class TerminalHistoryRenderSystem: public RenderSystem {
private:
    int maxLinesShown = 6;
    Camera unusedCamera{Position{0,0}};
    Position startingTerminalPosition;
    void renderLines(std::vector<AuthoredCommand> commands);
public:
    TerminalHistoryRenderSystem(Position startingTerminalPosition): startingTerminalPosition(startingTerminalPosition) {}
    void render(const std::shared_ptr<Renderer>& renderer, Camera camera) override;
};


#endif //TEXTBASED_TERMINALHISTORYRENDERSYSTEM_H
