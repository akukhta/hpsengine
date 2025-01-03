#include "SDLCore.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

SDLCore::~SDLCore()
{
    SDL_Quit();
}

bool SDLCore::initSDL()
{
    return SDL_Init(SDL_INIT_EVERYTHING) == 0;
}

bool SDLCore::initImage()
{
    return IMG_Init(IMG_INIT_PNG) == IMG_INIT_PNG;
}

bool SDLCore::initFont()
{
    return TTF_Init() == 0;
}
