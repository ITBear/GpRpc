#pragma once

#include "GpRpcRsResultItemsException.hpp"

namespace GPlatform {

class GpRpcRsResultItemsManager
{
public:
    using ItemT = GpRpcRsResultGPDesc::ItemT;

public:
                                GpRpcRsResultItemsManager   (void) = default;
                                ~GpRpcRsResultItemsManager  (void) = default;

    inline void                 Add                         (GpReflectObject::SP aItem);
    inline size_t               ItemsCount                  (void) const noexcept;
    [[noreturn]] inline void    Throw                       (const SourceLocationT& aSourceLocation = SourceLocationT::current());

private:
    ItemT::C::Vec::SP           items;
};

void    GpRpcRsResultItemsManager::Add (GpReflectObject::SP aItem)
{
    items.emplace_back(std::move(aItem));
}

size_t  GpRpcRsResultItemsManager::ItemsCount (void) const noexcept
{
    return items.size();
}

void    GpRpcRsResultItemsManager::Throw (const SourceLocationT& aSourceLocation)
{
    throw GpRpcRsResultItemsException(std::move(items), aSourceLocation);
}

}//namespace GPlatform
