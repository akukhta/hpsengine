cmake_minimum_required(VERSION 3.30)
project(sdlplgrd)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")

find_package(SDL2 REQUIRED CONFIG)
find_package(SDL2_image REQUIRED CONFIG)
find_package(SDL2_ttf REQUIRED CONFIG)

add_executable(sdlplgrd main.cpp
        src/sdlcore/SDLCore.cpp
        src/sdlcore/SDLCore.h
        src/sdlcore/SDLWindow.cpp
        src/sdlcore/SDLWindow.h
        src/sdlcore/SDLRenderer.cpp
        src/sdlcore/SDLRenderer.h
        src/sdlcore/SDLTimeController.cpp
        src/sdlcore/SDLTimeController.h
        src/sdlcore/SDLEngine.h
        src/sdlcore/SDLGame.cpp
        src/sdlcore/SDLGame.h
        src/sdlcore/SDLEventHandler.cpp
        src/sdlcore/SDLEventHandler.h
        src/sdlcore/SDLTexture.cpp
        src/sdlcore/SDLTexture.h
        src/sdlcore/IRenderable.h
        src/sdlcore/IRenderer.h
        src/sdlcore/RenderingQueue.cpp
        src/sdlcore/RenderingQueue.h
        src/sdlcore/Components/primitives/RectangleComponent.cpp
        src/sdlcore/Components/primitives/RectangleComponent.h
        src/primitives/Colors.h
        src/sdlcore/Components/primitives/CircleComponent.cpp
        src/sdlcore/Components/primitives/CircleComponent.h
        src/sdlcore/SDLAnimatedSpriteSheet.cpp
        src/sdlcore/SDLAnimatedSpriteSheet.h
        src/sdlcore/Math/Rectangle.h
        src/sdlcore/Texture/ITextureManager.h
        src/sdlcore/Texture/ITextureLoadStrategy.h
        src/sdlcore/Texture/TextureLoadStrategyFactory.h
        src/sdlcore/Texture/LoadBMP.cpp
        src/sdlcore/Texture/LoadBMP.h
        src/sdlcore/Texture/LoadPNG.cpp
        src/sdlcore/Texture/LoadPNG.h
        src/sdlcore/Texture/TextureManager.cpp
        src/sdlcore/Texture/TextureManager.h
        src/sdlcore/IUpdatable.h
        src/sdlcore/GameObject/GameObject.cpp
        src/sdlcore/GameObject/GameObject.h
        src/sdlcore/Scene/Scene.cpp
        src/sdlcore/Scene/Scene.h
        src/sdlcore/Math/Vector2D.h
        src/sdlcore/Components/SpriteComponent.cpp
        src/sdlcore/Components/SpriteComponent.h
        src/sdlcore/Actors/TestActor.cpp
        src/sdlcore/Actors/TestActor.h
        src/sdlcore/Components/IComponent.h
        src/sdlcore/Components/RenderableComponent.h
        src/sdlcore/Components/RenderableComponent.cpp
        src/sdlcore/Components/SpritesheetComponent.cpp
        src/sdlcore/Components/SpritesheetComponent.h
        src/sdlcore/Entity/IEntity.h
        src/sdlcore/Entity/ISceneEntity.h
        src/sdlcore/Components/debug/BoundingBox.cpp
        src/sdlcore/Components/debug/BoundingBox.h
        src/sdlcore/Components/ComponentsMapper.h
        src/sdlcore/Components/ComponentsMapper.cpp
        src/sdlcore/Input/IInputManager.h
        src/sdlcore/Input/SDLInputManager.cpp
        src/sdlcore/Input/SDLInputManager.h
        src/sdlcore/Input/IInputDevice.h
        src/sdlcore/Input/SDLGamepad.cpp
        src/sdlcore/Input/SDLGamepad.h
        src/sdlcore/Input/SDLMouse.cpp
        src/sdlcore/Input/SDLMouse.h
        src/sdlcore/Input/SDLKeyboard.cpp
        src/sdlcore/Input/SDLKeyboard.h
)

add_compile_options(-Wall)
add_compile_options(-Wextra)
add_compile_options(-Werror)

target_link_libraries(${PROJECT_NAME} SDL2::SDL2main)
target_link_libraries(${PROJECT_NAME} SDL2::SDL2)
target_link_libraries(${PROJECT_NAME} SDL2_ttf::SDL2_ttf-static)
target_link_libraries(${PROJECT_NAME} SDL2_image::SDL2_image)
