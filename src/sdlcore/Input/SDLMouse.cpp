#include "SDLMouse.h"
#include <iostream>

void SDLCore::SDLMouse::handleEvent(const SDL_Event &event)
{
    switch (event.type)
    {
        case SDL_MOUSEMOTION:
        {
            mouseMove(event);
            break;
        }

        case SDL_MOUSEBUTTONDOWN:
        case SDL_MOUSEBUTTONUP:
        {
            mouseButtonPress(event);
            break;
        }
    }
}

SDLCore::Math::IVector2D const & SDLCore::SDLMouse::getMousePosition() const
{
    return mousePos;
}

void SDLCore::SDLMouse::mouseMove(const SDL_Event &event)
{
    std::cout << "Mouse moved" << std::endl;

    mousePos.x = event.motion.x;
    mousePos.y = event.motion.y;
}

void SDLCore::SDLMouse::mouseButtonPress(const SDL_Event &event)
{
    std::cout << "Mouse button pressed: " << static_cast<unsigned int>(event.button.button) << std::endl;
}
