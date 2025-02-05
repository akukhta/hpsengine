#pragma once
#include "IInputDevice.h"
#include "../Math/Vector2D.h"

namespace SDLCore
{
    class SDLGamepad : public IInputDevice
    {
    public:

        enum Button
        {
            X = SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_X,
            Y = SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_Y,
            B = SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_B,
            A = SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_A,
            LSTICK = SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_LEFTSTICK,
            RSTICK = SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_RIGHTSTICK,
            START = SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_START,
            BACK = SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_BACK,
            DPAD_UP = SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_DPAD_UP,
            DPAD_DOWN = SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_DPAD_DOWN,
            DPAD_LEFT = SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_DPAD_LEFT,
            DPAD_RIGHT = SDL_GameControllerButton::SDL_CONTROLLER_BUTTON_DPAD_RIGHT,
        };

        explicit SDLGamepad(SDL_GameController* controller);
        ~SDLGamepad();

        int stickX(int stickId);
        int stickY(int stickId);
        bool getButtonState(Button button);

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
