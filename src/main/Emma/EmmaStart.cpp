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


extern std::unique_ptr<EventBus> eventBus;
extern std::unique_ptr<ECSManager> ecsManager;

EmmaStart::EmmaStart(Position startingPosition): startingPosition(startingPosition) {
    ecsManager->addSystem<EmmaWoodhouseSystem>();
    Position subjectPosition{11895, 10532};
    Position terrainPosition{subjectPosition + Position(0, 800)};

    createSubject(subjectPosition);
    createTerrain(terrainPosition);
    createCandidateLetters(terrainPosition);
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
    Entity terrainBase = ecsManager->createEntity();

    std::vector<std::string> terrainText = readParagraphs("/Users/yusufhacking/Documents/Projects/TextBased/resources/emma.txt");

    // Iterate through the jit, once I get enough characters to go wide of the window + a third of the screen down
    // New lines for horizontal;

    // I should leave the paragraph indents below perhaps; well, we're gonna be walking to the side

    // Meta idea is that as you get more words, it is burdensome.

    // So, I should spawn in some question mark letters that give Emma more

    // Eventually add a typing effect power up (mushroom typa thing)
    // For that to help, I need there to be some stuff you gotta jump up that is burdensome

    ecsManager->addComponentToEntity<LiveComponent>(terrainBase);
    ecsManager->addComponentToEntity<PositionComponent>(terrainBase, position);
    ecsManager->addComponentToEntity<TextComponent>(terrainBase, terrainText[1]);
    ecsManager->addComponentToEntity<CollisionComponent>(terrainBase);
    ecsManager->addComponentToEntity<PlatformComponent>(terrainBase);
    ecsManager->addComponentToEntity<GenericStyleComponent>(terrainBase);

    Position newPosition = position + ecsManager->getComponentFromEntity<TextComponent>(terrainBase).getSurfaceSizeAsPosition();


}

void EmmaStart::createCandidateLetters(Position terrainPosition) {
    float xShift = 300.0;
    float yShift = -1 * (float)MONACO_HEIGHT_OF_A_LINE_OF_TEXT;
    Position letterPosition = terrainPosition + Position(xShift, yShift);

    for(int x=0; x<10; x++){
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
