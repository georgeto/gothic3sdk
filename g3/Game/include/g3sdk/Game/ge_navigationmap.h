#pragma once

#include <Engine.h>

class gCCharacterMovement_PS;
class gCCollisionCircle_PS;
class gCCollisionCircle_PSObj;
class gCDynamicCollisionCircle_PS;
class gCInteraction_PS;
class gCNavOffset_PS;
class gCNavPath_PS;
class gCNavZone_PS;
class gCNavigationAdmin;
class gCNavigation_PS;
class gCNegZone_PS;
class gCPrefPath_PS;

class GE_DLLIMPORT gCNavigationMap
{
  public:
    enum gEWayAreaElementType
    {
        gEWayAreaElementType_NavZone = 0,
        gEWayAreaElementType_NavPath = 1,
        gEWayAreaElementType_ForceDWORD = GE_FORCE_DWORD
    };

    struct gSNavArea
    {
        eCPropertySetProxy m_PropertySetProxy;
        GEBool m_bIsNavPath;
        GE_PADDING(3)
    };

    struct gSWayAreaElement
    {
        bCVector m_Position;
        eCPropertySetProxy m_PropertySetProxy;
        gEWayAreaElementType m_Type;
    };

    struct gSNavObject3fg
    {
        eCPropertySetProxy m_Proxy;
        GEBool m_bIsNavPath;
        GE_PADDING(3);
        bTSmallArray<GEInt> m_arrIndices;
    };

    struct gSNavPathLink3h
    {
        bCVector m_Intersection;
        eCPropertySetProxy m_ZoneProxy;
        eCPropertySetProxy m_PathProxy;
    };

    struct gSWayPointConnection
    {
        GEFloat m_fDistance;
        GEBool m_bBackRoad;
        GE_PADDING(3);
        GEInt m_iIndex3h;
    };

    struct gSWayPoint
    {
        bTSmallArray<gSWayPointConnection> m_arrConnections;
    };

    // clang-format off
    public: virtual ~gCNavigationMap();
    // clang-format on

  public:
    gCNavigationMap(gCNavigationMap const &);
    gCNavigationMap();

  public:
    gCNavigationMap &operator=(gCNavigationMap const &);

  public:
    bEResult BuildLists(bTObjArray<bCString> &, bTObjArray<bCString> &);
    GEBool CanCorrectTarget(gCNavigation_PS *, bCVector const &, GEBool);
    GEBool CanEvade(eCEntity const &, bCVector const &, GEBool);
    GEBool CanGoto(eCEntity const &, eCEntity const &, GEBool, GEBool);
    GEBool CanGoto(eCEntity const &, bCVector const &, eCEntity const *, GEBool, GEBool);
    bEResult CompileStaticNavigationScene(GEBool, bCString const &);
    bEResult CorrectDCCPositions(gCNavigationAdmin *, GEInt, gCNavigation_PS *, gCDynamicCollisionCircle_PS *,
                                 gCNavigation_PS *, gCDynamicCollisionCircle_PS *);
    bEResult CreatePSObjects();
    bEResult DeregisterCollisionCirclePS(gCCollisionCircle_PS *);
    bEResult DeregisterInteractionPS(gCInteraction_PS *);
    bEResult DeregisterNavPathPS(gCNavPath_PS *);
    bEResult DeregisterNavZonePS(gCNavZone_PS *);
    bEResult DeregisterNegZonePS(gCNegZone_PS *);
    bEResult DeregisterPrefPathPS(gCPrefPath_PS *);
    bEResult DetectNetIndices(bCString const &);
    bEResult FindWay(bCVector const &, bCVector const &, gSNavArea const &, gSNavArea const &,
                     bTObjArray<gSWayAreaElement> &, GEBool &, GEBool);
    bEResult FindWay(gCNavigation_PS *);
    bEResult GetNavArea(bCPropertyID const &, gSNavArea &);
    bEResult GetNearestFleePoint(eCEntity const &, eCEntity *, eCEntity *&, GEFloat);
    bCPropertyID const &GetOutOfNavAreaID() const;
    bEResult GetZone(bCVector const &a_Position, bCPropertyID &o_AreaId, GEBool &o_bIsNavPath,
                     GEBool a_bDontConsiderNavPath, GEBool a_bUnk, GEFloat a_fUnk);
    bEResult GetZone(bCVector const &, GEFloat, bCVector const &, GEFloat, bTValArray<bCPropertyID> &,
                     bTValArray<GEBool> &, GEBool, GEBool);
    bEResult GetZone(bCVector const &, GEFloat, bTValArray<bCPropertyID> &, bTValArray<GEBool> &, GEBool, GEBool,
                     bCVector *);
    bEResult GetZone(eCEntity const &, eCEntityProxy &, GEBool &, GEBool, GEBool);
    void Invalidate();
    GEBool IsInZone(bCVector const &, GEFloat, bCPropertyID const &, GEBool, GEBool, bCVector *);
    GEBool IsOnPath(bCVector const &, GEFloat, gCNavPath_PS *);
    bEResult ReadLists();
    bEResult RecompileAIZonePropertiesForNavZones();
    bEResult RegisterCollisionCirclePS(gCCollisionCircle_PS *);
    bEResult RegisterInteractionPS(gCInteraction_PS *);
    bEResult RegisterNavPathPS(gCNavPath_PS *);
    bEResult RegisterNavZonePS(gCNavZone_PS *);
    bEResult RegisterNegZonePS(gCNegZone_PS *);
    bEResult RegisterPrefPathPS(gCPrefPath_PS *);
    bEResult ResetLists();
    bEResult RunNPCNavigation(gCNavigation_PS *, gCCharacterMovement_PS *, GEBool);
    GEBool TestNPCToCorDCCStretch(gCNavigation_PS *, gCDynamicCollisionCircle_PS *);
    bEResult UpdateNavigationEnabledFlags();
    bEResult WriteCriticalNavObjects(bCString &, bTObjArray<bCString> &, bTObjArray<bCString> &, bTObjArray<bCString> &,
                                     bTObjArray<bCString> &, bTObjArray<bCString> &, bTObjArray<bCString> &,
                                     bTObjArray<bCString> &, bTObjArray<bCString> &, bTObjArray<bCString> &,
                                     bTObjArray<bCString> &);
    bEResult WriteLists(bCString const &);
    bEResult WriteNavZoneObjects(bCString &, bTObjArray<bCString> &);

  protected:
    void AddCollisionCircleOffset(bTValArray<bCMotion> &, bCVector const &, bCVector const &, GEBool);
    bEResult DetectEvades(gCNavigation_PS *, bCVector const *, bCVector const *, GEBool);
    GEI8 DetectFinalTarget(gCNavigation_PS *, GEBool);
    GEBool DetectFinalTargetAsCollisionCircleOffset(gCNavigation_PS *, GEBool);
    GEBool DetectFinalTargetAsNPC(gCNavigation_PS *, gCNavigation_PS *, eCEntityProxy &, GEBool);
    GEBool DetectFinalTargetAsOffset(gCNavigation_PS *, gCNavOffset_PS *, eCEntityProxy &, GEBool);
    GEBool DetectFinalTargetAsOffsetOnCircle(gCNavigation_PS *, gCNavOffset_PS *, eCEntityProxy &, GEBool);
    bEResult DetectNextNavPoint(gCNavigation_PS *, GEBool);
    bEResult ExpandCollisionCircleCluster(bCPropertyID const &, gCCollisionCircle_PSObj *,
                                          bTValArray<gCCollisionCircle_PSObj *> &, gCNavigation_PS *);
    GEInt GetNavAreaListIndex(gSNavArea const &);
    GEBool ProceedTraveling(gCNavigation_PS *, gCCharacterMovement_PS *, GEBool);
    void RemoveCurrentDestination(gCNavigation_PS *);
    bEResult RunNavPathEnterAndExitCorrection(gCNavigation_PS *, GEBool);
    bEResult RunPreferredPath(gCNavigation_PS *);
    GEBool SetCurrentTarget(gCNavigation_PS *, gCCharacterMovement_PS *, GEBool);
    GEBool TestEntityObstacles(gCNavigation_PS *, bCVector &, GEBool &, bCPropertyID &, bCStretch &, gCNavZone_PS *,
                               GEI8 &);
    GEBool TestNavZone(gCNavigation_PS *, bCVector &o_Evade, GEBool &o_bAlwaysZero, bCPropertyID &o_EvadeZoneID,
                       bCStretch &a_Stretch, gCNavZone_PS *a_pNavZone);
    GEBool TestNegZones(gCNavigation_PS *, bCVector &, GEBool &, bCPropertyID &, bCStretch &, gCNavZone_PS *);

  public:
    GE_UNIMPL_MEMBERS(0x10)
    bTObjArray<gSNavObject3fg> m_Section3fg;
    bTObjArray<gSNavPathLink3h> m_Section3h;
    bTObjArray<gSWayPoint> m_Section4;
    bTPtrArray<gCNavZone_PS> ListNavZones;
    bTPtrArray<gCNavPath_PS> ListNavPaths;
    bTObjArray<GELPVoid> ListNegZones;
    bTObjArray<GELPVoid> ListCollisionCircles;
    bTObjArray<GELPVoid> ListPrefPaths;
    bTObjArray<GELPVoid> ReadListNegZones;
    bTObjArray<GELPVoid> ReadListCollisionCircles;
    bTObjArray<GELPVoid> ReadListPrefPaths;
    bTPtrArray<gCInteraction_PS *> ListInteractions;
    bTPtrArray<gCInteraction_PS *> ListFleePoints;
    bTObjArray<gSWayAreaElement> ListWayAreaElements;
    bTObjArray<bTObjArray<bTObjArray<eCPropertySetProxy>>> m_arrNavRegions;
    GEFloat m_fMinRasterX;
    GEFloat m_fMaxRasterX;
    GEFloat m_fMinRasterZ;
    GEFloat m_fMaxRasterZ;
    GEFloat m_fRasterSizeX;
    GEFloat m_fRasterSizeZ;
    GEInt m_iPassedHistoryLength_DefaultsTo5;
    eCEntityProxy m_UnkEntityProxy;
    bCPropertyID m_OutOfNavAreaID;
};

GE_ASSERT_SIZEOF(gCNavigationMap, 0x114)

// Section 3fg
struct gSWayNetList1 //@0x14
{
    eCPropertySetProxy proxy1;
    GEU32 unk1;
    GEU16 short1; // Small Array?
    GEU16 short2;
    GELPVoid pointer1;
};

// Section 3h
struct gSWayNetList2 //@0x20
{
    bCVector vec1;
    eCPropertySetProxy proxy1;
    eCPropertySetProxy proxy2;
};

// Section 4
struct gSWayNetList3 //@0x2C
{
    GEU16 short1; // Small Array?
    GEU16 short2;
    GELPVoid pointer1;
};
