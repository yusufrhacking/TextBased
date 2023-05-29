#ifndef TEXTBASED_MAPGENERATIONSYSTEM_H
#define TEXTBASED_MAPGENERATIONSYSTEM_H
#include "../../Design/Objects/System.h"

class MapGenerationSystem: public System {
private:
    Position relativeCameraPosition;
    bool doneBefore;
public:
    MapGenerationSystem();

    void update();
};


#endif
