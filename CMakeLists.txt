cmake_minimum_required(VERSION 3.13.1)
#set(CMAKE_XCODE_GENERATE_SCHEME ON)
#set(CMAKE_XCODE_SCHEME_ADDRESS_SANITIZER ON)
#set(CMAKE_XCODE_SCHEME_ADDRESS_SANITIZER_USE_AFTER_RETURN ON)

Message("")
Message( STATUS "CMAKE_BINARY_DIR: " ${CMAKE_BINARY_DIR} )
Message( STATUS "CMAKE_SOURCE_DIR: " ${CMAKE_SOURCE_DIR} )
Message( STATUS "CMAKE_COMMAND: " ${CMAKE_COMMAND} )
Message( STATUS "CMAKE_VERSION: " ${CMAKE_VERSION} )
Message( STATUS "CMAKE_C_COMPILER: " ${CMAKE_C_COMPILER} )
Message( STATUS "CMAKE_PROJECT_NAME: " ${CMAKE_PROJECT_NAME} )
Message( STATUS "CMAKE_FINDCMAKE: " ${CMAKE_SOURCE_DIR}/CMAKE )

project(TextBased)

# ------- Set Vars ------- #

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMAKE")
set(SOURCE_FILES
        src/main/Game/Game.cpp src/main/Game/Game.h
        src/main/Game/GameSystems/Renderer/Renderer.cpp src/main/Game/GameSystems/Renderer/Renderer.h
        src/main/Game/GameSystems/Window/Window.cpp src/main/Game/GameSystems/Window/Window.h
        src/main/Game/GameSystems/InputProcessor/InputProcessor.cpp src/main/Game/GameSystems/InputProcessor/InputProcessor.h
        src/main/ECS/Components/PositionComponent.h
        src/main/Helpers/Objects/Position.h src/main/Helpers/Objects/Velocity.h
        src/main/ECS/Systems/UpdateSystems/AutonomousMovementSystem.cpp src/main/ECS/Systems/UpdateSystems/AutonomousMovementSystem.h
        "src/main/ECS/Design/Objects/Entity.cpp" "src/main/ECS/Design/Objects/Entity.h"
        "src/main/ECS/Design/Objects/Component.cpp" "src/main/ECS/Design/Objects/Component.h"
        "src/main/ECS/Design/Objects/System.cpp" "src/main/ECS/Design/Objects/System.h"
        "src/main/ECS/Design/Managers/ECSManager.cpp" "src/main/ECS/Design/Managers/ECSManager.h"
        src/main/ECS/Design/Objects/Pool.cpp src/main/ECS/Design/Objects/Pool.h
        src/main/ECS/Components/MovementComponent.h
        src/main/ECS/Design/Managers/SystemManager.cpp src/main/ECS/Design/Managers/SystemManager.h
        src/main/ECS/Design/Managers/ComponentManager.cpp src/main/ECS/Design/Managers/ComponentManager.h
        src/main/ECS/Design/Managers/EntityManager.cpp src/main/ECS/Design/Managers/EntityManager.h
        src/main/Globals.h
        src/main/ECS/Systems/RenderSystem.cpp src/main/ECS/Systems/RenderSystem.h
        src/main/ECS/Components/TextComponents/TextComponent.h src/main/ECS/Systems/UpdateSystems/UpdateSystem.h
        src/main/Helpers/Objects/Size.h
        src/main/Game/TextGenerator.cpp src/main/Game/TextGenerator.h src/main/Game/GameManager.cpp src/main/Game/GameManager.h
        resources/SDL_FontCache.c resources/SDL_FontCache.h src/main/ECS/Components/CollisionComponent.h
        src/main/ECS/Systems/UpdateSystems/CollisionCheckSystem.cpp src/main/ECS/Systems/UpdateSystems/CollisionCheckSystem.h
        src/main/ECS/Components/StyleComponent.h src/main/Exceptions/NoStyleException.h
        src/main/Game/Levels/Level1.cpp src/main/Game/Levels/Level1.h src/main/Game/GameSystems/Renderer/SDLRenderer.cpp src/main/Game/GameSystems/Renderer/SDLRenderer.h src/main/Helpers/EventSystem/EventBus/EventBus.cpp src/main/Helpers/EventSystem/EventBus/EventBus.h src/main/Helpers/EventSystem/EventCallback/EventFunctionWrapper.cpp src/main/Helpers/EventSystem/EventCallback/EventFunctionWrapper.h src/main/Helpers/EventSystem/Events/Event.h src/main/ECS/Systems/EventCreationSystems/EventProducerSystem.h src/main/ECS/Systems/EventHandlerSystems/CollisionHandleSystem.cpp src/main/ECS/Systems/EventHandlerSystems/CollisionHandleSystem.h src/main/ECS/Systems/EventHandlerSystems/EventConsumerSystem.h src/main/Helpers/EventSystem/Events/CollisionEvent.h src/main/Helpers/EventSystem/Events/KeyEvent.h src/main/ECS/Components/MainPlayerComponent.h src/main/ECS/Systems/EventHandlerSystems/PlayerKeyboardInputSystem.cpp src/main/ECS/Systems/EventHandlerSystems/PlayerKeyboardInputSystem.h src/main/ECS/Components/TextComponents/TreeComponent.h src/main/ECS/Systems/UpdateSystems/CameraFollowSystem.cpp src/main/ECS/Systems/UpdateSystems/CameraFollowSystem.h src/main/ECS/Systems/UpdateSystems/UnprocessedMovements/UnprocessedMovement.cpp src/main/ECS/Systems/UpdateSystems/UnprocessedMovements/UnprocessedMovement.h src/main/ECS/Systems/UpdateSystems/UnprocessedMovements/UnprocessedKeyboardMovementSystem.cpp src/main/ECS/Systems/UpdateSystems/UnprocessedMovements/UnprocessedKeyboardMovementSystem.h)

Message("")
Message( STATUS "SOURCE entry point : " ${SOURCE_FILES} )
Message("")

# ------- End Set Vars --- #

# ------- Executable ----- #

add_library(TextBasedLib OBJECT ${SOURCE_FILES})
ADD_EXECUTABLE(TextBased $<TARGET_OBJECTS:TextBasedLib> src/main/Main.cpp)

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


INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIR} ${SDL2TTF_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2Mixer_INCLUDE_DIR})
TARGET_LINK_LIBRARIES(TextBasedLib ${SDL2_LIBRARY} ${SDL2TTF_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2Mixer_LIBRARY} gmock)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} TextBasedLib)
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
add_library(test_sources OBJECT src/tests/Catch2SetupTest.cpp src/tests/entityTest.cpp src/tests/Systems/UnitTests/MovementSystemTest.cpp src/tests/TestExternDeclarations.cpp src/tests/TestExternDeclarations.h src/tests/Systems/UnitTests/RenderSystemTest.cpp src/tests/Systems/IntegrationTests/CollisionRemovalTest.cpp src/tests/Systems/UnitTests/CollisionSystemTest.cpp)
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



