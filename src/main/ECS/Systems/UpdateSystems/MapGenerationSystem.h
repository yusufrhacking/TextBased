#ifndef TEXTBASED_MAPGENERATIONSYSTEM_H
#define TEXTBASED_MAPGENERATIONSYSTEM_H
#include "UpdateSystem.h"
#include "../../Design/Managers/ECSManager.h"

extern std::unique_ptr<ECSManager> ecsManager;


class MapGenerationSystem: public UpdateSystem {

    MapGenerationSystem();

    void update(double deltaTime) override;

};


#endif //TEXTBASED_MAPGENERATIONSYSTEM_H
