#include "GpRpcMethodsManagerGP.hpp"
#include "../../GpCore2/GpUtils/Exceptions/GpExceptionCode.hpp"

namespace GPlatform {

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
    iFactories.Set(factory.MethodName(), aFactory);
}

void    GpRpcMethodsManagerGP::Register (GpRpcMethodsRegister& aApiMethodsRegister)
{
    aApiMethodsRegister.OnInit(*this);
}

GpReflectObject::SP GpRpcMethodsManagerGP::GenResultOK (void) const
{
    return MakeSP<GpRpcRsResultGPDesc>
    (
        std::u8string(u8"OK"),
        std::u8string(u8""),
        GpRpcRsResultGPDesc::ItemT::C::Vec::SP{}
    );
}

GpReflectObject::SP GpRpcMethodsManagerGP::GenResultEx (const std::exception& e) const
{
    return MakeSP<GpRpcRsResultGPDesc>
    (
        std::u8string(u8"SYSTEM_ERROR"),
        std::u8string(GpUTF::S_STR_To_UTF8(e.what())),
        GpRpcRsResultGPDesc::ItemT::C::Vec::SP{}
    );
}

GpReflectObject::SP GpRpcMethodsManagerGP::GenResultExUnknown (void) const
{
    return MakeSP<GpRpcRsResultGPDesc>
    (
        std::u8string(u8"SYSTEM_ERROR"),
        std::u8string(u8"Unknown exception"),
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
            std::u8string(GpRpcRsResultItemsExceptionCode::SToString(GpRpcRsResultItemsExceptionCode::MULTIPLE_ERRORS)),
            std::u8string(GpUTF::S_STR_To_UTF8(e.what())),
            std::move(e.iItems)
        );
    } catch (const GpExceptionCode& e)
    {
        return MakeSP<GpRpcRsResultGPDesc>
        (
            std::u8string(e.CodeAsText()),
            std::u8string(GpUTF::S_STR_To_UTF8(e.what())),
            GpRpcRsResultGPDesc::ItemT::C::Vec::SP{}
        );
    }

    return GenResultOK();
}

}//namespace GPlatform
