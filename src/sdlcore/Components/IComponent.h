#pragma once
#include "../Entity/IEntity.h"
#include "../Math/Vector2D.h"

namespace SDLCore
{
    class IComponent : virtual public IEntity
    {
    public:
        virtual ~IComponent() = default;
    };
}
