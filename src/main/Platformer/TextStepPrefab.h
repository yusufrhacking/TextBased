#ifndef TEXTSTEPPREFAB_H
#define TEXTSTEPPREFAB_H
#include <string>

#include "../Maze/HalfwayOpenWallColumnPrefab.h"
#include "../PositionsAndMovement/Position.h"

extern std::unique_ptr<ECSManager> ecsManager;

struct TextStepPrefab {
    Entity entity{};
    std::string text;
    Position position;
    TextStepPrefab(std::string text, Position position): text(text), position(position) {
        entity = ecsManager->createEntity();
        ecsManager->addComponentToEntity<LiveComponent>(entity);
        ecsManager->addComponentToEntity<PositionComponent>(entity, position);
        ecsManager->addComponentToEntity<TextComponent>(entity, text);
        ecsManager->addComponentToEntity<CollisionComponent>(entity);
    }

    Entity getEntity() const{
        return entity;
    }
};

#endif //TEXTSTEPPREFAB_H
