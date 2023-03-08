#ifndef TEXTBASED_BOXCOMPONENT_H
#define TEXTBASED_BOXCOMPONENT_H

#include "SpriteComponent.h"

struct BoxComponent {
    SpriteComponent sprite;

    BoxComponent() {
        sprite = {"Robert C. Martin"};
    }
};

#endif
