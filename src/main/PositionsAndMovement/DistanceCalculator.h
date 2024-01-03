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

enum class CollisionDirection {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    NONE
};


class DistanceCalculator {
public:
    static bool isInAllowedRange(Position pos1, Position pos2, const EntitySize& size1, const EntitySize& size2, float allowedDistance) {
        float horizontalDistance = calculateSideDistance(pos1.x, pos1.x + size1.width, pos2.x, pos2.x + size2.width);
        float verticalDistance = calculateSideDistance(pos1.y, pos1.y + size1.height, pos2.y, pos2.y + size2.height);

        float shortestDistance = calculateEuclideanDistance(horizontalDistance, verticalDistance);

        return shortestDistance <= allowedDistance;
    }

    static bool checkAABBCollision(const Position firstPosition, EntitySize firstCollider,
                                              const Position secondPosition, EntitySize secondCollider) {
        bool firstXOverlap = firstPosition.x < (secondPosition.x + secondCollider.width);
        bool secondXOverlap = (firstPosition.x + firstCollider.width) > secondPosition.x;
        bool xOverlap = firstXOverlap && secondXOverlap;

        bool firstYOverlap = firstPosition.y < secondPosition.y + secondCollider.height;
        bool secondYOverlap = firstPosition.y + firstCollider.height > secondPosition.y;
        bool yOverlap = firstYOverlap && secondYOverlap;

        return xOverlap && yOverlap;
    }

    static CollisionAxis getCollisionAxes(const Position& firstPosition, const EntitySize& firstCollider,
                                 const Position& secondPosition, const EntitySize& secondCollider) {
        bool firstXOverlap = firstPosition.x < (secondPosition.x + secondCollider.width);
        bool secondXOverlap = (firstPosition.x + firstCollider.width) > secondPosition.x;
        bool xOverlap = firstXOverlap && secondXOverlap;

        bool firstYOverlap = firstPosition.y < (secondPosition.y + secondCollider.height);
        bool secondYOverlap = (firstPosition.y + firstCollider.height) > secondPosition.y;
        bool yOverlap = firstYOverlap && secondYOverlap;

        if (xOverlap && yOverlap) {
            float xOverlapDepth = std::min(firstPosition.x + firstCollider.width, secondPosition.x + secondCollider.width) -
                                  std::max(firstPosition.x, secondPosition.x);
            float yOverlapDepth = std::min(firstPosition.y + firstCollider.height, secondPosition.y + secondCollider.height) -
                                  std::max(firstPosition.y, secondPosition.y);

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

    static CollisionDirection getCollisionDirection(const Position& firstPosition, const EntitySize& firstCollider,
                                         const Position& secondPosition, const EntitySize& secondCollider) {
        bool firstXOverlap = firstPosition.x < (secondPosition.x + secondCollider.width);
        bool secondXOverlap = (firstPosition.x + firstCollider.width) > secondPosition.x;
        bool xOverlap = firstXOverlap && secondXOverlap;

        bool firstYOverlap = firstPosition.y < (secondPosition.y + secondCollider.height);
        bool secondYOverlap = (firstPosition.y + firstCollider.height) > secondPosition.y;
        bool yOverlap = firstYOverlap && secondYOverlap;

        if (xOverlap && yOverlap) {
            float xOverlapDepth = std::min(firstPosition.x + firstCollider.width, secondPosition.x + secondCollider.width) -
                                  std::max(firstPosition.x, secondPosition.x);
            float yOverlapDepth = std::min(firstPosition.y + firstCollider.height, secondPosition.y + secondCollider.height) -
                                  std::max(firstPosition.y, secondPosition.y);

            // Determine the collision direction based on the overlap depth and relative positions
            if (yOverlapDepth > xOverlapDepth) {
                if (firstPosition.y + firstCollider.height - yOverlapDepth == secondPosition.y) {
                    return CollisionDirection::DOWN; // First entity is above the second
                } else {
                    return CollisionDirection::UP; // First entity is below the second
                }
            } else if (xOverlapDepth > yOverlapDepth) {
                if (firstPosition.x + firstCollider.width - xOverlapDepth == secondPosition.x) {
                    return CollisionDirection::RIGHT; // First entity is to the left of the second
                } else {
                    return CollisionDirection::LEFT; // First entity is to the right of the second
                }
            }
        }

        return CollisionDirection::NONE;
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
