#ifndef TEXTBASED_GENERICSTYLECOMPONENT_H
#define TEXTBASED_GENERICSTYLECOMPONENT_H
#include <string>
#include <sstream>
#include "Style.h"
#include "TypeToStyleMapper.h"


struct GenericStyleComponent {
private:
    Style style;

public:
    GenericStyleComponent() {
        style = Style::WHITE_MONACO_GENERIC;
    }

//    explicit StyleComponent(Style style) : style(style) {}

    explicit GenericStyleComponent(Type type) {
        style = Types::typeToStyle(type);
    }

    [[nodiscard]] Style getStyle() const {
        return style;
    }
    //Maybe style stuff here, eventually
};

#endif
