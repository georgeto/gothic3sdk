#pragma once

#include <Engine/EngineEnum.h>
#include <Engine/ge_frustumelementitem.h>
#include <Engine/ge_node.h>
#include <Engine/io/ge_inpshared.h>

#include <SharedBase.h>

class eCEffector;
class eCEffectorDesc;
class eCEntityPropertySet;
class eCEntityProxyInternal;
class eCFrustumElementItem;
class eCJoint;
class eCJointDesc;
class eCPhysicObject;
class eCTemplateEntity;

struct eSEntityFlags
{
    GEU32 m_Locked : 1;                          // 00000001 0
    GEU32 m_ProcessingDisabled : 1;              // 00000002 1
    GEU32 m_RenderingEnabled : 1;                // 00000004 2
    GEU32 m_Enabled : 1;                         // 00000008 3
    GEU32 __FIXME_4 : 1;                         // 00000010 4
    GEU32 m_DeactivationEnabled : 1;             // 00000020 5
    GEU32 m_Killed : 1;                          // 00000040 6
    GEU32 m_InProcessingRange : 1;               // 00000080 7
    GEU32 m_CachedIn : 1;                        // 00000100 8
    GEU32 m_CachingInOut : 1;                    // 00000200 9
    GEU32 m_Hook : 1;                            // 00000400 10
    GEU32 m_Pickable : 1;                        // 00000800 11
    GEU32 m_CollisionEnabled : 1;                // 00001000 12
    GEU32 __FIXME_13 : 1;                        // 00002000 13
    GEU32 m_InsertType : 4;                      // 0003C000 14..17 // eCEntity::eEInsertType
    GEU32 __FIXME_18 : 1;                        // 00040000 18
    GEU32 m_LocalNodeBoundaryValid : 1;          // 00080000 19
    GEU32 m_WorldNodeBoundaryValid : 1;          // 00100000 20
    GEU32 m_WorldTreeBoundaryValid : 1;          // 00200000 21
    GEU32 __FIXME_22 : 1;                        // 00400000 22
    GEU32 Dynamic : 1;                           // 00800000 23
    GEU32 __FIXME_24 : 1;                        // 01000000 24
    GEU32 m_SpecialDepthTexPassEnabled : 1;      // 02000000 25
    GEU32 m_Processable : 1;                     // 04000000 26
    GEU32 __FIXME_27 : 1;                        // 08000000 27
    GEU32 m_ProcessingRangeOutFadingEnabled : 1; // 10000000 28
    GEU32 m_Temporary : 1;                       // 20000000 29
    GEU32 __FIXME_30 : 1;                        // 40000000 30
    GEU32 __FIXME_31 : 1;                        // 80000000 31
};

class GE_DLLIMPORT eCEntity : public eCNode
{
  public:
    enum eEInsertType
    {
        // TODO: Enumerator values
    };

    // clang-format off
    public: virtual void SetName(bCString const &);
    public: virtual GEBool IsHelperParent() const;
    public: virtual GEBool IsResource() const;
    public: virtual GEBool IsResourceData() const;
    public: virtual GEBool IsKilled() const;
    public: virtual bCVector GetLinearVelocity() const;
    public: virtual void SetLinearVelocity(bCVector const &);
    public: virtual GEBool IsDummy() const;
    protected: virtual bEResult ReadV83(bCIStream &, GEU16);
    protected: virtual bEResult ReadV63(bCIStream &, GEU16);
    protected: virtual void OnUpdatedWorldMatrix();
    protected: virtual void OnUpdatedWorldTreeBoundary();
    protected: virtual void SetWorldTreeBoundary(bCBox const &);
    protected: virtual void SetLocalNodeBoundary(bCBox const &);
    protected: virtual void SetWorldNodeBoundary(bCBox const &);
    public: virtual void SetLocalMatrix(bCMatrix const &);
    public: virtual void SetWorldPosition(bCVector const &);
    public: virtual void SetLocalPosition(bCVector const &);
    public: virtual void UpdateLocalBoundary();
    public: virtual void UpdateParentDependencies();
    public: virtual void UpdateChildDependencies();
    public: virtual GEBool AddPropertySet(eCEntityPropertySet *, GEBool);
    public: virtual GEBool RemovePropertySet(bCString const &);
    public: virtual eCEntityPropertySet * GetPropertySet(eEPropertySetType);
    public: virtual void Kill();
    public: virtual void Decay();
    public: virtual GEBool IsAutoKillEnabled() const;
    protected: virtual GEBool CreateFromTemplate(bCString const &);
    protected: virtual GEBool OnCreateFromTemplate(eCTemplateEntity const &);
    protected: virtual GEBool OnPatchWithTemplate(eCTemplateEntity const &, GEBool, GEBool);
    protected: virtual void SetCreator(eCTemplateEntity *);
    public: virtual eCTemplateEntity const * GetCreator() const;
    public: virtual GEBool HasCreator() const;
    protected: virtual void CopyEntityPrivateData(eCEntity const &, GEBool);
    public: virtual GEU32 Modified();
    public: virtual GEInt OnAction(eCInpShared::eSGameKeyMessage const &);
    public: virtual GEInt OnMouse(eCInpShared::eSInputMessage const &);
    protected: virtual void OnEnterProcessingRange();
    protected: virtual void OnExitProcessingRange();
    protected: virtual void OnUpdateInternals();
    protected: virtual void OnProcess();
    protected: virtual void OnPreProcess();
    protected: virtual void OnPostProcess();
    protected: virtual void OnDeinitialize();
    protected: virtual void OnPostRead();
    protected: virtual void OnCacheIn();
    protected: virtual void OnCacheOut();
    protected: virtual void OnChildrenAvailable();
    public: virtual void Trigger(bCString const &);
    public: virtual void Render(GEI16);
    public: virtual void RenderAlpha(GEI16);
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    protected: ~eCEntity() override;
    public: eCEntity * GetParent() override;
    public: eCEntity const * GetParent() const override;
    public: eCEntity const * GetRoot() const override;
    public: eCEntity const * GetChildAt(GEInt) const override;
    public: eCEntity * GetChildAt(GEInt) override;
    public: void RemoveAllChildren() override;
    public: void ChildrenAvailable(GEBool) override;
    // clang-format on

  public:
    static void GE_STDCALL DisableChildrenAvailableCall(GEBool);
    static void GE_STDCALL EnableEntityPatching(GEBool);
    static void GE_STDCALL EnableForceEntityPatching(GEBool);
    static GEBool GE_STDCALL IsChildrenAvailableDisabled();
    static GEBool GE_STDCALL IsEntityPatchingEnabled();

  public:
    GEBool AddPropertySet(bCPropertyObjectBase *);
    void CacheIn(GEBool);
    void CacheOut(GEBool, GEBool);
    GEBool CanBeDeactivated() const;
    GEBool CanCollideWith(eCEntity *) const;
    eCEntity *CloneIntoWorld() const;
    GEBool CreateFromTemplate(bCPropertyID const &);
    GEBool CreateFromTemplate(eCTemplateEntity const &);
    void CreatePhysicObject();
    void Deinitialize(GEBool);
    void DestroyPhysicObject();
    void DisableProcessing(GEBool);
    void DoDelete();
    void Enable(GEBool);
    void EnableCollision(GEBool);
    void EnableCollisionWith(eCEntity *, GEBool);
    void EnableDeactivation(GEBool);
    void EnablePicking(GEBool, GEBool);
    void EnableRendering(GEBool);
    void EnableShapeCollision(eEShapeGroup, GEBool, GEInt);
    void EnableSpecialDepthTexPass(GEBool);
    bCVector GetAtVector() const;
    bCVector GetAtVectorNormalized() const;
    void GetAziElev(eCEntity const &, GEFloat &, GEFloat &) const;
    void GetAziElev(bCVector const &, GEFloat &, GEFloat &) const;
    eECollisionGroup GetCollisionGroup() const;
    GEU32 GetDataChangedTimeStamp() const;
    GEFloat GetDistanceToEntity(eCEntity const &) const;
    GEFloat GetDistanceToEntity2(eCEntity const &) const;
    GEFloat GetDistanceToEntityApprox(eCEntity const &) const;
    eSEntityFlags const &GetEntityFlags() const;
    eCFrustumElementItem &GetFrustumElementItem();
    eCFrustumElementItem const &GetFrustumElementItem() const;
    eEInsertType GetInsertType() const;
    GEU8 GetLastRenderPriority() const;
    bCMatrix const &GetLocalMatrix() const;
    bCBox const &GetLocalNodeBoundary() const;
    bCVector const &GetLocalPosition() const;
    void GetLocalPosition(bCVector &) const;
    bCQuaternion GetLocalRotation() const;
    void GetLocalRotation(bCQuaternion &) const;
    bCVector const &GetMotionDelta();
    bCString const &GetName() const;
    GEFloat GetObjectCullFactor() const;
    eCPhysicObject *GetPhysicObject();
    eCPhysicObject const *GetPhysicObject() const;
    eCEntityPropertySet *GetPropertySet(bCString const &);
    eCEntityPropertySet const *GetPropertySet(bCString const &) const;
    eCEntityPropertySet const *GetPropertySet(eEPropertySetType) const;
    eCEntityPropertySet *GetPropertySetAt(GEInt);
    eCEntityPropertySet const *GetPropertySetAt(GEInt) const;
    GEInt GetPropertySetCount() const;
    GEInt GetPropertySetIndex(eCEntityPropertySet const *) const;
    void GetPropertySets(bCString const &, bTSmallArray<eCEntityPropertySet *> &);
    GEU16 &GetRefCountTAPoints();
    GEFloat GetRenderAlphaValue() const;
    bCPropertyID const &GetTemplateID() const;
    GEFloat GetUniformScaling() const;
    GEFloat GetVisualLoDFactor() const;
    bCMatrix const &GetWorldMatrix() const;
    bCBox const &GetWorldNodeBoundary() const;
    bCSphere const &GetWorldNodeSphere() const;
    bCVector const &GetWorldPosition() const;
    void GetWorldPosition(bCVector &) const;
    bCQuaternion GetWorldRotation() const;
    void GetWorldRotation(bCQuaternion &) const;
    bCBox const &GetWorldTreeBoundary() const;
    bCSphere const &GetWorldTreeSphere() const;
    GEBool HasCollision() const;
    GEBool HasProcessingRangeEntered() const;
    GEBool HasPropertySet(bCString const &) const;
    GEBool HasPropertySet(eEPropertySetType) const;
    GEBool HasRenderAlphaComponent();
    GEBool HasVisual() const;
    GEBool IsCachedIn() const;
    GEBool IsCachingInOut() const;
    GEBool IsEnabled() const;
    GEBool IsFreeLOS(eCEntity *, GEBool) const;
    GEBool IsHook() const;
    GEBool IsInFOV(eCEntity *) const;
    GEBool IsLocked() const;
    GEBool IsPhysicRelevant() const;
    GEBool IsPickable() const;
    GEBool IsProcessable() const;
    GEBool IsProcessingDisabled() const;
    GEBool IsProcessingRangeOutFadingEnabled() const;
    GEBool IsRenderingEnabled() const;
    GEBool IsSpecialDepthTexPassEnabled() const;
    GEBool IsValidPropertySetIndex(GEInt) const;
    GEBool IsWaitingForPlayer_FollowNPC() const;
    eCEffector *LinkTo(eCEntity *, eCEffectorDesc &);
    eCJoint *LinkTo(eCEntity *, eCJointDesc &);
    void Lock(GEBool);
    void MoveToLocalNode(eCEntity *);
    void MoveToWorldNode(eCEntity *);
    GEBool PatchWithTemplate(bCPropertyID const &, GEBool);
    GEBool PatchWithTemplate(bCString const &, GEBool);
    GEBool PatchWithTemplate(eCTemplateEntity const &, GEBool);
    void PostProcess(GEBool);
    void PostRead(GEBool);
    void PreProcess(GEBool);
    void PrintDebug();
    void Process(GEBool);
    void RemoveAllPropertySets();
    GEBool RemoveChildByNameRecursive(bCString const &);
    void RemoveFromParent(GEBool);
    void RemoveLink(eCEffector &);
    void RemoveLink(eCJoint &);
    GEBool RemovePropertySet(eCEntityPropertySet *);
    GEBool RemovePropertySetAt(GEInt);
    void RenderBoundingBox(GEU32, GEBool, GEBool);
    void RenderCoordinateAxes(GEFloat, GEBool, GEBool, GEBool);
    void RenderName(GEFloat);
    void RenderTranslationAxes(GEFloat, GEBool, GEBool, GEBool);
    void SetCollisionGroup(eECollisionGroup);
    void SetInsertType(eEInsertType);
    void SetLastRenderPriority(GEU8);
    void SetLocalRotation(bCQuaternion const &);
    void SetMotionDelta(bCVector const &);
    void SetObjectCullFactor(GEFloat);
    void SetProcessingRangeOutFadingEnabled(GEBool);
    void SetRenderAlphaValue(GEFloat, GEBool);
    void SetShapeGroup(eEShapeGroup, eEShapeGroup);
    void SetTemporary();
    void SetToWorldMatrix(bCMatrix const &);
    void SetVisualLoDFactor(GEFloat);
    void SetWaitingForPlayer_FollowNPC(GEBool);
    void UpdateGeometry();
    void UpdateInternals(GEBool);

  protected:
    static GEBool ms_bDisableChildrenAvailableCall;
    static GEBool ms_bEntityPatchingEnabled;
    static GEBool ms_bForceEntityPatching;

  protected:
    eCEntity(eCEntity const &);
    eCEntity();

  protected:
    eCEntity const &operator=(eCEntity const &);

  protected:
    void CacheInInternal();
    void CacheOutInternal(GEBool);
    void EnterProcessingRange(GEBool);
    void ExitProcessingRange(GEBool);
    void Invalidate();
    void KillIntern();
    eCEntityProxyInternal *QueryEntityProxyInternal();
    void ReleaseEntityProxyInternal();
    GEU16 SearchForEntity(eEPropertySetType) const;
    void SetAsHook(GEBool);

  private:
    void SetPhysicObject(eCPhysicObject *);
    void SetWorldMatrix(bCMatrix const &);

  public:
    eCPhysicObject *m_pPhysicObject;
    GEFloat m_fRenderAlphaValue;
    GEChar m_u8LastRenderPriority;
    GE_PADDING(0x3)
    eSEntityFlags m_EntityFlags;
    bCMatrix m_WorldMatrix;
    bCMatrix m_LocalMatrix;
    bCBox m_WorldTreeBoundary;
    bCSphere m_WorldTreeSphere;
    bCBox m_WorldNodeBoundary;
    bCSphere m_WorldNodeSphere;
    bCBox m_LocalNodeBoundary;
    GEFloat m_fVisualLoDFactor;
    GEFloat m_fObjectCullFactor;
    GEInt m_uDataChangedTimeStamp;
    GEFloat m_fUniformScaling;
    bCString m_strName;
    bTSmallArray<eCEntityPropertySet *> m_arrPropertySets;
    GE_UNIMPL_MEMBERS(0x8)
    eCFrustumElementItem m_FrustumElementItem;
    GEInt __UNK_018A;
    GEI16 m_u16RefCountTAPoints;
    GE_PADDING(0x2)
    GEInt __UNK_0194;
    GEInt __UNK_0198;
    GEInt __UNK_019A;
    GEInt __UNK_01A0;
    GEBool m_bWaitingForPlayer_FollowNPC;
    GE_PADDING(0x3)
    bCVector m_MotionDelta;
};

GE_ASSERT_SIZEOF(eCEntity, 0x1b4)
