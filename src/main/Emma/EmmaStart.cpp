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
#include "../Lettering/LetterPrefab.h"
#include "EmmaWoodhouseComponent.h"
#include "EmmaWoodhouseSystem.h"
#include "../Abyz/AbyzComponent.h"
#include "../Abyz/LifeGateComponent.h"
#include "../PositionsAndMovement/RandomRightLeftMovementComponent.h"
#include "../Platformer/HorizontalPlatformMovementComponent.h"


extern std::unique_ptr<EventBus> eventBus;
extern std::unique_ptr<ECSManager> ecsManager;

EmmaStart::EmmaStart(Position startingPosition): startingPosition(startingPosition) {
    ecsManager->addSystem<EmmaWoodhouseSystem>();
    Position subjectPosition{11895, 10532};
    Position terrainPosition{subjectPosition + Position(0, 800)};

    createSubject(subjectPosition);
    createTerrain(terrainPosition);


    createCandidateLetters(terrainPosition);

    createObstacle(terrainPosition);


    Position abyzPosition = terrainPosition + Position(200, -1.0 * MONACO_HEIGHT_OF_A_LINE_OF_TEXT);
    Entity abyz = ecsManager->createEntity();
    ecsManager->addComponentToEntity<TextComponent>(abyz, "Abyz");
    ecsManager->addComponentToEntity<PositionComponent>(abyz, abyzPosition);
    ecsManager->addComponentToEntity<LiveComponent>(abyz);
    ecsManager->addComponentToEntity<AbyzComponent>(abyz);

    auto leftBound = static_cast<unsigned int>(abyzPosition.x);
    auto rightBound = static_cast<int>(abyzPosition.x) + 150;
    ecsManager->addComponentToEntity<HorizontalPlatformMovementComponent>(abyz, 50.0, leftBound, rightBound);
    ecsManager->addComponentToEntity<LifeGateComponent>(abyz, abyzPosition.y + Window::windowHeight);
    ecsManager->addComponentToEntity<CollisionComponent>(abyz);
    int id = abyz.getId();
    ecsManager->addComponentToEntity<OnDeathComponent>(abyz, [this, id]() {
        eventBus->emitEvent<CreateItemAtEntityEvent>(Item::QUESTION_MARK, Entity{id});
    });

    // Dialogue Clouds takes in a vector of strings, then it passes them along, every few seconds or so
    // Starts at the right edge of the screen and floats along to the left, kinda slowly
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
    ecsManager->addComponentToEntity<WalkingComponent>(subject, 350.0);
    ecsManager->addComponentToEntity<EmmaWoodhouseComponent>(subject);
}

void EmmaStart::createTerrain(Position position) {
    // Iterate through the jit, once I get enough characters to go wide of the window + a third of the screen down
    // New lines for horizontal;

    // I should leave the paragraph indents below perhaps; well, we're gonna be walking to the side

    // Meta idea is that as you get more words, it is burdensome.

    // So, I should spawn in some question mark letters that give Emma more

    // Eventually add a typing effect power up (mushroom typa thing)
    // For that to help, I need there to be some stuff you gotta jump up that is burdensome

    std::vector<std::string> terrainText = readParagraphs("/Users/yusufhacking/Documents/Projects/TextBased/resources/emma.txt");
    float paragraphGap = 50.0;


    for(int x=0; x<3; x++){
        Entity terrainBase = ecsManager->createEntity();


        ecsManager->addComponentToEntity<LiveComponent>(terrainBase);
        ecsManager->addComponentToEntity<PositionComponent>(terrainBase, position);
        ecsManager->addComponentToEntity<TextComponent>(terrainBase, terrainText[x+1]);
        ecsManager->addComponentToEntity<CollisionComponent>(terrainBase);
        ecsManager->addComponentToEntity<PlatformComponent>(terrainBase);
        ecsManager->addComponentToEntity<GenericStyleComponent>(terrainBase);

        float prevXSize = ecsManager->getComponentFromEntity<TextComponent>(terrainBase).getSurfaceSize().width;

        position += Position(paragraphGap + prevXSize, 0.0);

    }



}

void EmmaStart::createCandidateLetters(Position terrainPosition) {
    float xShift = 500.0;
    float yShift = -1 * (float)MONACO_HEIGHT_OF_A_LINE_OF_TEXT;

    Position letterPosition = terrainPosition + Position(xShift, yShift);

    for(int x=0; x<20; x++){
        Entity letterEntity = ecsManager->createEntity();
        char character = '?';
        ecsManager->addComponentToEntity<TextComponent>(letterEntity, std::string(1, character));
        ecsManager->addComponentToEntity<PositionComponent>(letterEntity, letterPosition);
        ecsManager->addComponentToEntity<GenericStyleComponent>(letterEntity, RenderStyle::GREEN_TERMINAL);
        ecsManager->addComponentToEntity<LiveComponent>(letterEntity);
        ecsManager->addComponentToEntity<LetterComponent>(letterEntity, char_to_enum(character));
        letterPosition += Position(xShift, 0.0);
    }


}

void EmmaStart::createObstacle(Position terrainPosition) {
    std::string obstacleStr = "handsome\nhandsome\nhandsome\nhandsome\n";
    Entity obstacleEntity = ecsManager->createEntity();

    float xShift = 550.0;
    float yShift = -4 * (float)MONACO_HEIGHT_OF_A_LINE_OF_TEXT;

    Position obstaclePosition = terrainPosition + Position(xShift, yShift);

    ecsManager->addComponentToEntity<TextComponent>(obstacleEntity, obstacleStr);
    ecsManager->addComponentToEntity<PositionComponent>(obstacleEntity, obstaclePosition);
    ecsManager->addComponentToEntity<GenericStyleComponent>(obstacleEntity, RenderStyle::WHITE_MONACO_GENERIC);
    ecsManager->addComponentToEntity<LiveComponent>(obstacleEntity);
    ecsManager->addComponentToEntity<CollisionComponent>(obstacleEntity);

    // Make like a lil tower to climb over? I don't know how to standardize it quite yet
    obstaclePosition += TextComponent::getSurfaceSizeAsAddablePosition(obstacleStr);
    obstacleStr = "clever\nclever\nclever\nclever\n";
    obstacleEntity = ecsManager->createEntity();
    ecsManager->addComponentToEntity<TextComponent>(obstacleEntity, obstacleStr);
    ecsManager->addComponentToEntity<PositionComponent>(obstacleEntity, obstaclePosition);
    ecsManager->addComponentToEntity<GenericStyleComponent>(obstacleEntity, RenderStyle::WHITE_MONACO_GENERIC);
    ecsManager->addComponentToEntity<LiveComponent>(obstacleEntity);
    ecsManager->addComponentToEntity<CollisionComponent>(obstacleEntity);


    obstaclePosition += TextComponent::getSurfaceSizeAsAddablePosition(obstacleStr);
    obstacleStr = "rich\nrich\nrich\nrich\n";
    obstacleEntity = ecsManager->createEntity();
    ecsManager->addComponentToEntity<TextComponent>(obstacleEntity, obstacleStr);
    ecsManager->addComponentToEntity<PositionComponent>(obstacleEntity, obstaclePosition);
    ecsManager->addComponentToEntity<GenericStyleComponent>(obstacleEntity, RenderStyle::WHITE_MONACO_GENERIC);
    ecsManager->addComponentToEntity<LiveComponent>(obstacleEntity);
    ecsManager->addComponentToEntity<CollisionComponent>(obstacleEntity);

    obstaclePosition += TextComponent::getSurfaceSizeAsPosition(obstacleStr);
    obstacleStr = "clever\nclever\nclever\nclever\n";
    obstacleEntity = ecsManager->createEntity();
    ecsManager->addComponentToEntity<TextComponent>(obstacleEntity, obstacleStr);
    ecsManager->addComponentToEntity<PositionComponent>(obstacleEntity, obstaclePosition);
    ecsManager->addComponentToEntity<GenericStyleComponent>(obstacleEntity, RenderStyle::WHITE_MONACO_GENERIC);
    ecsManager->addComponentToEntity<LiveComponent>(obstacleEntity);
    ecsManager->addComponentToEntity<CollisionComponent>(obstacleEntity);


    obstaclePosition += TextComponent::getSurfaceSizeAsPosition(obstacleStr);
    obstacleStr = "handsome\nhandsome\nhandsome\nhandsome\n";
    obstacleEntity = ecsManager->createEntity();
    ecsManager->addComponentToEntity<TextComponent>(obstacleEntity, obstacleStr);
    ecsManager->addComponentToEntity<PositionComponent>(obstacleEntity, obstaclePosition);
    ecsManager->addComponentToEntity<GenericStyleComponent>(obstacleEntity, RenderStyle::WHITE_MONACO_GENERIC);
    ecsManager->addComponentToEntity<LiveComponent>(obstacleEntity);
    ecsManager->addComponentToEntity<CollisionComponent>(obstacleEntity);


    // Dialogue should pass along the sky like clouds (there are clouds in Mario)
}
