#include "RightLeftMovementSystem.h"

#include "LiveComponent.h"
#include "PositionComponent.h"
#include "WalkingComponent.h"
#include "MovementSystem.h"
#include "../Maze/HalfwayOpenWallColumnPrefab.h"

extern std::unique_ptr<EventBus> eventBus;
extern std::unique_ptr<ECSManager> ecsManager;


RightLeftMovementSystem::RightLeftMovementSystem() {
    requireComponent<WalkingComponent>();
    requireComponent<PositionComponent>();
    requireComponent<LiveComponent>();
    eventBus->listenToEvent<GameKeyEvent>(this, &RightLeftMovementSystem::onKeyPressed);
}

void RightLeftMovementSystem::onKeyPressed(GameKeyEvent& event) {
    for (auto entity: getRelevantEntities()) {
        switch (event.getKey()) {
            case GameKey::MOVE_LEFT:
                moves.emplace_back(entity, MoveDirection::LEFT);
                break;
            case GameKey::MOVE_RIGHT:
                moves.emplace_back(entity, MoveDirection::RIGHT);
                break;
            default:
                break;
        }
    }
}

void RightLeftMovementSystem::update(double deltaTime) {
    for(auto move: moves) {
        Entity entity = move.entity;
        float movementDistance = ecsManager->getComponentFromEntity<WalkingComponent>(entity).movementDistance;
        float xChange = move.intDirection * movementDistance * deltaTime;

        ecsManager->getSystem<MovementSystem>().queueMovement(UnprocessedMovement(move.entity, xChange, 0));
    }
    moves.clear();
}
