#pragma once

#include "../../include/gtx/gtx.hpp"

namespace Moon::Core
{
    template <class Type>
    GameContext_t<Type>::GameContext_t()
    {
        this->entities.reserve(NUM_ENTITIES);
    }

    template <class Type>
    GameContext_t<Type>::~GameContext_t()
    {
        /*Nada*/
    }

    template <class Type>
    Moon::Alias::GameContextType GameContext_t<Type>::getGameContextType()
    {
        static Moon::Alias::GameContextType type = ++nextType;
        return type;
    }
    template <class Type>
    Type &GameContext_t<Type>::addEntity()
    {
        auto &ent = this->entities.emplace_back(this->nextId++);
        return ent;
    }

    template <class Type>
    Type *
    GameContext_t<Type>::getEntityById(Moon::Alias::EntityId eid)
    {
        auto it = std::find_if(this->entities.begin(), this->entities.end(), [&](Type &e) { return eid == e.eid; });
        if (it == this->entities.end())
        {
            return nullptr;
        }
        return it.base();
    }

} // namespace Moon::Core