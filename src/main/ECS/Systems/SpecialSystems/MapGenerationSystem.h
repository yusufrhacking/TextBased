#ifndef TEXTBASED_MAPGENERATIONSYSTEM_H
#define TEXTBASED_MAPGENERATIONSYSTEM_H
#include "../../Design/Objects/System.h"
#include "../../../Game/Map/FrameMap/MapManager.h"

class MapGenerationSystem: public System {
private:
    std::shared_ptr<MapManager> frameMap;
public:
    explicit MapGenerationSystem(std::shared_ptr<MapManager> frameMap);

    void update();
};


#endif
