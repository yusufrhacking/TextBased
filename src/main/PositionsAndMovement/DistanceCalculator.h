#ifndef TEXTBASED_DISTANCECALCULATOR_H
#define TEXTBASED_DISTANCECALCULATOR_H


#include "Position.h"
#include "../Text/TextComponent.h"

class DistanceCalculator {
public:
    static bool isInAllowedRange(Position pos1, Position pos2, const Size& size1, const Size& size2, float allowedDistance) {
        if (isWithinBounds(pos1, pos2, size1) || isWithinBounds(pos2, pos1, size2)) {
            return true;
        }

        Position closestPoint1 = getClosestPart(pos1, pos2, size2);
        Position closestPoint2 = getClosestPart(pos2, pos1, size1);
        return isWithinAllowedDistance(pos1, closestPoint1, allowedDistance) || isWithinAllowedDistance(pos2, closestPoint2, allowedDistance);
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
