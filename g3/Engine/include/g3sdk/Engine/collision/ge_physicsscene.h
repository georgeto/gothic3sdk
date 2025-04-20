#pragma once

#include <Engine/EngineEnum.h>
#include <Engine/ge_enginecomponentbase.h>
#include <Engine/ge_physx.h>

#include <SharedBase.h>

class eCCollisionShape;
class eCDynamicEntity;
class eCEffector;
class eCEffectorDesc;
class eCEntity;
class eCJoint;
class eCJointDesc;
class eCPhysicObject;
class eCPhysicQueryReport;

enum eETraceRayHints
{
    eETraceRayHints_TestStaticShapes = 0x1,  // NX_STATIC_SHAPES
    eETraceRayHints_TestDynamicShapes = 0x2, // NX_DYNAMIC_SHAPES
    eETraceRayHints_CreatureClassPlayerOrNPC = 0x8,
    eETraceRayHints_TestIfHasItemPropertySet = 0x10,
    eETraceRayHints_FaceNormal = 0x20, // NX_RAYCAST_FACE_NORMAL
    eETraceRayHints_Normal = 0x40,     // NX_RAYCAST_NORMAL
    eETraceRayHints_Impact = 0x80,     // NX_RAYCAST_IMPACT
    eETraceRayHints_Distance = 0x100,  // NX_RAYCAST_DISTANCE
    eETraceRayHints_MaterialIndex = 0x200,
    eETraceRayHints_UserData = 0x400, // fill userdata array
    eETraceRayHints_MaxDistanceNotFromDirection =
        0x1000, // Don't use magnitude of direction vector as max distance, but instead use the
                // constant 3.402823466385289e38. It is assumed, that the direction vector is normalized.
    eETraceRayHints_IncludeCollisionGroup17 = 0x4000,
    eETraceRayHints_IncludeWater = 0x8000,
};

class eCCollisionPairNotification
{
    GE_UNIMPL_STRUCT(eCCollisionPairNotification)
};

class GE_DLLIMPORT eCPhysicsScene : public eCEngineComponentBase
{
    // clang-format off
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: GEU32 const GetProfileLastTicksFirst() const override;
    public: ~eCPhysicsScene() override;
    public: bEResult PostInitialize() override;
    public: bEResult PreShutdown() override;
    public: bEResult WorldActivate() override;
    public: bEResult WorldDeactivate() override;
    protected: void PostProcess() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCPhysicsScene, eCEngineComponentBase)
    GE_PROPERTY(GEBool, IsPhysicsEnabled, m_bPhysicsEnabled)
    GE_PADDING(1)

  public:
    static eCPhysicsScene &GE_STDCALL GetInstance();
    static GEBool GE_STDCALL g_EntityAdminKillsEntityCallback(eCEntity *);

  public:
    bCOStream &operator>>(bCOStream &);
    bCIStream &operator<<(bCIStream &);

  public:
    void AddCCDEntity(eCEntity *);
    void AddEditorSimulationEntity(eCEntity &);
    void AddHoverEntity(eCEntity *);
    GEBool CollectEntitiesInAABB(bCBox const &, GEBool, eCEntity const *, bTPtrArray<eCEntity *> *, GEU32, GEBool,
                                 eEPropertySetType, GEU16) const;
    GEBool CollectEntitiesInCapsule(bCCapsule const &, GEBool, eCEntity const *, bTPtrArray<eCEntity *> *, GEU32,
                                    GEBool, eEPropertySetType, GEU16) const;
    GEBool CollectEntitiesInOBB(bCOrientedBox const &, GEBool, eCEntity const *, bTPtrArray<eCEntity *> *, GEU32,
                                GEBool, eEPropertySetType, GEU16) const;
    GEBool CollectEntitiesInSphere(bCSphere const &, GEBool, eCEntity const *, bTPtrArray<eCEntity *> *, GEU32, GEBool,
                                   eEPropertySetType, GEU16) const;
    GEBool CollectPolysInAABB(bCBox const &, bTObjArray<bCTriangle> *) const;
    void CopyFrom(eCPhysicsScene const &);
    void CopyTo(eCPhysicsScene &) const;
    NxActor *CreateActor(NxActorDesc &);
    NxConvexMesh *CreateConvexMesh(NxStream &);
    NxActor *CreateDefaultActor(eCEntity const &);
    eCEffector *CreateEffector(eCEntity *, eCEntity *, eCEffectorDesc &);
    eCJoint *CreateJoint(eCEntity *, eCEntity *, eCJointDesc &);
    NxJoint *CreateJointInternal(NxJointDesc &);
    NxSpringAndDamperEffector *CreateSpringAndDamperEffector(NxSpringAndDamperEffectorDesc &);
    NxTriangleMesh *CreateTriangleMesh(NxStream &);
    void Debug_VisualizeTriangle(bCTriangle &);
    void EnableEditorSimulation(eCEntity &);
    void EnableEditorSimulation(bTPtrArray<eCEntity *>);
    void EnableEditorSimulation(GEBool);
    void EntityAdminKillsEntity(eCEntity *);
    eCCollisionPairNotification GetCollisionGroupNotifications(eECollisionGroup, eECollisionGroup) const;
    GEBool GetCollisionGroupsCanCollide(eECollisionGroup, eECollisionGroup) const;
    GEU32 GetCollisionGroupsNotifyFlags(eECollisionGroup, eECollisionGroup) const;
    bCCriticalSectionWin32 &GetCriticalSection();
    GEBool GetEntitiesCanCollide(eCEntity &, eCEntity &, GEBool) const;
    GEBool GetEntityPairsCanCollide(eCEntity &, eCEntity &) const;
    bCVector GetGravityVector() const;
    GEBool GetGroupsCanCollide(eEShapeGroup, eEShapeGroup) const;
    void GetIgnoreEntities(eCEntity &, bTPtrArray<eCEntity *> &);
    GEU32 GetNumRaysCasted() const;
    eCPhysicQueryReport &GetQueryReport();
    GEU32 GetRayProcessingTime() const;
    NxPhysicsSDK &GetSDK();
    NxScene &GetScene();
    GEFloat GetStateAlpha() const;
    GEBool HasEntityFreePlace(eCEntity &, bCMatrix *, GEBool, GEBool, GEFloat) const;
    GEBool HasShapeFreePlace(eCCollisionShape const &, eCEntity const &, bCMatrix *, GEBool, GEBool, GEFloat) const;
    GEBool IsEntityFrozen(eCEntity &) const;
    GEBool IsPlacingEntities() const;
    void GE_STDCALL OnConsoleCommand(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnDebugMenuClicked(bCObjectRefBase *, bCEvent *);
    void GE_STDCALL OnDebugMiscMenuClicked(bCObjectRefBase *, bCEvent *);
    NxActor *PickActor(GEInt, GEInt, GEFloat, bCVector &);
    eCEntity *PickEntity(GEInt, GEInt, GEFloat, bCVector &);
    void PutEntityToGround(eCEntity *);
    void ReleaseActor(NxActor &);
    void ReleaseConvexMesh(NxConvexMesh &);
    void ReleaseEffector(eCEffector &);
    void ReleaseEffectorInternal(NxEffector &);
    void ReleaseJoint(eCJoint &);
    void ReleaseJointInternal(NxJoint &);
    void ReleaseTriangleMesh(NxTriangleMesh &);
    void RemoveCCDEntity(eCEntity *);
    void RemoveEditorSimulationEntity(eCEntity &);
    void SetCollisionGroupNotifications(eECollisionGroup, eECollisionGroup, eCCollisionPairNotification const &);
    void SetEntitiesCanCollide(eCEntity &, eCEntity &, GEBool, GEBool);
    void SetGroupsCanCollide(eEShapeGroup, eEShapeGroup, GEBool);
    void SetQueryFilterCallback(GEBool(GE_STDCALL *)(eCEntity *, eCCollisionShape *));
    void SetQueryIgnoreEntities(bTPtrArray<eCEntity *> &);
    void SetSimulationFPS(GEFloat);
    GEBool TraceRayAllHits(bCVector const &a_Origin, bCVector const &a_Direction, eCEntity const *a_pExcludeEntity,
                           GEU32 a_Hints, eCEntity const * = nullptr,
                           eEPropertySetType a_PropertySetFilter = eEPropertySetType_Unknown,
                           eEShapeGroup a_GroupsMask = eEShapeGroup_Undefined);
    GEBool TraceRayFirstHit(bCVector const &a_Origin, bCVector const &a_Direction, eCEntity const *a_pExcludeEntity,
                            GEU32 a_Hints, eCEntity const * = nullptr,
                            eEPropertySetType a_PropertySetFilter = eEPropertySetType_Unknown,
                            eEShapeGroup a_GroupsMask = eEShapeGroup_Undefined);
    GEBool TraceRayNearestHit(bCVector const &a_Origin, bCVector const &a_Direction, eCEntity const *a_pExcludeEntity,
                              GEU32 a_Hints, eCEntity const * = nullptr,
                              eEPropertySetType a_PropertySetFilter = eEPropertySetType_Unknown,
                              eEShapeGroup a_GroupsMask = eEShapeGroup_Undefined);

  protected:
    void AddDynamicEntity(eCDynamicEntity *);
    void AddPhysicObject(eCPhysicObject *);
    void AddSkeleton(eCPhysicObject *);
    void DebugRender();
    void Invalidate();
    GEBool IsLocked();
    void RemoveDynamicEntity(eCDynamicEntity *);
    void RemoveSkeleton(eCPhysicObject *);
    void Simulate();

  private:
    static eCPhysicsScene *s_pCurrentInstance;

  private:
    void FetchResults();
    void FetchResultsOnDemand();
    void PlaceEntities();
    void SetEntitiesCanCollideInternal(eCEntity &, eCEntity &, GEBool);

  private:
    GE_UNIMPL_MEMBERS(220)
};

GE_ASSERT_SIZEOF(eCPhysicsScene, 0xf4)

GE_ASSERT_PROPERTY(eCPhysicsScene, m_bPhysicsEnabled, 0x14, 1)
