#pragma once
#include "../GameObject/GameObject.h"
#include <unordered_map>
#include "IComponent.h"

namespace SDLCore
{
    class ComponentsMapper
    {
    public:
        static ComponentsMapper mapComponents(GameObject &object1, GameObject &object2);

        IComponent *getComponent(IComponent* componentPtr);
    private:
        ComponentsMapper(GameObject &object1, GameObject &object2);
        std::unordered_map<IComponent*, IComponent*> components;
    };
}