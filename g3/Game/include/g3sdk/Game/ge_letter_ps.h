#pragma once

#include <Engine.h>

class GE_DLLIMPORT gCLetter_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCLetter_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: eEPropertySetType GetPropertySetType() const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCLetter_PS, eCEntityPropertySet)
    GE_PROPERTY(eCLocString, Header, m_strHeader)
    GE_PROPERTY(eCLocString, Text, m_strText)

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(gCLetter_PS, 0x1c)

GE_ASSERT_PROPERTY(gCLetter_PS, m_strHeader, 0x14, 4)
GE_ASSERT_PROPERTY(gCLetter_PS, m_strText, 0x18, 4)
