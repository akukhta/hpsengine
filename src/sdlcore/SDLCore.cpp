#include "SDLCore.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

SDLCore::SDLCore::~SDLCore()
{
    SDL_Quit();
}

bool SDLCore::SDLCore::initSDL()
{
    return SDL_Init(SDL_INIT_EVERYTHING) == 0;
}

bool SDLCore::SDLCore::initImage()
{
    return IMG_Init(IMG_INIT_PNG) == IMG_INIT_PNG;
}

bool SDLCore::SDLCore::initFont()
{
    return TTF_Init() == 0;
}

std::unique_ptr<SDLCore::SDLWindow> SDLCore::SDLCore::createWindow(std::string_view title, std::pair<int, int> size,
    std::pair<int, int> pos, bool isShown, bool isFullscreen)
{
    return std::make_unique<SDLWindow>(title, std::move(size), std::move(pos), isShown, isFullscreen);
}

std::unique_ptr<SDLCore::SDLRenderer> SDLCore::SDLCore::createRenderer(std::unique_ptr<SDLWindow> &window)
{
    return std::make_unique<SDLRenderer>(window.get());
}

std::unique_ptr<SDLCore::SDLRenderer> SDLCore::SDLCore::createRenderer(SDLWindow *window)
{
    return std::make_unique<SDLRenderer>(window);
}
