cmake_minimum_required(VERSION 3.30)
project(sdlplgrd)

set(CMAKE_CXX_STANDARD 23)

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
        src/sdlcore/SDLEventHandler.h)

target_link_libraries(${PROJECT_NAME} SDL2::SDL2main)
target_link_libraries(${PROJECT_NAME} SDL2::SDL2)
target_link_libraries(${PROJECT_NAME} SDL2_ttf::SDL2_ttf-static)
target_link_libraries(${PROJECT_NAME} SDL2_image::SDL2_image)
