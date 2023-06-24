#ifndef TEXTBASED_OPENAT_H
#define TEXTBASED_OPENAT_H

struct OpenAt{
    bool north, east, south, west;
    OpenAt(bool north, bool east, bool south, bool west): north(north), east(east), south(south), west(west) {

    }
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
