#pragma once
#include "IEntity.h"

namespace SDLCore
{
    class ISceneEntity : public virtual IEntity
    {
    public:
        virtual Math::IVector2D getWorldLocation() const = 0;
        virtual Math::IVector2D getRelativeLocation() const = 0;
    };
}
