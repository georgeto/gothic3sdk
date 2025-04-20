#pragma once

#include <Game/ge_navigationmap.h>

class gCAnchor_PS;
class gCCollisionCircle_PS;
class gCDoor_PS;
class gCDynamicCollisionCircle_PS;
class gCInteraction_PS;
class gCNavPath_PS;
class gCNavZone_PS;
class gCNavigation_PS;
class gCNegZone_PS;
class gCPrefPath_PS;
class gCWaterZone_PS;

class GE_DLLIMPORT gCNavigationAdmin : public eCEngineComponentBase
{
    // clang-format off
    public: GEBool IsValid() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: GEU32 const GetProfileLastTicksFirst() const override;
    public: GEU32 const GetProfileLastTicksSecond() const override;
    public: ~gCNavigationAdmin() override;
    public: bEResult Initialize() override;
    public: bEResult PostInitialize() override;
    public: bEResult Shutdown() override;
    public: void Process() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCNavigationAdmin, eCEngineComponentBase)

  public:
    void CallTheNextOnProcessRoutine();
    GEBool CanCorrectTarget(gCNavigation_PS *, bCVector const &, GEBool);
    GEBool CanEvade(eCEntity const &, bCVector const &, GEBool);
    GEBool CanGoto(eCEntity const &, eCEntity const &, GEBool, GEBool);
    GEBool CanGoto(eCEntity const &, bCVector const &, GEBool, GEBool);
    bEResult CompileNavigationScene(GEBool, bCString, GEBool);
    bEResult DeregisterAnchorPS(gCAnchor_PS *);
    bEResult DeregisterCollisionCirclePS(gCCollisionCircle_PS *);
    bEResult DeregisterDoorPS(gCDoor_PS *);
    bEResult DeregisterInteractionPS(gCInteraction_PS *);
    bEResult DeregisterNavPathPS(gCNavPath_PS *);
    bEResult DeregisterNavZonePS(gCNavZone_PS *);
    bEResult DeregisterNavigationPS(gCNavigation_PS *);
    bEResult DeregisterNavigationPSInROI(gCNavigation_PS *);
    bEResult DeregisterNegZonePS(gCNegZone_PS *);
    bEResult DeregisterPrefPathPS(gCPrefPath_PS *);
    bEResult DeregisterWaterZonePS(gCWaterZone_PS *);
    void DetectWaterContact(gCNavigation_PS *);
    bTValArray<gCAnchor_PS *> const &GetAnchorPSList();
    GEFloat GetDistanceToOcean(bCVector const &, GEFloat &);
    GEFloat GetDistanceToRiver(bCVector const &);
    bTValArray<gCDoor_PS *> const &GetDoorPSList();
    GEU32 GetMaxFreePlayerGotoDistance(GEBool);
    bEResult GetNavArea(bCPropertyID const &, gCNavZone_PS *&, gCNavPath_PS *&);
    bTValArray<gCNavigation_PS *> const &GetNavigationPSInROIList();
    bTValArray<gCNavigation_PS *> const &GetNavigationPSList();
    bEResult GetNearestFleePoint(eCEntity const &, eCEntity *, eCEntity *&, GEFloat);
    bCVector GetNearestNavigationPoint(eCEntity const &, bCVector const &, GEFloat);
    bCPropertyID const &GetOutOfNavAreaID() const;
    bCVector GetRandomNavigationPoint(eCEntity const &, bCVector const &, GEFloat);
    bTValArray<gCWaterZone_PS *> const &GetWaterZonePSList();
    bEResult GetZone(bCVector const &a_Position, bCPropertyID &o_AreaId, GEBool &o_bIsNavPath, GEBool a_bUnk);
    bEResult GetZone(bCVector const &, GEFloat, bTValArray<bCPropertyID> &, bTValArray<GEBool> &, GEBool, bCVector *);
    bEResult GetZone(eCEntity const &, eCEntityProxy &, GEBool &, GEBool);
    void Invalidate();
    bEResult PauseProcessing(GEBool);
    bEResult RegisterAnchorPS(gCAnchor_PS *);
    bEResult RegisterCollisionCirclePS(gCCollisionCircle_PS *);
    bEResult RegisterDoorPS(gCDoor_PS *);
    bEResult RegisterInteractionPS(gCInteraction_PS *);
    bEResult RegisterNavPathPS(gCNavPath_PS *);
    bEResult RegisterNavZonePS(gCNavZone_PS *);
    bEResult RegisterNavigationPS(gCNavigation_PS *);
    bEResult RegisterNavigationPSInROI(gCNavigation_PS *);
    bEResult RegisterNegZonePS(gCNegZone_PS *);
    bEResult RegisterPrefPathPS(gCPrefPath_PS *);
    bEResult RegisterWaterZonePS(gCWaterZone_PS *);
    bEResult ResetProcessing();
    void UpdateEnabledFlags();
    bEResult WriteCriticalNPCs(bCString &, bTObjArray<bCString> &, bTObjArray<bCString> &);

  protected:
    bEResult CheckAllControlledDCCs(GEInt, gCNavigation_PS *, gCDynamicCollisionCircle_PS *, GEBool);
    void GetLocalXZCameraVectors(bCVector &, bCVector &);
    void GE_STDCALL OnPauseNavigation(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnResetNavigation(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnWalkAnimationMixing(bCObjectRefBase *, bCEvent *);
    bEResult RunDynamicNavigation();
    bEResult UpdateNavigationEnabledFlags();

  public:
    bTPtrArray<gCWaterZone_PS *> m_arrRegisteredWaterZones;
    bTPtrArray<gCDoor_PS *> m_arrRegisteredDoors;
    bTPtrArray<gCAnchor_PS *> m_arrRegisteredAnchors;
    bTPtrArray<gCNavigation_PS *> m_arrRegisteredNavigations;
    bTPtrArray<gCNavigation_PS *> m_arrRegisteredNavigationsInROI;
    GEBool m_bUpdateNavigationEnabledFlagsPending;
    GEBool m_bPauseProcessing;
    GEBool o_bResetNavigation;
    GE_PADDING(1)
    gCNavigationMap m_NavigationMap;
    GEU32 m_uProfileLastTicksSecond;
    GEU32 m_uProfileLastTicksFirst;
    GEU8 field_170;
    GE_PADDING(3)
    GEFloat field_174;
    GE_PADDING(4)
    gCDynamicCollisionCircle_PS *gap_17C;
    gCNavigation_PS *gap_180;
    GEFloat m_fMaxFreePlayerGotoDistance;
};

GE_ASSERT_SIZEOF(gCNavigationAdmin, 0x188)
