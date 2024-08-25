#include <GpRpc/GpRpcCoreGP/GpRpcMethodsManagerGP.hpp>
#include <GpRpc/GpRpcCoreGP/RqRs/GpRpcRsResultGPDesc.hpp>
#include <GpRpc/GpRpcCoreGP/RqRs/GpRpcRsResultItemsException.hpp>
#include <GpCore2/GpUtils/Exceptions/GpExceptionCode.hpp>

namespace GPlatform {

GpRpcMethodsManagerGP::GpRpcMethodsManagerGP (void) noexcept
{
}

GpRpcMethodsManagerGP::~GpRpcMethodsManagerGP (void) noexcept
{
}

GpReflectObject::SP GpRpcMethodsManagerGP::GenResultOK (void) const
{
    return MakeSP<GpRpcRsResultGPDesc>
    (
        std::string("OK"),
        std::string(""),
        GpRpcRsResultGPDesc::ItemT::C::Vec::SP{}
    );
}

GpReflectObject::SP GpRpcMethodsManagerGP::GenResultEx (const std::exception& e) const
{
    return MakeSP<GpRpcRsResultGPDesc>
    (
        std::string("SYSTEM_ERROR"),
        std::string(e.what()),
        GpRpcRsResultGPDesc::ItemT::C::Vec::SP{}
    );
}

GpReflectObject::SP GpRpcMethodsManagerGP::GenResultExUnknown (void) const
{
    return MakeSP<GpRpcRsResultGPDesc>
    (
        std::string("SYSTEM_ERROR"),
        std::string("Unknown exception"),
        GpRpcRsResultGPDesc::ItemT::C::Vec::SP{}
    );
}

GpReflectObject::SP GpRpcMethodsManagerGP::CallAndCatch (std::function<void()> aFn) const
{
    try
    {
        aFn();
    } catch (const GpRpcRsResultItemsException& e)
    {
        return MakeSP<GpRpcRsResultGPDesc>
        (
            std::string(GpRpcRsResultItemsExceptionCode::SToString(GpRpcRsResultItemsExceptionCode::MULTIPLE_ERRORS)),
            std::string(e.what()),
            std::move(e.iItems)
        );
    } catch (const GpExceptionCode& e)
    {
        return MakeSP<GpRpcRsResultGPDesc>
        (
            std::string(e.CodeAsText()),
            std::string(e.what()),
            GpRpcRsResultGPDesc::ItemT::C::Vec::SP{}
        );
    }

    return GenResultOK();
}

}// namespace GPlatform
