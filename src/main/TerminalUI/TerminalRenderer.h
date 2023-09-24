#ifndef TEXTBASED_TERMINALRENDERER_H
#define TEXTBASED_TERMINALRENDERER_H

#include <memory>
#include "../Rendering/Renderer.h"


class TerminalRenderer {
private:
    Camera unusedCamera{Position{0,0}};
    int showUnderscore = 0;
    int typedTextInd = 0;

public:
    TerminalRenderer() = default;
    Position renderAuthor(const std::shared_ptr<Renderer> &renderer, Position startingPosition,
                          const std::string& authorStr, Style style);

    Position renderPromptSymbol(const std::shared_ptr<Renderer> &renderer, Position startingPosition, Style style);

    Position renderText(const std::shared_ptr<Renderer> &renderer, Position startingPosition,
                        const std::string& currText, Style style);

    Position renderUnderscore(const std::shared_ptr<Renderer> &renderer, Position startingPosition,
                              const std::string& currText, bool isTerminalLive, Style style);
};


#endif //TEXTBASED_TERMINALRENDERER_H
