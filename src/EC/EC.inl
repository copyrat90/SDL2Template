#include "EC.hpp"


namespace EC
{
    template <typename C, typename... CArgs>
    void Entity::AddComponent(CArgs&&... componentArgs)
    {
        static_assert(std::is_base_of_v<Component, C>);

        std::unique_ptr<C> component = std::make_unique<C>(std::forward<CArgs>(componentArgs)...);
        component->owner_ = this;
        components_.push_back(std::move(component));
    }
}
