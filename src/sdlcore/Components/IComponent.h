#pragma once
#include "../IRenderable.h"
#include "../IUpdatable.h"

namespace SDLCore
{
    class IComponent
    {
    public:
        virtual ~IComponent() = default;

        virtual void setParent(class GameObject* parent) = 0;
        virtual GameObject* getParent() const = 0;
    };
}