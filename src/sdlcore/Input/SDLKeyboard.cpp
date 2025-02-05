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

std::uint64_t constexpr makeHotKey(std::uint16_t const mod, std::uint32_t const key)
{
    std::uint64_t result = 0x0000000000000000;
    result |= (static_cast<uint64_t>(mod) << 48) | key;

    return result;
}

void SDLCore::SDLKeyboard::onKeyDown(const SDL_KeyboardEvent &event)
{
    std::cout << "Pressed: " << SDL_GetKeyName(event.keysym.sym) << " " << event.keysym.mod << "\n";

    if (makeHotKey(event) == makeHotKey<SDLK_a, KMOD_LSHIFT>())
    {
        std::cout << "bingo!\n";
    }
}

void SDLCore::SDLKeyboard::onKeyUp(const SDL_KeyboardEvent &event)
{
    //std::cout << "Released: " << SDL_GetKeyName(event.keysym.sym) << "\n";
}
