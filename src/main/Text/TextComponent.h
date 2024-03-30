#ifndef TEXTBASED_TEXTCOMPONENT_H
#define TEXTBASED_TEXTCOMPONENT_H
#include <string>
#include <utility>
#include "../HighLevel/Globals.h"
#include "../PositionsAndMovement/Size.h"
#include <sstream>
#include <spdlog/spdlog.h>

struct TextComponent {
    std::string text;
    bool isLined = false;

    explicit TextComponent(std::string text);

    TextComponent();

    [[nodiscard]] EntitySize getSurfaceSize() const;

    [[nodiscard]] Position getSurfaceSizeAsPosition() const;


    static EntitySize getSurfaceSize(const std::string& text);

    static Position getSurfaceSizeAsPosition(const std::string& text);

    static Position getSurfaceSizeAsAddablePosition(const std::string& text);

    static int getTextHeightInChars(const std::string& text);

    static unsigned int getTextWidthInChars(const std::string& text);

    [[nodiscard]] int getTextHeight() const;

    [[nodiscard]] unsigned int getTextWidth() const;
};


#endif
