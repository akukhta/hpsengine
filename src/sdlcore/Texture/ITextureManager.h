#pragma once
#include "../SDLTexture.h"
#include <string>

namespace SDLCore
{
    class ITextureManager
    {
    public:
        ITextureManager() = default;
        ITextureManager(const ITextureManager&) = default;
        ITextureManager(ITextureManager&&) = default;
        ITextureManager& operator=(const ITextureManager&) = default;
        ITextureManager& operator=(ITextureManager&&) = default;

        virtual ~ITextureManager() = default;

        struct AsRef{};
        static constexpr AsRef GetReference{};

        virtual SDLTexture* getTexture(std::uint32_t textureDescriptor) noexcept = 0;
        virtual SDLTexture& getTexture(std::uint32_t textureDescriptor, AsRef const& tag) = 0;

        virtual SDLTexture* getTexture(const std::string& name) noexcept = 0;
        virtual SDLTexture& getTexture(const std::string& name, AsRef const& tag) = 0;

        // Responsibilities:
        // 1. Load texture by using some strategy (additionally assign a name to the texture) and get a texture's descriptor
        // 2. Get texture by handler
        // 3. Get texture by name

        virtual std::uint32_t loadTexture(std::string const& fileName, IRenderer* renderer, class ITextureLoadStrategy* loadStrategy, std::string const& textureName = std::string{}) = 0;
    };
}
