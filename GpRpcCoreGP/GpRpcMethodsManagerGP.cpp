#include "GpRpcMethodsManagerGP.hpp"
#include "RqRs/GpRpcRqRsGP.hpp"

namespace GPlatform::RPC {

GpRpcMethodsManagerGP::GpRpcMethodsManagerGP (void) noexcept
{
}

GpRpcMethodsManagerGP::~GpRpcMethodsManagerGP (void) noexcept
{
}

void    GpRpcMethodsManagerGP::Init (void)
{
    OnInit();
}

void    GpRpcMethodsManagerGP::Register (GpRpcMethodFactory::SP aFactory)
{
    const auto& factory = aFactory.V();
    iFactories.Register(factory.MethodName(), aFactory);
}

void    GpRpcMethodsManagerGP::Register (GpRpcMethodsRegister& aApiMethodsRegister)
{
    aApiMethodsRegister.OnInit(*this);
}

GpRpcRsResultIfDesc::SP GpRpcMethodsManagerGP::GenResultOK (void) const
{
    return MakeSP<GpRpcRsResultGPDesc>
    (
        std::string("OK"),
        std::string("")
    );
}

GpRpcRsResultIfDesc::SP GpRpcMethodsManagerGP::GenResultEx (const std::exception& e) const
{
    return MakeSP<GpRpcRsResultGPDesc>
    (
        std::string("SYSTEM_ERROR"),
        e.what()
    );
}

GpRpcRsResultIfDesc::SP GpRpcMethodsManagerGP::GenResultExUnknown (void) const
{
    return MakeSP<GpRpcRsResultGPDesc>
    (
        std::string("SYSTEM_ERROR"),
        std::string("Unknown exception")
    );
}

GpRpcRsResultIfDesc::SP GpRpcMethodsManagerGP::CallAndCatch (std::function<void()> aFn) const
{
    try
    {
        aFn();
    } catch (const GpExceptionCode& e)
    {
        return MakeSP<GpRpcRsResultGPDesc>
        (
            std::string(e.CodeAsText()),
            e.what()
        );
    }

    return GenResultOK();
}

}//namespace GPlatform::RPC
