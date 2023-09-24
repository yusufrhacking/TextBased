#ifndef TEXTBASED_TERMINALRENDERER_H
#define TEXTBASED_TERMINALRENDERER_H

#include <memory>
#include "../Rendering/Renderer.h"


class TerminalRenderer {
private:
    Camera unusedCamera{Position{0,0}};
    bool isTerminalLive = false;
    int showUnderscore = 0;

public:
    Position renderAuthor(const std::shared_ptr<Renderer> &renderer, Position startingPosition, const std::string& authorStr);

    Position renderPromptSymbol(const std::shared_ptr<Renderer> &renderer, Position startingPosition);

    Position renderLiveText(const std::shared_ptr<Renderer> &renderer, Position startingPosition, const std::string& currText);

    Position renderUnderscore(const std::shared_ptr<Renderer> &renderer, Position startingPosition, const std::string& currText);
};


#endif //TEXTBASED_TERMINALRENDERER_H
