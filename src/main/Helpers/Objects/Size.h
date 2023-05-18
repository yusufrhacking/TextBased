#ifndef TEXTBASED_SIZE_H
#define TEXTBASED_SIZE_H

#include "../../Globals.h"

struct Size {
    RenderedVal width;
    RenderedVal height;

    Size(RenderedVal x, RenderedVal y){
        this->width = x;
        this->height = y;
    }

    Size(){
        this->width = 0;
        this->height = 0;
    }
};

#endif //TEXTBASED_SIZE_H
