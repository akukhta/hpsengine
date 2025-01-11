#include "TextureManager.h"
#include <stdexcept>

SDLCore::TextureManager::TextureManager(std::unique_ptr<TextureLoadStrategyFactory> loadFactory)
    : loadFactory(std::move(loadFactory)) {}

SDLCore::SDLTexture* SDLCore::TextureManager::getTexture(std::uint32_t textureDescriptor) noexcept
{
    if (auto it = textures.find(textureDescriptor); it != textures.end()) [[likely]]
    {
        return it->second.get();
    }

    return nullptr;
}

SDLCore::SDLTexture& SDLCore::TextureManager::getTexture(std::uint32_t textureDescriptor, const AsRef &tag)
{
    if (auto it = textures.find(textureDescriptor); it != textures.end()) [[likely]]
    {
        return *it->second;
    }
    else
    {
        throw std::runtime_error("Texture does not exist");
    }
}

SDLCore::SDLTexture* SDLCore::TextureManager::getTexture(const std::string &name) noexcept
{
    std::uint32_t textureDescriptor = 0;

    if (auto it = nameDescriptorMap.find(name); it != nameDescriptorMap.end()) [[likely]]
    {
        textureDescriptor = it->second;
    }
    else
    {
        return nullptr;
    }

    return getTexture(textureDescriptor);
}

SDLCore::SDLTexture& SDLCore::TextureManager::getTexture(const std::string &name, const AsRef &tag)
{
    if (auto it = nameDescriptorMap.find(name); it != nameDescriptorMap.end()) [[likely]]
    {
        if (auto texture = textures.find(it->second); texture != textures.end()) [[likely]]
        {
            return *texture->second;
        }
    }

    throw std::runtime_error("Texture with the given name does not exist");
}

std::uint32_t SDLCore::TextureManager::loadTexture(const std::string &fileName, IRenderer *renderer,
                                                   ITextureLoadStrategy *loadStrategy, const std::string &textureName)
{
    auto texture = loadStrategy->load(fileName, renderer);

    if (!texture)
    {
        throw std::runtime_error("Can't load " + textureName + " texture");
    }

    std::uint32_t textureDescriptor = nextTextureDescriptor++;

    textures.insert({textureDescriptor, std::move(texture)});

    if (!textureName.empty())
    {
        nameDescriptorMap.insert({textureName, textureDescriptor});
    }

    return textureDescriptor;
}
