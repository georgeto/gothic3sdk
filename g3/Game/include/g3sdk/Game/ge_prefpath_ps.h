#pragma once

#include <Engine.h>

class gCPrefPath_PSObj;

class GE_DLLIMPORT gCPrefPath_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCPrefPath_PS() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsReferencedByTemplate() const override;
    public: void GetBoundary(bCBox &, GEBool) override;
    public: void OnPropertySetAdded() override;
    public: void OnPropertySetRemoved() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCPrefPath_PS, eCEntityPropertySet)
    GE_PROPERTY(bTValArray<bCVector>, Point, m_arrPoint)
    GE_PROPERTY(bTValArray<GEFloat>, PointRadius, m_arrPointRadius)
    GE_PROPERTY(GEFloat, Radius, m_fRadius)
    GE_PROPERTY(bCVector, RadiusOffset, m_vecRadiusOffset)
    GE_PROPERTY(bCPropertyID, ZoneEntityID, m_ZoneEntityID)

  public:
    void CreatePSObject();
    gCPrefPath_PSObj *GetPSObject() const;

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(4)
};

GE_ASSERT_SIZEOF(gCPrefPath_PS, 0x54)

GE_ASSERT_PROPERTY(gCPrefPath_PS, m_arrPoint, 0x14, 12)
GE_ASSERT_PROPERTY(gCPrefPath_PS, m_arrPointRadius, 0x20, 12)
GE_ASSERT_PROPERTY(gCPrefPath_PS, m_fRadius, 0x2c, 4)
GE_ASSERT_PROPERTY(gCPrefPath_PS, m_vecRadiusOffset, 0x30, 12)
GE_ASSERT_PROPERTY(gCPrefPath_PS, m_ZoneEntityID, 0x3c, 20)
