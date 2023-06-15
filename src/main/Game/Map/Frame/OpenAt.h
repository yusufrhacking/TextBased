#ifndef TEXTBASED_OPENAT_H
#define TEXTBASED_OPENAT_H

struct OpenAt{
    bool north, east, south, west;
    OpenAt(){
        north = false;
        east = false;
        south = false;
        west = false;
    }

    void openVertical(){
        north = true;
        south = true;
    }

    void openEverywhere(){
        north = true;
        east = true;
        south = true;
        west = true;
    }
};

#endif //TEXTBASED_OPENAT_H
