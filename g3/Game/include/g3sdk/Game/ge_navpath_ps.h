#pragma once

#include <Game/GameEnum.h>

#include <Engine.h>

class gCDynamicCollisionCircle_PS;

class GE_DLLIMPORT gCNavPath_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCNavPath_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsReferencedByTemplate() const override;
    protected: void OnTouch(eCEntity *, eCContactIterator &) override;
    protected: void OnIntersect(eCEntity *, eCContactIterator &) override;
    protected: void OnUntouch(eCEntity *, eCContactIterator &) override;
    public: void GetBoundary(bCBox &, GEBool) override;
    public: void OnPostRead() override;
    public: void OnPropertySetAdded() override;
    public: void OnPropertySetRemoved() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCNavPath_PS, eCEntityPropertySet)
    GE_PROPERTY(bTValArray<bCVector>, Point, m_arrPoint)
    GE_PROPERTY(bTValArray<GEFloat>, Radius, m_arrRadius)
    GE_PROPERTY(GEBool, UnlimitedHeight, m_bUnlimitedHeight)
    GE_PADDING(3)
    GE_PROPERTY(bCPropertyID, ZoneAEntityID, m_ZoneAEntityID)
    GE_PROPERTY(bCPropertyID, ZoneBEntityID, m_ZoneBEntityID)
    GE_PROPERTY(bCVector, ZoneAIntersectionMargin1, m_vecZoneAIntersectionMargin1)
    GE_PROPERTY(bCVector, ZoneAIntersectionMargin2, m_vecZoneAIntersectionMargin2)
    GE_PROPERTY(bCVector, ZoneAIntersectionCenter, m_vecZoneAIntersectionCenter)
    GE_PROPERTY(bCVector, ZoneBIntersectionMargin1, m_vecZoneBIntersectionMargin1)
    GE_PROPERTY(bCVector, ZoneBIntersectionMargin2, m_vecZoneBIntersectionMargin2)
    GE_PROPERTY(bCVector, ZoneBIntersectionCenter, m_vecZoneBIntersectionCenter)
    GE_PROPERTY(GEFloat, TopToleranz, m_fTopToleranz)
    GE_PROPERTY(GEFloat, BottomToleranz, m_fBottomToleranz)
    GE_PROPERTY(GEBool, LinkInnerArea, m_bLinkInnerArea)
    GE_PROPERTY(GEBool, LinkInnerTopArea, m_bLinkInnerTopArea)
    GE_PROPERTY(GEBool, LinkInnerBottomArea, m_bLinkInnerBottomArea)
    GE_PADDING(1)

  public:
    GEFloat CalcAbsHeightDiffFlagAndPrioFlag(bCVector const &, GEBool &, GEBool &);
    bCVector CalcNearestPathPoint(bCVector const &);
    bEResult CalcPathHeights();
    bEResult DeregisterDCCPS(gCDynamicCollisionCircle_PS *);
    GEFloat GetCosts(bCVector const &, bCVector const &) const;
    GEFloat GetCosts() const;
    GEU32 GetNetIndex();
    GEBool GetOpenStatus() const;
    eCEntityProxy const &GetOwner() const;
    GEFloat GetPathBottomHeight();
    GEFloat GetPathTopHeight();
    gESecurityLevel GetSecurityLevel() const;
    gEZoneType GetZoneType() const;
    bEResult RegisterDCCPS(gCDynamicCollisionCircle_PS *);
    void SetNetIndex(GEU32);
    void SetOpenStatus(GEBool);
    void SetOwner(eCEntityProxy const &);
    void SetSecurityLevel(gESecurityLevel);
    void SetZoneType(gEZoneType);
    GEBool Test3DPointOnPath(bCVector const &);
    GEBool TestPointAgainstDCCs(bCVector const &, eCEntity const &);
    GEBool TestStretchOnPath(bCStretch const &);
    GEBool UseNavigationPath(bCVector const &, bCVector const &, bCMatrix &, GEInt &, GEInt &);

  protected:
    void GameReset();
    void Invalidate();

  public:
    bTPtrArray<gCDynamicCollisionCircle_PS *> m_arrDCCPS;
    GEBool m_bOpenStatus;
    GE_PADDING(3)
    GEU32 __UNK_00BC;
    GEU32 __UNK_00C0;
    GEU32 __UNK_00C4;
    GEUInt m_uNetIndex;
    bCMatrix field_CC;
    gEZoneType m_enuZoneType;
    gESecurityLevel m_enuSecurityLevel;
    eCEntityProxy m_Owner;
    GEU16 m_u16Version;
    GE_PADDING(2)
};

GE_ASSERT_SIZEOF(gCNavPath_PS, 0x134)

GE_ASSERT_PROPERTY(gCNavPath_PS, m_arrPoint, 0x14, 12)
GE_ASSERT_PROPERTY(gCNavPath_PS, m_arrRadius, 0x20, 12)
GE_ASSERT_PROPERTY(gCNavPath_PS, m_bUnlimitedHeight, 0x2c, 1)
GE_ASSERT_PROPERTY(gCNavPath_PS, m_ZoneAEntityID, 0x30, 20)
GE_ASSERT_PROPERTY(gCNavPath_PS, m_ZoneBEntityID, 0x44, 20)
GE_ASSERT_PROPERTY(gCNavPath_PS, m_vecZoneAIntersectionMargin1, 0x58, 12)
GE_ASSERT_PROPERTY(gCNavPath_PS, m_vecZoneAIntersectionMargin2, 0x64, 12)
GE_ASSERT_PROPERTY(gCNavPath_PS, m_vecZoneAIntersectionCenter, 0x70, 12)
GE_ASSERT_PROPERTY(gCNavPath_PS, m_vecZoneBIntersectionMargin1, 0x7c, 12)
GE_ASSERT_PROPERTY(gCNavPath_PS, m_vecZoneBIntersectionMargin2, 0x88, 12)
GE_ASSERT_PROPERTY(gCNavPath_PS, m_vecZoneBIntersectionCenter, 0x94, 12)
GE_ASSERT_PROPERTY(gCNavPath_PS, m_fTopToleranz, 0xa0, 4)
GE_ASSERT_PROPERTY(gCNavPath_PS, m_fBottomToleranz, 0xa4, 4)
GE_ASSERT_PROPERTY(gCNavPath_PS, m_bLinkInnerArea, 0xa8, 1)
GE_ASSERT_PROPERTY(gCNavPath_PS, m_bLinkInnerTopArea, 0xa9, 1)
GE_ASSERT_PROPERTY(gCNavPath_PS, m_bLinkInnerBottomArea, 0xaa, 1)
