#pragma once
#include "IInputDevice.h"
#include "../Math/Vector2D.h"
#include <functional>
#include <unordered_map>
namespace SDLCore
{
    class SDLMouse : public IInputDevice
    {
    public:
        void handleEvent(const SDL_Event &event) override;
        Math::IVector2D const& getMousePosition() const;
        void addButtonPressCallback(int button, std::function<void()> callback);
        void addButtonReleaseCallback(int button, std::function<void()> callback);
        size_t addMouseMoveCallback(std::function<void(int, int)> mouseMoveCallback);

    private:
        void onMouseMove(const SDL_Event &event);
        void onMouseButtonPress(const SDL_Event &event);
        void onMouseButtonRelease(const SDL_Event &event);

        std::unordered_map<int, std::function<void()>> buttonPressCallbacks;
        std::unordered_map<int, std::function<void()>> buttonReleaseCallbacks;
        std::unordered_map<size_t, std::function<void(int, int)>> mouseMoveCallbacks;

        Math::IVector2D mousePos;
    };
}
