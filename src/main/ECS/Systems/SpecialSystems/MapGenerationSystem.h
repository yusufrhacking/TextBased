#ifndef TEXTBASED_MAPGENERATIONSYSTEM_H
#define TEXTBASED_MAPGENERATIONSYSTEM_H
#include "../../Design/Objects/System.h"
#include "../../../Game/Map/FrameMap/FrameMap.h"

class MapGenerationSystem: public System {
private:
    std::shared_ptr<FrameMap> frameMap;
public:
    explicit MapGenerationSystem(std::shared_ptr<FrameMap> frameMap);

    void update();
};


#endif
