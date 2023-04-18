#ifndef TEXTBASED_GAMEMANAGER_H
#define TEXTBASED_GAMEMANAGER_H

#include <memory>
#include "../ECS/Design/Managers/ECSManager.h"

extern std::unique_ptr<ECSManager> ecsManager;

class GameManager {
public:
    void setup();

    void createBobby() const;

    void createJSON() const;

    void createForest(int widthInTrees, Position startingPosition) const;
};


#endif //TEXTBASED_GAMEMANAGER_H
