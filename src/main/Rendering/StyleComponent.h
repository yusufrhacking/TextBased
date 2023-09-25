#ifndef TEXTBASED_STYLECOMPONENT_H
#define TEXTBASED_STYLECOMPONENT_H
#include <string>
#include <sstream>
#include "Style.h"
#include "TypeToStyleMapper.h"


struct StyleComponent {
private:
    Style style;

public:
    StyleComponent() {
        style = Style::WHITE_MONACO_GENERIC;
    }

//    explicit StyleComponent(Style style) : style(style) {}

    explicit StyleComponent(Type type) {
        style = Types::typeToStyle(type);
    }

    [[nodiscard]] Style getStyle() const {
        return style;
    }
    //Maybe style stuff here, eventually
};

#endif
