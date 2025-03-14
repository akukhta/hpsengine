#include "Scene.h"

std::uint32_t SDLCore::Scene::addObject(GameObject *object)
{
    if (object == nullptr)
    {
        return INVALID_OBJECT;
    }

    std::shared_ptr<GameObject> sceneObject{object};

    return addObject(std::move(sceneObject));
}

std::uint32_t SDLCore::Scene::addObject(GameObject *object, std::string const &objectName)
{
    if (object == nullptr)
    {
        return INVALID_OBJECT;
    }

    std::shared_ptr<GameObject> sceneObject{object};

    return addObject(std::move(sceneObject), objectName);
}

std::uint32_t SDLCore::Scene::addObject(std::shared_ptr<GameObject> object)
{
    auto it = sceneObjects.insert({currentObjectId++, std::move(object)});

    if (!it.second)
    {
        throw std::runtime_error("Could not add object to scene.");
    }

    return it.first->first;
}

std::uint32_t SDLCore::Scene::addObject(std::shared_ptr<GameObject> object, std::string const &objectName)
{
    auto it = sceneObjects.insert({currentObjectId++, std::move(object)});

    if (!it.second)
    {
        throw std::runtime_error("Could not add object to scene.");
    }

    nameToId.insert({objectName, it.first->first});
    idToName.insert({it.first->first, objectName});
    return it.first->first;
}

std::shared_ptr<SDLCore::GameObject> SDLCore::Scene::getObject(std::uint32_t objectId)
{
    if (auto it = sceneObjects.find(objectId); it != sceneObjects.end())
    {
        return it->second;
    }

    return nullptr;
}

std::shared_ptr<SDLCore::GameObject> SDLCore::Scene::getObject(std::string const &objectName)
{
    if (auto it = nameToId.find(objectName); it != nameToId.end())
    {
        if (auto sceneObj = sceneObjects.find(it->second); sceneObj != sceneObjects.end())
        {
            return sceneObj->second;
        }
    }

    return nullptr;
}

void SDLCore::Scene::removeObject(std::uint32_t objectId)
{
    sceneObjects.erase(objectId);

    if (auto it = idToName.find(objectId); it != idToName.end())
    {
        nameToId.erase(it->second);
        idToName.erase(it);
    }
}

void SDLCore::Scene::removeObject(std::string const &objectName)
{
    if (auto it = nameToId.find(objectName); it != nameToId.end())
    {
        sceneObjects.erase(it->second);

        if (auto nameIt = nameToId.erase(it); nameIt != nameToId.end())
        {
            idToName.erase(nameIt->second);
        }
    }
}
