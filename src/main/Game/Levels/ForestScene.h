#ifndef TEXTBASED_FORESTSCENE_H
#define TEXTBASED_FORESTSCENE_H
#include "../../ECS/Systems/UpdateSystems/AutonomousMovementSystem.h"
#include "../TextGenerator.h"
#include "../../ECS/Components/CollisionComponent.h"
#include "../../Helpers/Objects/Position.h"
#include "../../ECS/Design/Managers/ECSManager.h"
#include <memory>
#include "../../ECS/Systems/UpdateSystems/CollisionCheckSystem.h"
#include "../../Helpers/Objects/Position.h"

class ForestScene {
public:
    explicit ForestScene(Position startingPosition);
private:
    Position startingPosition;

    void createBobby() const;

    void createJSON() const;

    void createForests();

    void createForest(int widthInTrees, Position startingPosition) const;

    void createTreeAtPosition(Position position) const;

};


#endif //TEXTBASED_FORESTSCENE_H
