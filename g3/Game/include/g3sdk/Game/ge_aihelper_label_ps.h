#pragma once

#include <Engine.h>

class GE_DLLIMPORT gCAIHelper_Label_PS : public eCEntityPropertySet
{
    // clang-format off
    public: virtual GEBool IsInZone() const;
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCAIHelper_Label_PS() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsReferencedByTemplate() const override;
    public: void GetBoundary(bCBox &, GEBool) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCAIHelper_Label_PS, eCEntityPropertySet)

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(gCAIHelper_Label_PS, 0x14)
