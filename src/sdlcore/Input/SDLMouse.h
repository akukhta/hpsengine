#pragma once
#include "IInputDevice.h"
#include "../Math/Vector2D.h"

namespace SDLCore
{
    class SDLMouse : public IInputDevice
    {
    public:
        void handleEvent(const SDL_Event &event) override;
        Math::IVector2D const& getMousePosition() const;

    private:
        void mouseMove(const SDL_Event &event);
        void mouseButtonPress(const SDL_Event &event);
        Math::IVector2D mousePos;
    };
}
