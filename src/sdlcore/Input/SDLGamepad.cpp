#include "SDLGamepad.h"
#include <utility>

SDLCore::SDLGamepad::SDLGamepad(SDL_GameController *controller)
    : controller(controller)
{}

SDLCore::SDLGamepad::~SDLGamepad()
{
    if (controller)
    {
        SDL_GameControllerClose(controller);
    }
}

int SDLCore::SDLGamepad::stickX(int stickId)
{
    switch (stickId)
    {
        case 0:
            return axis01.x;
        case 1:
            return axis34.x;
        default:
            return 0;
    }
}

int SDLCore::SDLGamepad::stickY(int stickId)
{
    switch (stickId)
    {
        case 0:
            return axis01.y;
        case 1:
            return axis34.y;
        default:
            return 0;
    }
}

bool SDLCore::SDLGamepad::getButtonState(Button button)
{
    return controller ? SDL_GameControllerGetButton(controller, static_cast<SDL_GameControllerButton>(button)) : false;
}

void SDLCore::SDLGamepad::handleEvent(const SDL_Event &event)
{
    switch (event.type)
    {
        case SDL_JOYAXISMOTION:
            axisMotion(event);
    }
}

void SDLCore::SDLGamepad::axisMotion(const SDL_Event &event)
{
    auto& axis = getAxis(event.jaxis.axis);

    if (event.jaxis.value > gamepadStickDeadZone)
    {
        axis = 1;
    }
    else if (event.jaxis.value < -gamepadStickDeadZone)
    {
        axis = -1;
    }
    else
    {
        axis = 0;
    }
}

int & SDLCore::SDLGamepad::getAxis(int axisIdx)
{
    switch (axisIdx)
    {
        case 0:
            return axis01.x;
        case 1:
            return axis01.y;
        case 3:
            return axis34.x;
        case 4:
            return axis34.y;
        default:
            std::unreachable();
    }
}
