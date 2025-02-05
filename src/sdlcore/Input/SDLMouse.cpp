#include "SDLMouse.h"
#include <iostream>

void SDLCore::SDLMouse::handleEvent(const SDL_Event &event)
{
    switch (event.type)
    {
        case SDL_MOUSEMOTION:
        {
            onMouseMove(event);
            break;
        }

        case SDL_MOUSEBUTTONDOWN:
        {
            onMouseButtonPress(event);
            break;
        }

        case SDL_MOUSEBUTTONUP:
        {
            onMouseButtonRelease(event);
            break;
        }
    }
}

SDLCore::Math::IVector2D const & SDLCore::SDLMouse::getMousePosition() const
{
    return mousePos;
}

void SDLCore::SDLMouse::addButtonPressCallback(int button, std::function<void()> callback)
{
    buttonPressCallbacks.insert(std::make_pair(button, std::move(callback)));
}

void SDLCore::SDLMouse::addButtonReleaseCallback(int button, std::function<void()> callback)
{
    buttonReleaseCallbacks.insert(std::make_pair(button, std::move(callback)));
}

size_t SDLCore::SDLMouse::addMouseMoveCallback(std::function<void(int, int)> mouseMoveCallback)
{
    mouseMoveCallbacks.insert(std::make_pair(mouseMoveCallbacks.size(), std::move(mouseMoveCallback)));
}

void SDLCore::SDLMouse::onMouseMove(const SDL_Event &event)
{
    mousePos.x = event.motion.x;
    mousePos.y = event.motion.y;

    for (auto const& [key, cb] : mouseMoveCallbacks)
    {
        cb(mousePos.x, mousePos.y);
    }
}

void SDLCore::SDLMouse::onMouseButtonPress(const SDL_Event &event)
{
    if (auto it = buttonPressCallbacks.find(event.button.button); it != buttonPressCallbacks.end())
    {
        it->second();
    }
}

void SDLCore::SDLMouse::onMouseButtonRelease(const SDL_Event &event)
{
    if (auto it = buttonReleaseCallbacks.find(event.button.button); it != buttonReleaseCallbacks.end())
    {
        it->second();
    }
}
