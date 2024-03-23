cmake_minimum_required(VERSION 3.25.1)
#set(CMAKE_XCODE_GENERATE_SCHEME ON)
#set(CMAKE_XCODE_SCHEME_ADDRESS_SANITIZER ON)
#set(CMAKE_XCODE_SCHEME_ADDRESS_SANITIZER_USE_AFTER_RETURN ON)

Message("")
Message( STATUS "CMAKE_BINARY_DIR: " ${CMAKE_BINARY_DIR} )
Message( STATUS "CMAKE_SOURCE_DIR: " ${CMAKE_SOURCE_DIR} )
Message( STATUS "CMAKE_COMMAND: " ${CMAKE_COMMAND} )
Message( STATUS "CMAKE_VERSION: " ${CMAKE_VERSION} )
Message( STATUS "CMAKE_C_COMPILER: " ${CMAKE_C_COMPILER} )
Message( STATUS "CMAKE_CXX_COMPILER: " ${CMAKE_CXX_COMPILER} )

Message( STATUS "CMAKE_PROJECT_NAME: " ${CMAKE_PROJECT_NAME} )
Message( STATUS "CMAKE_FINDCMAKE: " ${CMAKE_SOURCE_DIR}/CMAKE )

project(TextBased)

# ------- Set Vars ------- #

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fmodules-ts")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMAKE")
set(SOURCE_FILES
        src/main/HighLevel/Game.cpp src/main/HighLevel/Game.h
        src/main/Rendering/Renderer.cpp src/main/Rendering/Renderer.h
        src/main/Rendering/Window.cpp src/main/Rendering/Window.h
        src/main/TextInput/InputProcessor.cpp src/main/TextInput/InputProcessor.h
        src/main/PositionsAndMovement/PositionComponent.h
        src/main/PositionsAndMovement/Position.h src/main/PositionsAndMovement/Velocity.h
        src/main/PositionsAndMovement/VelocitySystem.cpp src/main/PositionsAndMovement/VelocitySystem.h
        "src/main/ECSObjects/Entity.cpp" "src/main/ECSObjects/Entity.h"
        "src/main/ECSObjects/Component.h"
        "src/main/ECSObjects/System.cpp" "src/main/ECSObjects/System.h"
        "src/main/HighLevel/ECSManager.cpp" "src/main/HighLevel/ECSManager.h"
        src/main/ECSObjects/Pool.h
        src/main/PositionsAndMovement/MovementComponent.h
        src/main/ECSManagers/SystemManager.cpp src/main/ECSManagers/SystemManager.h
        src/main/ECSManagers/ComponentManager.cpp src/main/ECSManagers/ComponentManager.h
        src/main/ECSManagers/EntityManager.cpp src/main/ECSManagers/EntityManager.h
        src/main/HighLevel/Globals.h
        src/main/Rendering/EntityRenderSystem.cpp src/main/Rendering/EntityRenderSystem.h
        src/main/Text/TextComponent.h src/main/ECSObjects/UpdateSystem.h
        src/main/PositionsAndMovement/Size.h
        src/main/Text/TextGenerator.cpp src/main/Text/TextGenerator.h src/main/HighLevel/GameManager.cpp src/main/HighLevel/GameManager.h
        resources/SDL_FontCache.c resources/SDL_FontCache.h src/main/PositionsAndMovement/CollisionComponent.h
        src/main/PositionsAndMovement/CollisionCheckSystem.cpp src/main/PositionsAndMovement/CollisionCheckSystem.h
        src/main/Rendering/GenericStyleComponent.h src/main/Rendering/NoStyleException.h
        src/main/Levels/BasicLevel.cpp src/main/Levels/BasicLevel.h
        src/main/Rendering/SDLRenderer.cpp src/main/Rendering/SDLRenderer.h
        src/main/EventSystem/EventBus.cpp src/main/EventSystem/EventBus.h
        src/main/EventSystem/EventFunctionWrapper.cpp src/main/EventSystem/EventFunctionWrapper.h
        src/main/EventSystem/Event.h
        src/main/PositionsAndMovement/CollisionHandleSystem.cpp src/main/PositionsAndMovement/CollisionHandleSystem.h
        src/main/ECSObjects/EventConsumerSystem.h
        src/main/PositionsAndMovement/CollisionEvent.h
        src/main/TextInput/GameKeyEvent.h
        src/main/MainPlayer/KeyboardMovementComponent.h
        src/main/MainPlayer/PlayerKeyboardInputSystem.cpp src/main/MainPlayer/PlayerKeyboardInputSystem.h
        src/main/Woodworking/TreeComponent.h
        "src/main/Camera/CameraFollowSystem.cpp" "src/main/Camera/CameraFollowSystem.h"
        "src/main/MainPlayer/UnprocessedMovement.cpp" "src/main/MainPlayer/UnprocessedMovement.h"
        "src/main/PositionsAndMovement/MovementSystem.cpp" "src/main/PositionsAndMovement/MovementSystem.h"
        src/main/ECSObjects/ComponentSignature.cpp src/main/ECSObjects/ComponentSignature.h
        src/main/Camera/Camera.cpp src/main/Camera/Camera.h
        src/main/TheCanon/MapPosition.h
        src/main/TheCanon/Canon.cpp src/main/TheCanon/Canon.h src/main/TheCanon/Page.cpp src/main/TheCanon/Page.h src/main/TheCanon/CanonRegisteringSystem.cpp src/main/TheCanon/CanonRegisteringSystem.h src/main/ECSObjects/FirstSystem.h src/main/PositionsAndMovement/ReadyToMoveEvent.h src/main/MainPlayer/MovementHandleSystem.cpp src/main/MainPlayer/MovementHandleSystem.h src/main/TheCanon/CanonMovementHandleSystem.cpp src/main/TheCanon/CanonMovementHandleSystem.h src/main/PositionsAndMovement/PostMovementEvent.h src/main/Levels/ForestGenerator.cpp src/main/Levels/ForestGenerator.h src/main/TextInput/GameKeyEvent.cpp src/main/TextInput/WordInputSystem.cpp src/main/TextInput/TextInputEvent.h src/main/TextInput/TextCommandEvent.h src/main/TextCommands/TextCommandSystem.cpp src/main/TextCommands/TextCommandSystem.h src/main/TextInput/TextQueuedEvent.h src/main/MainPlayer/TiedChildComponent.h src/main/Woodworking/AxeComponent.h src/main/Woodworking/ChopEvent.h src/main/Woodworking/ChoppingSystem.cpp src/main/Woodworking/ChoppingSystem.h src/main/Creation/CreateItemAtPositionEvent.h src/main/Creation/ItemCreationSystem.cpp src/main/Creation/ItemCreationSystem.h src/main/Woodworking/AxeComponent.cpp src/main/Woodworking/WoodComponent.h src/main/Inventory/InventoryPickupComponent.h src/main/Creation/ItemComponent.h src/main/Inventory/PlayerPickUpEvent.h src/main/Inventory/InventorySystem.cpp src/main/Inventory/InventorySystem.h src/main/PositionsAndMovement/DistanceCalculator.cpp src/main/PositionsAndMovement/DistanceCalculator.h src/main/Creation/CreatePlayerItemEvent.h src/main/Creation/Item.h src/main/MainPlayer/MainPlayerAccessSystem.h src/main/MainPlayer/MainPlayerAccessSystem.cpp src/main/Inventory/InventoryComponent.h src/main/PositionsAndMovement/LiveComponent.h src/main/Inventory/PlaceSystem.cpp src/main/Inventory/PlaceSystem.h src/main/Inventory/PlaceEvent.h
        src/main/Inventory/StashPlayerItemEvent.h src/main/Lettering/CharacterStorageSystem.cpp src/main/Lettering/CharacterStorageSystem.h src/main/Lettering/Alphabet.h src/main/Lettering/Letter.h src/main/TextCommands/CharacterSpendEvent.h src/main/Grammar/GrammarSystem.cpp src/main/Grammar/GrammarSystem.h src/main/Grammar/GrammarEvent.h src/main/Text/Split.h src/main/Lettering/LetterComponent.h src/main/Lettering/LetterPickupSystem.cpp src/main/Lettering/LetterPickupSystem.h src/main/Lettering/CharacterDepositEvent.h src/main/TerminalUI/LiveTerminalRenderSystem.cpp src/main/TerminalUI/LiveTerminalRenderSystem.h src/main/TerminalUI/FixedPositionComponent.h src/main/Rendering/DynamicRenderSystem.h src/main/TerminalUI/TerminalUnderscoreComponent.h src/main/TerminalUI/TerminalTextUpdateEvent.h src/main/TerminalUI/TakingInputFlipEvent.h src/main/TextCommands/CommandLogSystem.cpp src/main/TextCommands/CommandLogSystem.h src/main/TextCommands/AuthoredCommand.h src/main/TextCommands/Command.h src/main/TerminalUI/TerminalHistoryRenderSystem.cpp src/main/TerminalUI/TerminalHistoryRenderSystem.h src/main/Diegesis/EngineerDialogueSystem.cpp src/main/Diegesis/EngineerDialogueSystem.h src/main/TerminalUI/TerminalRenderer.cpp src/main/TerminalUI/TerminalRenderer.h src/main/Diegesis/EngineerTerminalEvent.h src/main/Lettering/LetterBankRenderSystem.cpp src/main/Lettering/LetterBankRenderSystem.h src/main/Inventory/InventoryRenderSystem.cpp src/main/Inventory/InventoryRenderSystem.h src/main/Rendering/RenderControllerSystem.cpp src/main/Rendering/RenderControllerSystem.h src/main/Rendering/FixedRenderSystem.h src/main/Rendering/TypeToStyleMapper.h src/main/Rendering/RenderStyle.h src/main/Inventory/Inventory.h src/main/Lettering/FreeWordSystem.cpp src/main/Lettering/FreeWordSystem.h src/main/Lettering/FreeWordEvent.h src/main/Lettering/WordDepositEvent.h src/main/Abyz/AbyzComponent.h src/main/Health/HealthComponent.h src/main/Health/PendingDeathComponent.h src/main/Attacking/AttemptedAttackEvent.h src/main/Attacking/SuccessfulAttackEvent.h src/main/Attacking/AttackAttemptSystem.cpp src/main/Attacking/AttackAttemptSystem.h src/main/Health/HealthSystem.cpp src/main/Health/HealthSystem.h src/main/Attacking/AttackableComponent.h src/main/Attacking/AttackType.h src/main/Health/PendingDeathSystem.cpp src/main/Health/PendingDeathSystem.h src/main/Health/OnDeathComponent.h src/main/Creation/CreateItemAtEntityEvent.h src/main/Abyz/AbyzControlSystem.cpp src/main/Abyz/AbyzControlSystem.h src/main/Attacking/ActiveWeaponComponent.h src/main/Health/HealthBarRenderSystem.cpp src/main/Health/HealthBarRenderSystem.h src/main/Levels/FullBasicLevel.cpp src/main/Levels/FullBasicLevel.h src/main/Woodworking/TreePrefab.h src/main/Abyz/PlainAbyzPrefab.h src/main/Lettering/LetterPrefab.h src/main/Woodworking/ForestPrefab.h src/main/PlayerDialogueSystem/PlayerSideTextSystem.cpp src/main/Levels/IntroPac.cpp src/main/Levels/IntroPac.h src/main/Diegesis/EngineerSpeakEvent.h src/main/Woodworking/ChoppableComponent.h src/main/Woodworking/PunchEvent.h src/main/Creation/CreateLetterAtPositionEvent.h src/main/Maze/HorizontalWallPrefab.h src/main/Maze/SolidWallRowPrefab.h src/main/Maze/SolidColumnPrefab.h src/main/Maze/IntroMazePrefab.h src/main/Maze/VerticalWallPrefab.h src/main/Maze/HalfwayOpenWallRowPrefab.h src/main/Maze/HalfwayOpenWallColumnPrefab.h src/main/Maze/IntroMazePrefab.cpp src/main/MainPlayer/RotateEvent.h src/main/MainPlayer/PlayerRotateSystem.cpp src/main/MainPlayer/PlayerRotateSystem.h src/main/MainPlayer/RotateComponent.h
        src/main/LetterMaze/LetterStreamPrefab.h
        src/main/LetterMaze/VerticalLetterStreamPrefab.h
        src/main/UIShow/HideUIEvent.h
        src/main/UIShow/UIControllerSystem.cpp
        src/main/UIShow/UIControllerSystem.h
        src/main/UIShow/HideLetterBankEvent.h
        src/main/UIShow/ShowUIEvent.h
        src/main/UIShow/ShowLetterBankEvent.h
        src/main/Woodworking/FlipEvent.h
        src/main/Woodworking/AxeFlipSystem.cpp
        src/main/Woodworking/AxeFlipSystem.h
        src/main/UIShow/HideHealthBarEvent.h
        src/main/UIShow/ShowHealthBarEvent.h
        src/main/Maze/FourTreePrefab.h
        src/main/Maze/CentralLetterStreamPrefab.h
        src/main/Middlemarch/MiddlemarchStart.cpp
        src/main/Middlemarch/MiddlemarchStart.h
        src/main/Middlemarch/PreludeText.h
        src/main/Middlemarch/NovelTextComponent.h
        src/main/Middlemarch/NovelTextRenderSystem.cpp
        src/main/Middlemarch/NovelTextRenderSystem.h
        src/main/HighLevel/FontGlobals.h
        src/main/HighLevel/TerminalGlobals.h
        src/main/Middlemarch/SubjectComponent.h
        src/main/Middlemarch/SubjectRenderSystem.cpp
        src/main/Middlemarch/SubjectRenderSystem.h
        src/main/Rendering/TextStyles.h
        src/main/Middlemarch/PunctuationMarks.h
        src/main/Middlemarch/WordRelicComponent.h
        src/main/Middlemarch/EndOfReadingEvent.h
        src/main/HighLevel/SystemAddSystem.cpp
        src/main/HighLevel/SystemAddSystem.h
        src/main/Abyz/WordRelicPrioritizingSystem.cpp
        src/main/Abyz/WordRelicPrioritizingSystem.h
        src/main/Abyz/PriorityTargetComponent.h
        src/main/Abyz/AbyzTargetAllocationSystem.cpp
        src/main/Abyz/AbyzTargetAllocationSystem.h
        src/main/Abyz/AbyzRenderingSystem.cpp
        src/main/Abyz/AbyzRenderingSystem.h
        src/main/Abyz/AbyzTargetingComponent.h
        src/main/Abyz/AbyzTargetExecutionSystem.cpp
        src/main/Abyz/AbyzTargetExecutionSystem.h
        src/main/Abyz/JourneyComponent.h
        src/main/Gravity/GravityComponent.h
        src/main/MainPlayer/MainPlayerComponent.h
        src/main/PositionsAndMovement/VelocityComponent.h
        src/main/Gravity/GravitySystem.cpp
        src/main/Gravity/GravitySystem.h
        src/main/Gravity/JumpingComponent.h
        src/main/Gravity/JumpingSystem.cpp
        src/main/Gravity/JumpingSystem.h
        src/main/ECSObjects/FinalSystem.h
        src/main/PositionsAndMovement/RightLeftMovementSystem.cpp
        src/main/PositionsAndMovement/RightLeftMovementSystem.h
        src/main/PositionsAndMovement/WalkingComponent.h
        src/main/Platformer/TargetComponent.h
        src/main/Platformer/TargetRenderingSystem.cpp
        src/main/Platformer/TargetRenderingSystem.h
        src/main/Platformer/TextStepPrefab.h
        src/main/Platformer/PlatformComponent.h
        src/main/Platformer/PlatformGenerationSystem.cpp
        src/main/Platformer/PlatformGenerationSystem.h
        src/main/Spawning/SupremePowerComponent.h
        src/main/Spawning/SupremePowerRenderSystem.cpp
        src/main/Spawning/SupremePowerRenderSystem.h
        src/main/Spawning/SpawnAbyzComponent.h
        src/main/Spawning/SpawnAbyzSystem.cpp
        src/main/Spawning/SpawnAbyzSystem.h
        src/main/Abyz/LifeGateComponent.h
        src/main/Abyz/LifeGateSystem.cpp
        src/main/Abyz/LifeGateSystem.h
        src/main/PositionsAndMovement/RandomRightLeftMovementComponent.h
        src/main/PositionsAndMovement/RandomRightLeftMovementSystem.cpp
        src/main/PositionsAndMovement/RandomRightLeftMovementSystem.h
        src/main/Platformer/ProspectivePlatformLandingEvent.h
        src/main/Platformer/PlatformLandingSystem.cpp
        src/main/Platformer/PlatformLandingSystem.h
        src/main/Platformer/HorizontalPlatformMovementComponent.h
        src/main/Platformer/HorizontalPlatformMovementSystem.cpp
        src/main/Platformer/HorizontalPlatformMovementSystem.h
        src/main/PositionsAndMovement/TopBottomCollisionEvent.h
        src/main/Abyz/AbyzPlatformCollisionHandleSystem.cpp
        src/main/Abyz/AbyzPlatformCollisionHandleSystem.h
        src/main/PositionsAndMovement/RightLeftCollisionEvent.h
        src/main/MainPlayer/DamageSystem.cpp
        src/main/MainPlayer/DamageSystem.h
        src/main/MainPlayer/DamageEvent.h
        src/main/Emma/ReadEmma.cpp
        src/main/Emma/EmmaStart.cpp
        src/main/Emma/EmmaStart.h
)


Message("")
Message( STATUS "SOURCE entry point : " ${SOURCE_FILES} )
Message("")

# ------- End Set Vars --- #

# ------- Executable ----- #

add_library(TextBasedLib OBJECT ${SOURCE_FILES})

#ADD_EXECUTABLE(TextBased ${SOURCE_FILES})

# ------- End Executable - #

# ------- Finds ---------- #

find_package(spdlog CONFIG REQUIRED)

FIND_PACKAGE(SDL2 REQUIRED)
Message("")
Message( STATUS "FINDING SDL2" )
IF (${SDL2_FOUND})
    Message( STATUS "SDL2_FOUND: " ${SDL2_FOUND})
    Message( STATUS "SDL2_INCLUDE_DIR:" ${SDL2_INCLUDE_DIR})
    Message( STATUS "SDL2_LIBRARY: " ${SDL2_LIBRARY})
ELSE()
    Message( STATUS "SDL2_FOUND: " ${SDL2_FOUND})
    Message( FATAL_ERROR "SDL2 NOT FOUND" )
ENDIF()

FIND_PACKAGE(SDL2_IMAGE)
Message("")
Message( STATUS "FINDING SDL2_IMAGE" )
Message( STATUS "SDL2_IMAGE_FOUND: " ${SDL2_IMAGE_FOUND})
IF (${SDL2_IMAGE_FOUND})
    Message( STATUS "SDL2_IMAGE_INCLUDE_DIR: " ${SDL2_IMAGE_INCLUDE_DIR})
    Message( STATUS "SDL2_IMAGE_LIBRARY: " ${SDL2_IMAGE_LIBRARY})
ELSE()
    Message( FATAL_ERROR "SDL2_IMAGE NOT FOUND" )
ENDIF()

FIND_PACKAGE(SDL2TTF)
Message("")
Message( STATUS "FINDING SDL2TTF" )
Message( STATUS "SDL2TTF_FOUND: " ${SDL2TTF_FOUND} )
IF (${SDL2TTF_FOUND})
    Message( STATUS "SDL2TTF_INCLUDE_DIR: " ${SDL2TTF_INCLUDE_DIR})
    Message( STATUS "SDL2TTF_LIBRARY: " ${SDL2TTF_LIBRARY})
ELSE()
    Message( FATAL_ERROR "SDL2TTF NOT FOUND" )
ENDIF()
Message("")

FIND_PACKAGE(SDL2Mixer)

Message( STATUS "FINDING SDL2Mixer" )
Message( STATUS "SDL2Mixer_FOUND: " ${SDL2Mixer_FOUND} )

Message("")

file(COPY resources DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})





# all this Catch2 stuff from here: https://github.com/catchorg/Catch2/blob/devel/docs/cmake-integration.md#top
#Include(FetchContent)
#
#FetchContent_Declare(
#        Catch2
#        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
#        GIT_TAG        v3.0.1 # or a later release
#)
#
#FetchContent_MakeAvailable(Catch2)
#
#add_library(tests src/tests/firstTryTest.cpp src/tests/entityTest.cpp)
#target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
#
## ------- End Finds ------ #
#
## ------- Inc & Link ---- #
##
##

#add_compile_options(-fsanitize=address)
#add_link_options(-fsanitize=address)


include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/0bdaac5a1401fffac6b64581efc639734aded793.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

Include(FetchContent)
FetchContent_Declare(
        spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog.git
        GIT_TAG v1.9.2
)
FetchContent_MakeAvailable(spdlog)


INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIR} ${SDL2TTF_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2Mixer_INCLUDE_DIR})
TARGET_LINK_LIBRARIES(TextBasedLib ${SDL2_LIBRARY} ${SDL2TTF_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2Mixer_LIBRARY} gmock spdlog::spdlog)

ADD_EXECUTABLE(TextBased $<TARGET_OBJECTS:TextBasedLib> src/main/Main.cpp)
ADD_EXECUTABLE(SandboxBased $<TARGET_OBJECTS:TextBasedLib> src/main/Sandbox.cpp)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} TextBasedLib)
TARGET_LINK_LIBRARIES(SandboxBased TextBasedLib)

#
#if(CMAKE_BUILD_TYPE MATCHES "Debug")
#    set(
#            CMAKE_C_FLAGS
#            "${CMAKE_C_FLAGS} -Werror -fsanitize=undefined -fsanitize=address"
#    )
#    target_link_options(TextBased
#            BEFORE PUBLIC -fsanitize=undefined PUBLIC -fsanitize=address
#            )
#endif()


find_package(Catch2 3 REQUIRED)
add_library(test_sources OBJECT src/tests/Catch2SetupTest.cpp src/tests/entityTest.cpp src/tests/Systems/UnitTests/MovementSystemTest.cpp src/tests/TestExternDeclarations.cpp src/tests/TestExternDeclarations.h src/tests/Systems/UnitTests/RenderSystemTest.cpp src/tests/Systems/IntegrationTests/CollisionRemovalTest.cpp src/tests/Systems/UnitTests/CollisionSystemTest.cpp src/tests/Systems/UnitTests/ComponentSignatureTest.cpp src/tests/Canon/CanonStartupTests.cpp src/tests/Canon/CanonMovementTests.cpp src/tests/Canon/GameManagerCanonTest.cpp)
target_link_libraries(test_sources Catch2::Catch2)


target_link_libraries(test_sources gmock)


#ADD_EXECUTABLE(test_tga $<TARGET_OBJECTS:TextBasedLib>
#        src/tests/entityTest.cpp src/tests/firstTryTest.cpp)
## These tests can use the Catch2-provided main
add_executable(tests)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain test_sources TextBasedLib)
#target_link_libraries(tests TextLibraryLib)
#

include(GoogleTest)
include(CTest)
include(Catch)
catch_discover_tests(tests)

# ------- End ----------- #



