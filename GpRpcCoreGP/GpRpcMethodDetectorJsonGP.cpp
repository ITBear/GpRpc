#include "GpRpcMethodDetectorJsonGP.hpp"
#include "../../GpJson/GpJsonToObject.hpp"

namespace GPlatform::RPC {

GpRpcMethodDetectorJsonGP::GpRpcMethodDetectorJsonGP (std::string_view aJsonStr) noexcept:
iJsonStr(aJsonStr)
{
}

GpRpcMethodDetectorJsonGP::~GpRpcMethodDetectorJsonGP (void) noexcept
{
}

std::string GpRpcMethodDetectorJsonGP::DetectApiMethodName (void) const
{
    //TODO: use parsing result in upper levels (API payload deserialize). Return jsonObject

    rapidjson::Document                         jsonDOM;
    rapidjson::Document::ConstObject            jsonObject  = GpJsonToObject::SParseJsonDom(iJsonStr, jsonDOM);
    rapidjson::Document::ConstMemberIterator    mit         = jsonObject.FindMember("method");

    THROW_COND_GP
    (
        mit != jsonObject.MemberEnd(),
        "Json member 'method' was not found"_sv
    );

    const auto& mitVal = mit->value;

    return std::string{mitVal.GetString(), mitVal.GetStringLength()};
}

}//namespace GPlatform::RPC
