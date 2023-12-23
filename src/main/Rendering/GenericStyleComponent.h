#ifndef TEXTBASED_GENERICSTYLECOMPONENT_H
#define TEXTBASED_GENERICSTYLECOMPONENT_H
#include <string>
#include <sstream>
#include "RenderStyle.h"
#include "TypeToStyleMapper.h"


struct GenericStyleComponent {
private:
    RenderStyle style;

public:
    GenericStyleComponent() {
        style = RenderStyle::WHITE_MONACO_GENERIC;
    }

//    explicit StyleComponent(Style style) : style(style) {}

    explicit GenericStyleComponent(Type type) {
        style = Types::typeToStyle(type);
    }

    [[nodiscard]] RenderStyle getStyle() const {
        return style;
    }
    //Maybe style stuff here, eventually
};

#endif
