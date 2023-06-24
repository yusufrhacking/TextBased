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
    int treeWidth = (int)treeSprite.surfaceSize.width;
    int treeHeight = (int)treeSprite.surfaceSize.height;

    int northWallWidthInTrees = 8;
    int northWallHeightInTrees = 2;

    int sideWallWidthInTrees = 2;
    int sideWallHeightInTrees = 3;
protected:
    Position frameReferencePosition;
    Position createDimensionedForest(int widthInTrees, int heightInTrees, const Position referencePosition) const;
    void createVerticalForest(int widthInTrees, Position referencePosition) const;

    void createGenericTreeAtPosition(Position position) const;

    Position createNorthWall();

    Position createSideWallCluster(Position referencePosition);

    Position createStubTrees(int trees, Position position) const;

    static std::vector<std::string> splitText(std::string string) ;

    void createStubTreeAtPosition(std::string stubTreeText, Position treePosition) const;

    [[nodiscard]] std::string getStubTreeText() const;

    Position getStartingRightPositionFromWidth(int forestWidthInTrees);

private:
    [[nodiscard]] Position createDimensionedUncutForest(int widthInTrees, int heightInTrees, const Position &referencePosition) const;

    int getTreeCapacityFromPosition(Position position) const;

};


#endif //TEXTBASED_FORESTFRAME_H
