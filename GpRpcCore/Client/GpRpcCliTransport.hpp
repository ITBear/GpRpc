#pragma once

#include "../GpRpcCore_global.hpp"
#include "../../../GpCore2/GpUtils/Macro/GpMacroClass.hpp"
#include "../../../GpCore2/GpUtils/Types/Containers/GpContainersT.hpp"
#include "../../../GpCore2/GpUtils/Types/Containers/GpAny.hpp"
#include "../../../GpCore2/GpUtils/Streams/GpByteWriter.hpp"
#include "../../../GpCore2/GpReflection/GpReflectObject.hpp"

namespace GPlatform {

class GpRpcCliTransport
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpRpcCliTransport)
    CLASS_DD(GpRpcCliTransport)

    enum class SerializeRqFnRes
    {
        CONTINUE,
        DONE
    };

    using SerializeRqFnT    = std::function<SerializeRqFnRes(GpByteWriter& aRqWriter)>;
    using ProcessRqRsFnT    = std::function<void(GpAny& aRq)>;

public:
                                    GpRpcCliTransport       (void) noexcept {}
    virtual                         ~GpRpcCliTransport      (void) noexcept {}

    inline void                     SetDefaultProcessFns    (std::optional<SerializeRqFnT>  aBeforeSerializeRqFn,
                                                             std::optional<SerializeRqFnT>  aAfterSerializeRqFn,
                                                             std::optional<ProcessRqRsFnT>  aBeforeProcessFn,
                                                             std::optional<ProcessRqRsFnT>  aAfterProcessFn);

    inline GpReflectObject::SP      ProcessRQ               (std::optional<GpReflectObject::C::Ref::CVal>   aRq,
                                                             const std::vector<const GpReflectModel*>&      aRsTypeStructVariants);

    virtual GpReflectObject::SP     ProcessRQ               (std::optional<GpReflectObject::C::Ref::CVal>   aRq,
                                                             const std::vector<const GpReflectModel*>&      aRsTypeStructVariants,
                                                             std::optional<SerializeRqFnT>                  aBeforeSerializeRqFn,
                                                             std::optional<SerializeRqFnT>                  aAfterSerializeRqFn,
                                                             std::optional<ProcessRqRsFnT>                  aBeforeProcessFn,
                                                             std::optional<ProcessRqRsFnT>                  aAfterProcessFn) = 0;

private:
    std::optional<SerializeRqFnT>   iBeforeSerializeRqFn;
    std::optional<SerializeRqFnT>   iAfterSerializeRqFn;
    std::optional<ProcessRqRsFnT>   iBeforeProcessFn;
    std::optional<ProcessRqRsFnT>   iAfterProcessF;
};

void    GpRpcCliTransport::SetDefaultProcessFns
(
    std::optional<SerializeRqFnT>   aBeforeSerializeRqFn,
    std::optional<SerializeRqFnT>   aAfterSerializeRqFn,
    std::optional<ProcessRqRsFnT>   aBeforeProcessFn,
    std::optional<ProcessRqRsFnT>   aAfterProcessFn
)
{
    iBeforeSerializeRqFn    = aBeforeSerializeRqFn;
    iAfterSerializeRqFn     = aAfterSerializeRqFn;
    iBeforeProcessFn        = aBeforeProcessFn;
    iAfterProcessF          = aAfterProcessFn;
}

GpReflectObject::SP GpRpcCliTransport::ProcessRQ
(
    std::optional<GpReflectObject::C::Ref::CVal>    aRq,
    const std::vector<const GpReflectModel*>&       aRsTypeStructVariants
)
{
    return ProcessRQ
    (
        aRq,
        aRsTypeStructVariants,
        iBeforeSerializeRqFn,
        iAfterSerializeRqFn,
        iBeforeProcessFn,
        iAfterProcessF
    );
}

}//namespace GPlatform
