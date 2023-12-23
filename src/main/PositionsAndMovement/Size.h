#ifndef TEXTBASED_SIZE_H
#define TEXTBASED_SIZE_H

#include "../HighLevel/Globals.h"

struct EntitySize {
    RenderedVal width;
    RenderedVal height;

    EntitySize(RenderedVal x, RenderedVal y){
        this->width = x;
        this->height = y;
    }

    EntitySize(){
        this->width = 0;
        this->height = 0;
    }
};

#endif
