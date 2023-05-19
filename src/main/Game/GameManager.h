#ifndef TEXTBASED_GAMEMANAGER_H
#define TEXTBASED_GAMEMANAGER_H

#include <memory>
#include "../ECS/Design/Managers/ECSManager.h"

extern std::unique_ptr<ECSManager> ecsManager;

class GameManager {
private:
    void setupSystems() const;
public:
    void setup();


};


#endif //TEXTBASED_GAMEMANAGER_H
