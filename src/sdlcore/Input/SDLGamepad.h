#pragma once
#include "IInputDevice.h"
#include "../Math/Vector2D.h"

namespace SDLCore
{
    class SDLGamepad : public IInputDevice
    {
    public:
        explicit SDLGamepad(SDL_GameController* controller);
        ~SDLGamepad();

        int stickX(int stickId);
        int stickY(int stickId);

        void handleEvent(const SDL_Event &event) override;

    private:
        void axisMotion(const SDL_Event &event);
        int& getAxis(int axisIdx);

        Math::IVector2D axis01;
        Math::IVector2D axis34;
        Math::IVector2D &leftStick = axis01;
        Math::IVector2D &rightStick = axis01;
        SDL_GameController* controller;

        static constexpr int gamepadStickDeadZone = 10000;
    };
}
