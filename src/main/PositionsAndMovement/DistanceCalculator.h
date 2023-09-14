#ifndef TEXTBASED_DISTANCECALCULATOR_H
#define TEXTBASED_DISTANCECALCULATOR_H


#include "Position.h"
#include "../Text/TextComponent.h"

class DistanceCalculator {
public:
    static bool isInAllowedRange(Position pos1, Position pos2, const Size& size1, const Size& size2, float allowedDistance) {
        auto endpointLeftBound = pos2.xPos;
        auto endpointRightBound = pos2.xPos + size2.width;
        auto endpointTopBound = pos2.yPos;
        auto endpointBottomBound = pos2.yPos + size2.height;

        auto startLeftBound = pos1.xPos;
        auto startRightBound = pos1.xPos + size1.width;
        auto startTopBound = pos1.yPos;
        auto startBottomBound = pos1.yPos + size1.height;

        float horizontalDistance = 0.0f;
        if (startRightBound < endpointLeftBound) {
            horizontalDistance = endpointLeftBound - startRightBound;
        } else if (startLeftBound > endpointRightBound) {
            horizontalDistance = startLeftBound - endpointRightBound;
        }

        float verticalDistance = 0.0f;
        if (startBottomBound < endpointTopBound) {
            verticalDistance = endpointTopBound - startBottomBound;
        } else if (startTopBound > endpointBottomBound) {
            verticalDistance = startTopBound - endpointBottomBound;
        }

        float shortestDistance = std::sqrt(horizontalDistance * horizontalDistance + verticalDistance * verticalDistance);

        return shortestDistance <= allowedDistance;
    }

private:
    static bool isWithinBounds(Position mainPos, Position otherPos, const Size& otherSize) {
        bool isWithinHorizontalBounds = mainPos.xPos >= otherPos.xPos && mainPos.xPos <= otherPos.xPos + otherSize.width;
        bool isWithinVerticalBounds = mainPos.yPos >= otherPos.yPos && mainPos.yPos <= otherPos.yPos + otherSize.height;

        return isWithinHorizontalBounds && isWithinVerticalBounds;
    }

    static Position getClosestPart(Position mainPos, Position otherPos, const Size& otherSize) {
        float closestX = std::clamp(mainPos.xPos, otherPos.xPos, otherPos.xPos + otherSize.width);
        float closestY = std::clamp(mainPos.yPos, otherPos.yPos, otherPos.yPos + otherSize.height);

        return {closestX, closestY};
    }

    static bool isWithinAllowedDistance(Position mainPos, Position point, float allowedDistance) {
        float distanceSquared = std::pow(point.xPos - mainPos.xPos, 2) + std::pow(point.yPos - mainPos.yPos, 2);
        return distanceSquared <= std::pow(allowedDistance, 2);
    }
};


#endif //TEXTBASED_DISTANCECALCULATOR_H
