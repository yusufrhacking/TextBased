cmake_minimum_required(VERSION 3.13.1)

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
        src/Game/Game.cpp src/Game/Game.h
        src/Main.cpp
        src/Game/GameSystems/Renderer/Renderer.cpp src/Game/GameSystems/Renderer/Renderer.h
        src/Game/GameSystems/Window/Window.cpp src/Game/GameSystems/Window/Window.h
        src/Game/GameSystems/InputProcessor/InputProcessor.cpp src/Game/GameSystems/InputProcessor/InputProcessor.h
        src/ECS/Components/TransformComponent.h
        src/Objects/Position.h src/Objects/Velocity.h
        src/ECS/Systems/MovementSystem.cpp src/ECS/Systems/MovementSystem.h
        "src/ECS/Design/Objects/Entity.cpp" "src/ECS/Design/Objects/Entity.h"
        "src/ECS/Design/Objects/Component.cpp" "src/ECS/Design/Objects/Component.h"
        "src/ECS/Design/Objects/System.cpp" "src/ECS/Design/Objects/System.h"
        "src/ECS/Design/Managers/ECSManager.cpp" "src/ECS/Design/Managers/ECSManager.h"
        src/ECS/Design/Objects/Pool.cpp src/ECS/Design/Objects/Pool.h
        src/ECS/Components/MovementComponent.h
        src/ECS/Design/Managers/SystemManager.cpp src/ECS/Design/Managers/SystemManager.h
        src/ECS/Design/Managers/ComponentManager.cpp src/ECS/Design/Managers/ComponentManager.h
        src/ECS/Design/Managers/EntityManager.cpp src/ECS/Design/Managers/EntityManager.h
        src/Globals.h
        src/ECS/Systems/RenderSystem.cpp src/ECS/Systems/RenderSystem.h
        src/ECS/Components/SpriteComponent.h src/ECS/Systems/UpdateSystem.h
        src/Objects/Size.h
        src/Game/TextGenerator.cpp src/Game/TextGenerator.h src/Game/GameManager.cpp src/Game/GameManager.h
        resources/SDL_FontCache.c resources/SDL_FontCache.h src/ECS/Components/ColliderComponent.h)

Message("")
Message( STATUS "SOURCE entry point : " ${SOURCE_FILES} )
Message("")

# ------- End Set Vars --- #

# ------- Executable ----- #

ADD_EXECUTABLE(TextBased ${SOURCE_FILES})

# ------- End Executable - #

# ------- Finds ---------- #

if(NOT TARGET spdlog)
    # Stand-alone build
    find_package(spdlog REQUIRED)
endif()

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



# ------- End Finds ------ #

# ------- Inc & Link ---- #

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIR} ${SDL2TTF_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2Mixer_INCLUDE_DIR})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARY} ${SDL2TTF_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2Mixer_LIBRARY} spdlog::spdlog_header_only)

# ------- End ----------- #



