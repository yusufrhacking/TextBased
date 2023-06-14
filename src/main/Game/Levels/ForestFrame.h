#ifndef TEXTBASED_FORESTFRAME_H
#define TEXTBASED_FORESTFRAME_H
#include "../../ECS/Systems/UpdateSystems/AutonomousMovementSystem.h"
#include "../TextGenerator.h"
#include "../../ECS/Components/CollisionComponent.h"
#include "../../Helpers/Objects/Position.h"
#include "../../ECS/Design/Managers/ECSManager.h"
#include <memory>
#include "../../ECS/Systems/UpdateSystems/CollisionCheckSystem.h"
#include "../../Helpers/Objects/Position.h"
#include "../Map/Frame/Frame.h"

class ForestFrame: public Frame {
public:
    explicit ForestFrame(Position referencePosition);
private:
    Position frameReferencePosition;

    void createForests();

    void createVerticalForest(int widthInTrees, Position referencePosition) const;

    void createTreeAtPosition(Position position) const;

    void createUncutTrees(int forestWidthInTrees, const Position &referencePosition) const;

    void createStubTrees(int trees, Position position) const;

    static std::vector<std::string> splitText(std::string string) ;
};


#endif //TEXTBASED_FORESTFRAME_H
