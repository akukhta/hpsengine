#pragma once
#include "IInputDevice.h"
#include <cstdint>
#include <utility>
#include <functional>
#include <unordered_map>

namespace SDLCore
{
    class SDLKeyboard : public IInputDevice
    {
    public:
        void handleEvent(const SDL_Event &event) override;
        std::uint64_t makeHotKey(std::int32_t key, uint16_t mods);
        std::uint64_t makeHotKey(SDL_KeyboardEvent const& keyboardEvent);

        template <std::int32_t key, std::uint16_t... Mods>
        static constexpr std::uint64_t makeHotKey()
        {
            static_assert(sizeof...(Mods) > 0);

            std::uint64_t result = static_cast<std::uint64_t>(key);
            makeHotKeyHelper<Mods...>(result);

            return result;
        }

        void addAxis(std::pair<SDL_Keycode, SDL_Keycode> axis, std::function<void(int)> callback);
        void addAxis(SDL_Keycode key1, SDL_Keycode key2, std::function<void(int)> callback);
        void addKeyDownCallback(SDL_Keycode key, std::function<void()> callback);
        void addKeyUpCallback(SDL_Keycode key, std::function<void()> callback);
        bool getKey(SDL_Scancode key);

    private:
        void onKeyDown(const SDL_KeyboardEvent &event);
        void onKeyUp(const SDL_KeyboardEvent &event);

        template <std::uint16_t currentMod, std::uint16_t... rest>
        static constexpr void makeHotKeyHelper(std::uint64_t& res)
        {
            res |= (static_cast<std::uint64_t>(currentMod) << 32);

            if constexpr (sizeof...(rest) > 0)
            {
                makeHotKeyHelper<rest...>(res);
            }
        }

        std::unordered_map<SDL_Keycode, std::function<void(int)>> axisCallbacks;
        std::unordered_map<SDL_Keycode, std::function<void()>> keydownCallbacks;
        std::unordered_map<SDL_Keycode, std::function<void()>> keyupCallbacks;
    };
}
