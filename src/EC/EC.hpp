#pragma once

#include <vector>
#include <memory>


namespace EC
{
    class Entity;

    class Component
    {
    public:
        virtual ~Component() = 0;

    protected:
        Entity* owner_;
    };
    inline Component::~Component() {}

    class Entity
    {
    public:
        virtual ~Entity() = 0;
        template <typename C, typename... CArgs>
        void AddComponent(CArgs&&...);

    protected:
        std::vector<std::unique_ptr<Component>> components_;
    };
    inline Entity::~Entity() {}


}

#include "EC.inl"
