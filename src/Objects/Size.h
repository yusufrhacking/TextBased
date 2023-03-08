#ifndef TEXTBASED_SIZE_H
#define TEXTBASED_SIZE_H

#include "../Globals.h"

struct Size {
    WindowNum width;
    WindowNum height;

    Size(WindowNum x, WindowNum y){
        this->width = x;
        this->height = y;
    }

    Size(){
        this->width = 0;
        this->height = 0;
    }
};

#endif //TEXTBASED_SIZE_H
