#pragma once

#include <Engine.h>

class gCNegZone_PSObj;

class GE_DLLIMPORT gCNegZone_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCNegZone_PS() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsReferencedByTemplate() const override;
    public: void GetBoundary(bCBox &, GEBool) override;
    public: void OnPropertySetAdded() override;
    public: void OnPropertySetRemoved() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCNegZone_PS, eCEntityPropertySet)
    GE_PROPERTY(bTValArray<bCVector>, Point, m_arrPoint)
    GE_PROPERTY(GEFloat, Radius, m_fRadius)
    GE_PROPERTY(bCVector, RadiusOffset, m_vecRadiusOffset)
    GE_PROPERTY(GEBool, ZoneIsCCW, m_bZoneIsCCW)
    GE_PADDING(3)
    GE_PROPERTY(bCPropertyID, ZoneEntityID, m_ZoneEntityID)

  public:
    bEResult AddLeftAndRightAngle(bCVector &, bCVector &, GEFloat &, GEFloat &);
    void CreatePSObject();
    bEResult GetAngleSums(GEFloat &, GEFloat &);
    gCNegZone_PSObj *GetPSObject() const;
    GEBool IsZoneIllegal();
    void OnStakesChanged();
    GEBool Test3DPointInZone(bCVector const &, GEBool);

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(4)
};

GE_ASSERT_SIZEOF(gCNegZone_PS, 0x4c)

GE_ASSERT_PROPERTY(gCNegZone_PS, m_arrPoint, 0x14, 12)
GE_ASSERT_PROPERTY(gCNegZone_PS, m_fRadius, 0x20, 4)
GE_ASSERT_PROPERTY(gCNegZone_PS, m_vecRadiusOffset, 0x24, 12)
GE_ASSERT_PROPERTY(gCNegZone_PS, m_bZoneIsCCW, 0x30, 1)
GE_ASSERT_PROPERTY(gCNegZone_PS, m_ZoneEntityID, 0x34, 20)
