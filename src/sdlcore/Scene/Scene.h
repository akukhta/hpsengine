#pragma once
#include <vector>
#include <memory>
#include <unordered_map>
#include "../GameObject/GameObject.h"

namespace SDLCore
{
    /// Scene class is responsible for an aggregation of game objects used in a scene
    /// It stores updatable and renderable objects in a separate containers
    /// The class should support following operations:
    /// 1. adding of objects
    /// 2. Getting a reference to an object by Object's name
    /// 3. Getting a reference to an object by Object's id
    /// 4. Removing of an object from the scene by a name
    /// 5. Removing of an object from the scene by Object's id

    class Scene
    {
    public:
        Scene() = default;

        std::uint32_t addObject(GameObject* object);
        std::uint32_t addObject(GameObject* object, std::string const& objectName);

        std::uint32_t addObject(std::shared_ptr<GameObject> object);
        std::uint32_t addObject(std::shared_ptr<GameObject> object, std::string const& objectName);

        std::shared_ptr<GameObject> getObject(std::uint32_t objectId);
        std::shared_ptr<GameObject> getObject(std::string const& objectName);

    private:
        friend class SDLGame;

        static std::uint32_t constexpr inline INVALID_OBJECT = 0;
        std::uint32_t currentObjectId = INVALID_OBJECT + 1;

        std::unordered_map<std::uint32_t, std::shared_ptr<GameObject>> sceneObjects;

        std::unordered_map<std::string, std::uint32_t> nameToId;
    };
}