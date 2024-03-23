#include "EmmaStart.h"
#include "../PositionsAndMovement/Position.h"
#include "../HighLevel/ECSManager.h"
#include "../ECSObjects/Entity.h"
#include "../PositionsAndMovement/LiveComponent.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../MainPlayer/MainPlayerComponent.h"
#include "../Middlemarch/SubjectComponent.h"
#include "../Gravity/GravityComponent.h"
#include "../PositionsAndMovement/VelocityComponent.h"
#include "../PositionsAndMovement/CollisionComponent.h"
#include "../Gravity/JumpingComponent.h"
#include "../PositionsAndMovement/WalkingComponent.h"
#include "ReadEmma.cpp"
#include "../Platformer/PlatformComponent.h"


extern std::unique_ptr<EventBus> eventBus;
extern std::unique_ptr<ECSManager> ecsManager;

EmmaStart::EmmaStart(Position startingPosition): startingPosition(startingPosition) {
    Position subjectPosition{11895, 10532};

    createSubject(subjectPosition);
    createTerrain(subjectPosition);
}

void EmmaStart::createSubject(Position subjectPosition) {
    Entity subject = ecsManager->createEntity();
    ecsManager->addComponentToEntity<LiveComponent>(subject);
    ecsManager->addComponentToEntity<PositionComponent>(subject, subjectPosition);
    ecsManager->addComponentToEntity<TextComponent>(subject, "Emma");
    ecsManager->addComponentToEntity<MainPlayerComponent>(subject);
    ecsManager->addComponentToEntity<SubjectComponent>(subject);
    ecsManager->addComponentToEntity<GravityComponent>(subject);
    ecsManager->addComponentToEntity<VelocityComponent>(subject);
    ecsManager->addComponentToEntity<CollisionComponent>(subject);
    ecsManager->addComponentToEntity<JumpingComponent>(subject, 200);
    ecsManager->addComponentToEntity<WalkingComponent>(subject, 100.0);
}

void EmmaStart::createTerrain(Position position) {
    Entity terrainBase = ecsManager->createEntity();

    std::vector<std::string> terrainText = readParagraphs("/Users/yusufhacking/Documents/Projects/TextBased/resources/emma.txt");

    // Iterate through the jit, once I get enough characters to go wide of the window + a third of the screen down
    // New lines for horizontal;

    // I should leave the paragraph indents below perhaps; well, we're gonna be walking to the side

    // Meta idea is that as you get more words, it is burdensome.

    ecsManager->addComponentToEntity<LiveComponent>(terrainBase);
    ecsManager->addComponentToEntity<PositionComponent>(terrainBase, position + Position(0, 800));
    ecsManager->addComponentToEntity<TextComponent>(terrainBase, terrainText[1]);
    ecsManager->addComponentToEntity<CollisionComponent>(terrainBase);
    ecsManager->addComponentToEntity<PlatformComponent>(terrainBase);
    ecsManager->addComponentToEntity<GenericStyleComponent>(terrainBase);
}
