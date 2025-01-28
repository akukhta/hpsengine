#include "ComponentsMapper.h"

SDLCore::ComponentsMapper SDLCore::ComponentsMapper::mapComponents(GameObject &object1, GameObject &object2)
{
    if (typeid(object1) != typeid(object2))
    {
        throw std::runtime_error("ComponentsMapper::mapComponents: wrong type");
    }

    return ComponentsMapper(object1, object2);
}

SDLCore::IComponent * SDLCore::ComponentsMapper::getComponent(IComponent *componentPtr)
{
    if (auto it = components.find(componentPtr); it != components.end())
    {
        return it->second;
    }

    return nullptr;
}

SDLCore::ComponentsMapper::ComponentsMapper(GameObject &object1, GameObject &object2)
{
    if (object1.staticComponents.size() != object2.staticComponents.size())
    {
        throw std::runtime_error("Cannot map object with different set of components");
    }

    for (size_t i = 0; i < object1.staticComponents.size(); ++i)
    {
        components[object1.staticComponents[i].get()] = object2.staticComponents[i].get();
    }
}
