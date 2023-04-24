#ifndef TEXTBASED_LEVEL1_H
#define TEXTBASED_LEVEL1_H
#include "../ECS/Systems/MovementSystem.h"
#include "TextGenerator.h"
#include "../ECS/Components/ColliderComponent.h"
#include "../Objects/Position.h"
#include "../ECS/Design/Managers/ECSManager.h"
#include <memory>
#include "../ECS/Systems/CollisionSystem.h"

extern std::unique_ptr<ECSManager> ecsManager;

class Level1 {
public:
    void setup();

private:
    void createBobby() const;

    void createJSON() const;

    void createForest(int widthInTrees, Position startingPosition) const;
};


#endif //TEXTBASED_LEVEL1_H
