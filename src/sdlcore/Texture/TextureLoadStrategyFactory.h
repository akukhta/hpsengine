#pragma once
#include "ITextureLoadStrategy.h"
#include <unordered_map>
#include <typeindex>

namespace SDLCore
{
    class TextureLoadStrategyFactory
    {
    public:
        template <typename StrategyType>
            requires std::is_base_of_v<ITextureLoadStrategy, StrategyType>
        ITextureLoadStrategy* getStrategy()
        {
            if (auto it = strategies.find(std::type_index(typeid(StrategyType))); it == strategies.end())
            {
                strategies[std::type_index(typeid(StrategyType))] = std::make_unique<StrategyType>();
            }
            else
            {
                return it->second.get();
            }
        }

    private:
        std::unordered_map<std::type_index, std::unique_ptr<ITextureLoadStrategy>> strategies;
    };
}