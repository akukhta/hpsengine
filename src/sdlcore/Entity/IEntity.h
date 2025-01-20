#pragma once
#include "../Math/Vector2D.h"

namespace SDLCore
{
    class IEntity
    {
    public:
        IEntity() = default;
        IEntity(const IEntity&) = default;
        IEntity(IEntity&&) = default;
        IEntity& operator=(const IEntity&) = default;
        IEntity& operator=(IEntity&&) = default;
        virtual ~IEntity() = default;

        virtual void setParent(IEntity* parent)
        {
            this->parent = parent;
        }

        virtual IEntity* getParent() const
        {
            return parent;
        }

    protected:
        IEntity* parent = nullptr;
    };
}
