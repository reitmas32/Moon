#pragma once

#include <core/gtx/gtx.hpp>

namespace Moon::Core {
    template<typename Type>
    Moon::Alias::GameContextType
    GameContext_t<Type>::getGameContextType() noexcept
    {
        static Moon::Alias::GameContextType type = ++nextType;
        return type;
    }
#if false
    template<typename Type>
    Type& GameContext_t<Type>::addEntity()
    {
        auto& ent = this->entities.createEntity(this->nextId++);
        Moon::Tools::Moon_Log([&]() { spdlog::info("Add Entity_t wiht EntityType {} and eid {}", ent.getEntityType(), this->nextId); });
        return ent;
    }
#endif
#if false
    template<typename Type>
    Type* GameContext_t<Type>::getEntityById(Moon::Alias::EntityId eid)
    {
#ifdef __linux__
    auto it = std::find_if(this->entities.begin(),
                               this->entities.end(),
                               [&](Type& e) { return eid == e.eid; });
        if (it == this->entities.end()) {
            return nullptr;
        }
        return it.base();
#elif _WIN32
        for(Type& var : this->entities){
            if(var.eid == eid){
                return &var;
            }
           
        }
    return nullptr;   
#endif
    }
#endif
} // namespace Moon::Core