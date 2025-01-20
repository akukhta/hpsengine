#pragma once
#include "../Entity/IEntity.h"
#include "../Math/Vector2D.h"

namespace SDLCore
{
    class IComponent : public IEntity
    {
    public:
        virtual ~IComponent() = default;
    };
}
