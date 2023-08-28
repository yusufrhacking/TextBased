#ifndef TEXTBASED_GAMEMANAGER_H
#define TEXTBASED_GAMEMANAGER_H

#include <memory>
#include "../ECS/Design/Managers/ECSManager.h"

extern std::unique_ptr<ECSManager> ecsManager;

class GameManager {
private:
    void setupSystems();
    Canon canon;
public:
    explicit GameManager(Position position);
    void setup();
    void update(double deltaTime);


};


#endif //TEXTBASED_GAMEMANAGER_H
