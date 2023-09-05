#ifndef TEXTBASED_FIRSTLEVEL_H
#define TEXTBASED_FIRSTLEVEL_H
#include "../Positioning/AutonomousMovementSystem.h"
#include "../Art/TextGenerator.h"
#include "../Positioning/CollisionComponent.h"
#include "../Positioning/Position.h"
#include "../HighLevel/ECSManager.h"
#include <memory>
#include "../Positioning/CollisionCheckSystem.h"

extern std::unique_ptr<ECSManager> ecsManager;

class FirstLevel {
public:
    FirstLevel(Position startingPosition);

private:
    Position startingPosition;
    void createPlayer();
    Entity witt;

    void createTree();
};


#endif //TEXTBASED_FIRSTLEVEL_H
