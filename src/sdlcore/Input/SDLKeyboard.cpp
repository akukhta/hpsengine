#include "SDLKeyboard.h"
#include <iostream>

void SDLCore::SDLKeyboard::handleEvent(const SDL_Event &event)
{
    switch (event.type)
    {
        case SDL_KEYDOWN:
        {
            onKeyDown(event.key);
            break;
        }
        case SDL_KEYUP:
        {
            onKeyUp(event.key);
            break;
        }

        default:
        {
            break;
        }
    }
}

std::uint64_t SDLCore::SDLKeyboard::makeHotKey(std::int32_t key, uint16_t mods)
{
    std::uint64_t result = static_cast<std::uint64_t>(key);
    result |= static_cast<std::uint64_t>(mods) << 32;

    return result;
}

std::uint64_t SDLCore::SDLKeyboard::makeHotKey(SDL_KeyboardEvent const &keyboardEvent)
{
    return makeHotKey(keyboardEvent.keysym.sym, keyboardEvent.keysym.mod);
}

void SDLCore::SDLKeyboard::addAxis(std::pair<SDL_Keycode, SDL_Keycode> axis, std::function<void(int)> callback)
{
    axisCallbacks.insert(std::make_pair(axis.first, std::bind(callback, -1)));
    axisCallbacks.insert(std::make_pair(axis.second, std::bind(callback, 1)));
}

void SDLCore::SDLKeyboard::addAxis(SDL_Keycode key1, SDL_Keycode key2, std::function<void(int)> callback)
{
    axisCallbacks.insert(std::make_pair(key1, std::bind(callback, -1)));
    axisCallbacks.insert(std::make_pair(key2, std::bind(callback, 1)));
}

void SDLCore::SDLKeyboard::addKeyDownCallback(SDL_Keycode key, std::function<void()> callback)
{
    keydownCallbacks.insert(std::make_pair(makeHotKey(key, KMOD_NONE), std::move(callback)));
}

void SDLCore::SDLKeyboard::addKeyUpCallback(SDL_Keycode key, std::function<void()> callback)
{
    keyupCallbacks.insert(std::make_pair(makeHotKey(key, KMOD_NONE), std::move(callback)));
}

void SDLCore::SDLKeyboard::addKeyDownCallback(std::uint64_t hotkey, std::function<void()> callback)
{
    keydownCallbacks.insert(std::make_pair(hotkey, std::move(callback)));
}

void SDLCore::SDLKeyboard::addKeyUpCallback(std::uint64_t hotkey, std::function<void()> callback)
{
    keyupCallbacks.insert(std::make_pair(hotkey, std::move(callback)));
}

bool SDLCore::SDLKeyboard::getKey(SDL_Scancode key)
{
    int numKeys = 0;
    std::uint8_t const* const keyboard = SDL_GetKeyboardState(&numKeys);

    if (key < numKeys) [[likely]]
    {
        return keyboard[key];
    }

    return false;
}

std::uint64_t constexpr makeHotKey(std::uint16_t const mod, std::uint32_t const key)
{
    std::uint64_t result = 0x0000000000000000;
    result |= (static_cast<uint64_t>(mod) << 48) | key;

    return result;
}

void SDLCore::SDLKeyboard::onKeyDown(const SDL_KeyboardEvent &event)
{
    if (auto axisIt = axisCallbacks.find(event.keysym.sym); axisIt != axisCallbacks.end())
    {
        axisIt->second();
    }
    if (auto it = keydownCallbacks.find(makeHotKey(event)); it != keydownCallbacks.end())
    {
        it->second();
    }
}

void SDLCore::SDLKeyboard::onKeyUp(const SDL_KeyboardEvent &event)
{
    if (auto it = keyupCallbacks.find(makeHotKey(event)); it != keyupCallbacks.end())
    {
        it->second();
    }
}
