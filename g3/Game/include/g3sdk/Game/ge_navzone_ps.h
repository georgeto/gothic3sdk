#pragma once

#include <Engine.h>

class gCCollisionCircle_PSObj;
class gCDynamicCollisionCircle_PS;
class gCNavigation_PS;
class gCNegZone_PSObj;
class gCPrefPath_PSObj;

class GE_DLLIMPORT gCNavZone_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCNavZone_PS() override;
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
    GE_PROPERTY_SET(gCNavZone_PS, eCEntityPropertySet)
    GE_PROPERTY(bTValArray<bCVector>, Point, m_arrPoint)
    GE_PROPERTY(GEFloat, Radius, m_fRadius)
    GE_PROPERTY(bCVector, RadiusOffset, m_vecRadiusOffset)
    GE_PROPERTY(GEBool, ZoneIsCCW, m_bZoneIsCCW)
    GE_PADDING(3)
    GE_PROPERTY(GEFloat, TopToleranz, m_fTopToleranz)
    GE_PROPERTY(GEFloat, BottomToleranz, m_fBottomToleranz)
    GE_PROPERTY(GEBool, LinkInnerArea, m_bLinkInnerArea)
    GE_PROPERTY(GEBool, LinkInnerTopArea, m_bLinkInnerTopArea)
    GE_PROPERTY(GEBool, LinkInnerBottomArea, m_bLinkInnerBottomArea)
    GE_PADDING(1)

  public:
    void AddCollisionCircleOffset(bTValArray<bCMotion> &, bCVector const &, bCVector const &, GEBool);
    bEResult BuildClusterLists();
    GEFloat CalcAbsHeightDiffFlagAndPrioFlag(bCVector const &, GEBool &, GEBool &);
    bEResult CalcZoneHeights();
    bEResult DeregisterCollisionCirclePSObject(gCCollisionCircle_PSObj *);
    bEResult DeregisterDCCPS(gCDynamicCollisionCircle_PS *);
    bEResult DeregisterNegZonePSObject(gCNegZone_PSObj *);
    bEResult DeregisterPrefPathPSObject(gCPrefPath_PSObj *);
    GEBool DetectCollisionCircleExit(gCNavigation_PS *, bCVector &);
    void DynAttachCollisionCirclePSObj(gCCollisionCircle_PSObj *);
    void DynDeattachCollisionCirclePSObj(gCCollisionCircle_PSObj *);
    bCVector const &Get3DEvade(GEBool);
    GEFloat GetCosts(bCVector const &, bCVector const &) const;
    bCVector2 const &GetEvade(GEBool);
    GEU32 GetNetIndex();
    GEFloat GetZoneBottomHeight();
    GEFloat GetZoneTopHeight();
    GEBool IntersectsStretch(bCStretch const &, GEFloat &, gCNavigation_PS *, GEBool);
    GEBool IsZoneIllegal();
    void OnStakesChanged();
    bEResult RegisterCollisionCirclePSObject(gCCollisionCircle_PSObj *);
    bEResult RegisterDCCPS(gCDynamicCollisionCircle_PS *);
    bEResult RegisterNegZonePSObject(gCNegZone_PSObj *);
    bEResult RegisterPrefPathPSObject(gCPrefPath_PSObj *);
    GEBool SetFirstIntersection(GEFloat &);
    void SetNetIndex(GEU32);
    GEBool Test3DPointInInternalNegZone(bCVector const &);
    // When the point lies on the segment between the last and the first point of the NavZone,
    // then a_bIncludeLastSegment is returned. Used for DCCs, but why?!
    GEBool Test3DPointInZone(bCVector const &a_Point, GEBool a_bIncludeLastSegment);
    GEBool TestPointAgainstCollCircles(bCVector const &, GEBool, GEBool *, GEBool);
    GEBool TestPointAgainstDCCs(bCVector const &, eCEntity const &);
    GEBool TestPointAgainstNegZones(bCVector const &, GEBool);
    GEBool TestStretchAgainstCollCircles(bCStretch const &, GEBool, GEBool);
    GEBool TestStretchAgainstNegZones(bCStretch const &);
    GEBool TestStretchInZone(bCStretch const &);

  protected:
    bEResult AddLeftAndRightAngle(bCVector &, bCVector &, GEFloat &, GEFloat &);
    void GameReset();
    bEResult GetAngleSums(GEFloat &, GEFloat &);
    void Invalidate();

  public:
    bTValArray<GEFloat> m_TestStretch_PerPointFloat;
    int __UNK_004C;
    int __UNK_0050;
    int __UNK_0054;
    int __UNK_0058;
    int __UNK_005C;
    bCStretch m_TestStretch;
    bCVector2 m_TestStretchStart2D;
    bCVector2 m_TestStretchEnd2D;
    bCVector2 m_TestStretchVector2D;
    bCVector2 m_TestStretchOrthogonalOrSomething;
    float m_fInitWith_1_0;
    bCVector2 Intersect1_Vector;
    int Intersect1_StartPoint;
    int Intersect1_EndPoint;
    float m_fInitWith_MINUS0_0000099999997;
    bCVector2 Intersect2_Vector;
    int Intersect2_StartPoint;
    int Intersect2_EndPoint;
    void *m_pIntersectsStretch_Navigation;
    bTPtrArray<gCNegZone_PSObj *> m_arrNegZones;
    bTPtrArray<gCCollisionCircle_PSObj *> m_arrNegCircles;
    bTPtrArray<gCPrefPath_PSObj *> m_arrPrefPaths;
    int __UNK_00E8;
    int __UNK_00EC;
    int __UNK_00F0;
    float fMeanY;
    float fMaxYOffset;
    float fMinYOffset;
    unsigned __int32 m_uNetIndex;
    bCMatrix m_InverseWorldMatrix;
    int __UNK_0144;
};

GE_ASSERT_SIZEOF(gCNavZone_PS, 0x148)

GE_ASSERT_PROPERTY(gCNavZone_PS, m_arrPoint, 0x14, 12)
GE_ASSERT_PROPERTY(gCNavZone_PS, m_fRadius, 0x20, 4)
GE_ASSERT_PROPERTY(gCNavZone_PS, m_vecRadiusOffset, 0x24, 12)
GE_ASSERT_PROPERTY(gCNavZone_PS, m_bZoneIsCCW, 0x30, 1)
GE_ASSERT_PROPERTY(gCNavZone_PS, m_fTopToleranz, 0x34, 4)
GE_ASSERT_PROPERTY(gCNavZone_PS, m_fBottomToleranz, 0x38, 4)
GE_ASSERT_PROPERTY(gCNavZone_PS, m_bLinkInnerArea, 0x3c, 1)
GE_ASSERT_PROPERTY(gCNavZone_PS, m_bLinkInnerTopArea, 0x3d, 1)
GE_ASSERT_PROPERTY(gCNavZone_PS, m_bLinkInnerBottomArea, 0x3e, 1)
