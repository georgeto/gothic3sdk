#pragma once

#include <Engine.h>

class GE_DLLIMPORT gCBook_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCBook_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: eEPropertySetType GetPropertySetType() const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCBook_PS, eCEntityPropertySet)
    GE_PROPERTY(eCLocString, Header, m_strHeader)
    GE_PROPERTY(eCLocString, LeftText, m_strTextLeft)
    GE_PROPERTY(eCLocString, RightText, m_strTextRight)

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(gCBook_PS, 0x20)

GE_ASSERT_PROPERTY(gCBook_PS, m_strHeader, 0x14, 4)
GE_ASSERT_PROPERTY(gCBook_PS, m_strTextLeft, 0x18, 4)
GE_ASSERT_PROPERTY(gCBook_PS, m_strTextRight, 0x1c, 4)
