#ifndef TEXTBASED_FORESTFRAME_H
#define TEXTBASED_FORESTFRAME_H
#include "../../../ECS/Systems/UpdateSystems/AutonomousMovementSystem.h"
#include "../../TextGenerator.h"
#include "../../../ECS/Components/CollisionComponent.h"
#include "../../../Helpers/Objects/Position.h"
#include "../../../ECS/Design/Managers/ECSManager.h"
#include <memory>
#include "../../../ECS/Systems/UpdateSystems/CollisionCheckSystem.h"
#include "../../../Helpers/Objects/Position.h"
#include "../../Map/Frame/Frame.h"

class ForestFrame: public Frame {
public:
    explicit ForestFrame(Position referencePosition);

    TextComponent treeSprite = TextComponent(TextGenerator::getTreeText());
    int treeWidth = treeSprite.surfaceSize.width;
    int treeHeight = treeSprite.surfaceSize.height;
protected:
    Position frameReferencePosition;
    Position createDimensionedForest(int widthInTrees, int heightInTrees, const Position referencePosition) const;
    void createVerticalForest(int widthInTrees, Position referencePosition) const;

    void createGenericTreeAtPosition(Position position) const;


    void createStubTrees(int trees, Position position) const;

    static std::vector<std::string> splitText(std::string string) ;

    void createStubTreeAtPosition(std::string stubTreeText, Position treePosition) const;

    [[nodiscard]] std::string getStubTreeText() const;

    Position createDimensionedUncutForest(int widthInTrees, int heightInTrees, const Position &referencePosition) const;

    Position getStartingRightPositionFromWidth(int forestWidthInTrees);

};


#endif //TEXTBASED_FORESTFRAME_H
