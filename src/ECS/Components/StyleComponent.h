#ifndef TEXTBASED_STYLECOMPONENT_H
#define TEXTBASED_STYLECOMPONENT_H
#include <string>
#include <sstream>
#include "../../Objects/Size.h"

struct StyleComponent{
private:
    Style style;

public:
    StyleComponent(){
        style = WHITE_MONACO_GENERIC;
    }

    [[nodiscard]] Style getStyle() const {
        return style;
    }
    //Maybe style stuff here, eventually
};

#endif
