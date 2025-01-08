#pragma once
#include "ITextureManager.h"
#include "TextureLoadStrategyFactory.h"
#include <unordered_map>

namespace SDLCore
{
    class TextureManager : public ITextureManager
    {
    public:
        TextureManager(std::unique_ptr<TextureLoadStrategyFactory> loadFactory);

        SDLTexture* getTexture(std::uint32_t textureDescriptor) noexcept override;
        SDLTexture& getTexture(std::uint32_t textureDescriptor, const AsRef &tag) override;

        SDLTexture* getTexture(const std::string &name) noexcept override;
        SDLTexture& getTexture(const std::string &name, const AsRef &tag) override;

        template <typename LoadStrategy>
            requires std::is_base_of_v<ITextureLoadStrategy, LoadStrategy>
        std::uint32_t loadTexture(const std::string &fileName, IRenderer *renderer, const std::string &textureName = std::string{})
        {
            auto loadStrategy = loadFactory->getStrategy<LoadStrategy>();
            return loadTexture(fileName, renderer, loadStrategy, textureName);
        }

        std::uint32_t loadTexture(const std::string &fileName, IRenderer *renderer, ITextureLoadStrategy *loadStrategy,
            const std::string &textureName) override;

    private:
        std::unique_ptr<TextureLoadStrategyFactory> loadFactory;

        std::unordered_map<std::string, std::uint32_t> nameDescriptorMap;
        std::unordered_map<std::uint32_t, std::unique_ptr<SDLTexture>> textures;

        std::uint32_t nextTextureDescriptor = 1;
    };
}
