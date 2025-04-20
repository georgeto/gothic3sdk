#pragma once

#include <SharedBase/container/map/ge_objmap.h>
#include <SharedBase/propertysystem/enum/ge_propertycontainer.h>
#include <SharedBase/types/ge_string.h>

class bCEnumWrapper
{
    // clang-format off
    public: virtual bCString const & GetValueString() const = 0;
    public: virtual GEU32            GetValue() const       = 0;
    public: virtual                 ~bCEnumWrapper( )  = 0;
    // clang-format on
};

template <typename ENUMCLASS>
class bTEnumWrapper : public bCEnumWrapper
{
    // clang-format off
    public: bCString const & GetValueString() const override;
    public: GEU32            GetValue() const override;
    public: ~bTEnumWrapper( ) override;
    // clang-format on

  private:
    static bTObjMap<bCString, ENUMCLASS> &GetMapStringToValue();
    static bTObjMap<ENUMCLASS, bCString> &GetMapValueToString();

  public:
    bTEnumWrapper(bCString const &a_strValue, GEU32 a_u32Value);

  public:
    bTEnumWrapper() = delete;
    bTEnumWrapper<ENUMCLASS> &operator=(bTEnumWrapper<ENUMCLASS> const &) = delete;

  private:
    ENUMCLASS m_EnumValue;
};

#include "ge_enumwrapper.inl"

using bTEnumWrapper_DUMMY = bTEnumWrapper<bTPropertyContainer<GEU32>>;
GE_ASSERT_SIZEOF(bTEnumWrapper_DUMMY, 12)
