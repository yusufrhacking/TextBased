#ifndef TEXTBASED_STYLECOMPONENT_H
#define TEXTBASED_STYLECOMPONENT_H
#include <string>
#include <sstream>

enum class Style{
    WHITE_MONACO_GENERIC,
    LETTER,
    TERMINAL,
    ENGINEER_TERMINAL,
    OLD_TERMINAL_COMMAND,
    TINY_NUMBER
};

struct StyleComponent{
private:
    Style style;

public:
    StyleComponent(){
        style = Style::WHITE_MONACO_GENERIC;
    }

    explicit StyleComponent(Style style): style(style){

    }

    [[nodiscard]] Style getStyle() const {
        return style;
    }
    //Maybe style stuff here, eventually
};

#endif
