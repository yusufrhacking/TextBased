#ifndef TEXTBASED_DISTANCECALCULATOR_H
#define TEXTBASED_DISTANCECALCULATOR_H


#include "Position.h"
#include "../Text/TextComponent.h"

enum class CollisionAxis {
    HORIZONTAL,
    VERTICAL,
    NONE,
    BOTH
};

class DistanceCalculator {
public:
    static bool isInAllowedRange(Position pos1, Position pos2, const EntitySize& size1, const EntitySize& size2, float allowedDistance) {
        float horizontalDistance = calculateSideDistance(pos1.xPos, pos1.xPos + size1.width, pos2.xPos, pos2.xPos + size2.width);
        float verticalDistance = calculateSideDistance(pos1.yPos, pos1.yPos + size1.height, pos2.yPos, pos2.yPos + size2.height);

        float shortestDistance = calculateEuclideanDistance(horizontalDistance, verticalDistance);

        return shortestDistance <= allowedDistance;
    }

    static bool checkAABBCollision(const Position firstPosition, EntitySize firstCollider,
                                              const Position secondPosition, EntitySize secondCollider) {
        bool firstXOverlap = firstPosition.xPos < (secondPosition.xPos + secondCollider.width);
        bool secondXOverlap = (firstPosition.xPos + firstCollider.width) > secondPosition.xPos;
        bool xOverlap = firstXOverlap && secondXOverlap;

        bool firstYOverlap = firstPosition.yPos < secondPosition.yPos + secondCollider.height;
        bool secondYOverlap = firstPosition.yPos + firstCollider.height > secondPosition.yPos;
        bool yOverlap = firstYOverlap && secondYOverlap;

        return xOverlap && yOverlap;
    }

    static CollisionAxis getCollisionAxes(const Position& firstPosition, const EntitySize& firstCollider,
                                 const Position& secondPosition, const EntitySize& secondCollider) {
        bool firstXOverlap = firstPosition.xPos < (secondPosition.xPos + secondCollider.width);
        bool secondXOverlap = (firstPosition.xPos + firstCollider.width) > secondPosition.xPos;
        bool xOverlap = firstXOverlap && secondXOverlap;

        bool firstYOverlap = firstPosition.yPos < (secondPosition.yPos + secondCollider.height);
        bool secondYOverlap = (firstPosition.yPos + firstCollider.height) > secondPosition.yPos;
        bool yOverlap = firstYOverlap && secondYOverlap;

        if (xOverlap && yOverlap) {
            float xOverlapDepth = std::min(firstPosition.xPos + firstCollider.width, secondPosition.xPos + secondCollider.width) -
                                  std::max(firstPosition.xPos, secondPosition.xPos);
            float yOverlapDepth = std::min(firstPosition.yPos + firstCollider.height, secondPosition.yPos + secondCollider.height) -
                                  std::max(firstPosition.yPos, secondPosition.yPos);

            if (xOverlapDepth > yOverlapDepth) {
                return CollisionAxis::VERTICAL;
            } else if (yOverlapDepth > xOverlapDepth) {
                return CollisionAxis::HORIZONTAL;
            } else {
                return CollisionAxis::BOTH;
            }
        }

        return CollisionAxis::NONE;
    }

private:
    static float calculateSideDistance(float entityBegin, float entityEnd, float otherBegin, float otherEnd) {
        if (entityEnd < otherBegin) {
            return otherBegin - entityEnd;
        } else if (entityBegin > otherEnd) {
            return entityBegin - otherEnd;
        }
        return 0.0f;
    }

    static float calculateEuclideanDistance(float x, float y) {
        return std::sqrt(x * x + y * y);
    }
};



#endif //TEXTBASED_DISTANCECALCULATOR_H
