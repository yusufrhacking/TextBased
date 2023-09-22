#ifndef TEXTBASED_STYLECOMPONENT_H
#define TEXTBASED_STYLECOMPONENT_H
#include <string>
#include <sstream>

enum Style{
    WHITE_MONACO_GENERIC,
    LETTER,
    TERMINAL
};

struct StyleComponent{
private:
    Style style;

public:
    StyleComponent(){
        style = WHITE_MONACO_GENERIC;
    }

    explicit StyleComponent(Style style): style(style){

    }

    [[nodiscard]] Style getStyle() const {
        return style;
    }
    //Maybe style stuff here, eventually
};

#endif
