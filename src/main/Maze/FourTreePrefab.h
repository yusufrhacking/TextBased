#ifndef FOURTREEPREFAB_H
#define FOURTREEPREFAB_H
#include "../PositionsAndMovement/Position.h"
#include "../HighLevel/ECSManager.h"
#include "../PositionsAndMovement/CollisionComponent.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../Text/TextGenerator.h"
#include "../Woodworking/TreePrefab.h"
#include "../Abyz/PlainAbyzPrefab.h"

struct FourTreePrefab {
    Position relativeTreeCenterSpacing = {static_cast<float>(Window::windowWidth/5.5),  static_cast<float>(Window::windowHeight/6.0)};

    FourTreePrefab(Position startingPosition) {
        TextComponent dummyTree{TextGenerator::getTreeText()};
        EntitySize treeSize = dummyTree.getSurfaceSize();
        Position topLeftTreePosition = Window::deriveRelativeTopLeft(startingPosition) + relativeTreeCenterSpacing;
        TreePrefab topLeftTree{topLeftTreePosition};
        Position topLeftAbyzPosition = Window::deriveRelativeTopLeft(startingPosition) / topLeftTreePosition;
        PlainAbyzPrefab{topLeftAbyzPosition};

        Position bottomLeftTreePosition = topLeftTreePosition + Position(0, Window::windowHeight/2);
        TreePrefab bottomLeftTree{bottomLeftTreePosition};
        Position bottomleftAbyzPosition = Window::deriveRelativeBottomLeft(startingPosition) / bottomLeftTreePosition;
        PlainAbyzPrefab{bottomleftAbyzPosition};

        Position topRightTreePosition = topLeftTreePosition + Position(Window::windowWidth/2 + treeSize.width/2, 0);
        TreePrefab topRightTree{topRightTreePosition};
        Position topRightAbyzPosition = Window::deriveRelativeTopRight(startingPosition) / topRightTreePosition;
        PlainAbyzPrefab{topRightAbyzPosition};

        Position bottomRightTreePosition = topRightTreePosition + Position(0, Window::windowHeight/2);
        TreePrefab bottomRightTree{bottomRightTreePosition};
        Position bottomRightAbyzPosition = Window::deriveRelativeBottomRight(startingPosition) / bottomRightTreePosition;
        PlainAbyzPrefab{bottomRightAbyzPosition};
    }
};

#endif //FOURTREEPREFAB_H
