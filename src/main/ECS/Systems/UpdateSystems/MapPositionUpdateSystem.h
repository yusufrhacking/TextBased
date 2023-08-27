#ifndef TEXTBASED_MAPPOSITIONUPDATESYSTEM_H
#define TEXTBASED_MAPPOSITIONUPDATESYSTEM_H
#include "UpdateSystem.h"
#include "../../Design/Managers/ECSManager.h"

extern std::unique_ptr<ECSManager> ecsManager;


class MapPositionUpdateSystem: public UpdateSystem {

    MapPositionUpdateSystem();

    void update(double deltaTime) override;

};


#endif //TEXTBASED_MAPPOSITIONUPDATESYSTEM_H
