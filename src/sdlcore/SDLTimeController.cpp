#include "SDLTimeController.h"
#include <SDL2/SDL.h>

std::uint32_t SDLCore::SDLTimeController::getTicks()
{
    return getInstance().getTicksImpl();
}

double SDLCore::SDLTimeController::getDeltaTime()
{
    return getInstance().getDeltaTimeImpl();
}

void SDLCore::SDLTimeController::update()
{
    getInstance().updateImpl();
}

void SDLCore::SDLTimeController::pause()
{
    getInstance().pauseImpl();
}

void SDLCore::SDLTimeController::resume()
{
    getInstance().resumeImpl();
}

void SDLCore::SDLTimeController::reset()
{
    getInstance().resetImpl();
}

SDLCore::SDLTimeController & SDLCore::SDLTimeController::getInstance()
{
    static SDLTimeController instance;
    return instance;
}

double SDLCore::SDLTimeController::getDeltaTimeImpl() const
{
    return deltaTime;
}

void SDLCore::SDLTimeController::updateImpl()
{
    deltaTime = !isPaused ? (SDL_GetTicks() - currentTicks) / 1000. : 0;
    currentTicks = SDL_GetTicks();
}

void SDLCore::SDLTimeController::pauseImpl()
{
    isPaused = true;
}

void SDLCore::SDLTimeController::resumeImpl()
{
    isPaused = false;
}

void SDLCore::SDLTimeController::resetImpl()
{
    deltaTime = 0;
    currentTicks = SDL_GetTicks();
}

std::uint32_t SDLCore::SDLTimeController::getTicksImpl() const
{
    return SDL_GetTicks();
}
