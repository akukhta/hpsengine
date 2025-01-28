#pragma once
#include "../Math/Vector2D.h"
#include <memory>

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

        virtual void setOwner(IEntity* owner)
        {
            this->owner = owner;
        }

        virtual IEntity* getOwner() const
        {
            return owner;
        }

        virtual void attach(std::unique_ptr<IEntity> child) = 0;

    protected:
        IEntity* parent = nullptr;
        IEntity* owner = nullptr;
    };
}
