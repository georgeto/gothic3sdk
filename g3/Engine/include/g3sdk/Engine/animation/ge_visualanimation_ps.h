#pragma once

#include <Engine/EngineEnum.h>
#include <Engine/animation/ge_visualanimationfactory.h>
#include <Engine/animation/ge_wrapper_emfx2actor.h>
#include <Engine/entity/ge_entitypropertyset.h>
#include <Engine/ge_effector.h>
#include <Engine/ge_emotion_fx.h>
#include <Engine/ge_springanddampereffector.h>
#include <Engine/ge_stringwrapper.h>
#include <Engine/ge_wrapper_emfx2motion.h>

#include <SharedBase.h>

class NxActor;
class eCResourceAnimationMotion_PS;
class eCResourceDataEntity;
class eCVisualAnimationFactory;
class eCVisualAnimationLipSync;
struct eSEntityLoDInfoDesc;

class GE_DLLIMPORT eCVisualAnimation_PS : public eCEntityPropertySet
{
  public:
    struct eSSubSkeleton
    {
        GE_UNIMPL_STRUCT(eSSubSkeleton)
    };

    struct SStatus
    {
        GE_UNIMPL_STRUCT(SStatus)
    };

  public:
    class eCActorAttachment
    {
      public:
        eCActorAttachment(eCActorAttachment const &);
        explicit eCActorAttachment(eCVisualAnimation_PS *);
        ~eCActorAttachment();

      public:
        eCActorAttachment &operator=(eCActorAttachment const &);

      public:
        void Create(eCEntity *, bCString const &, bCMatrix const *, GEU32, GEBool);
        void Destroy();
        void ForceRelinkNode();
        eCEntity *GetEntity();
        GEBool IsEntityValid();
        GEBool Process(GEU32);
        GEBool ProcessOnce();
        void Read(bCIStream &, GEU16);
        void Write(bCOStream &);
    };

    class eCLookAtConstraint
    {
      public:
        eCLookAtConstraint(eCLookAtConstraint const &);
        explicit eCLookAtConstraint(eCVisualAnimation_PS *);
        ~eCLookAtConstraint();

      public:
        eCLookAtConstraint &operator=(eCLookAtConstraint const &);

      public:
        void Create(bCString const &, bCVector const &, bCVector const &, GEFloat);
        void Destroy();
        void Enable(GEBool);
        void ForceRelinkNode();
        void GetConstraints(bCVector &, bCVector &, GEFloat &) const;
        bCString const &GetNodeName() const;
        void Read(bCIStream &);
        GEBool SetTargetPos(bCVector const &);
        void Write(bCOStream &);
    };

    struct eSMotionDesc
    {
      public:
        enum eEMotionOwner
        {
            // TODO: Enumerator values
        };

      public:
        eSMotionDesc(eSMotionDesc const &);
        explicit eSMotionDesc(bCString const &);
        explicit eSMotionDesc(eCResourceAnimationMotion_PS *);
        explicit eSMotionDesc(eCResourceDataEntity *);
        eSMotionDesc();
        ~eSMotionDesc();

      public:
        eSMotionDesc const &operator=(eSMotionDesc const &);
        bCOStream &operator>>(bCOStream &);
        bCIStream &operator<<(bCIStream &);

      public:
        eCResourceAnimationMotion_PS *GetMotion();
        eCResourceAnimationMotion_PS const *GetMotion() const;
        bCString const &GetMotionFilename() const;
        eEMotionOwner GetMotionOwner() const;
        GEBool IsValid() const;
        void SetMotion(bCString const &);
        void SetMotion(eCResourceAnimationMotion_PS *);
        void SetMotion(eCResourceDataEntity *);
        void SetMotionOwner(eEMotionOwner);
    };

    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCVisualAnimation_PS() override;
    public: bEResult PostInitializeProperties() override;
    protected: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    protected: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsReferencedByTemplate() const override;
    public: GEBool IsVisual() const override;
    public: GEBool IsProcessable() const override;
    public: eCRenderContext * QueryRenderContext() override;
    public: GEBool SupportsRenderDebugOutput() const override;
    public: GEBool HasRenderAlphaComponent() const override;
    protected: eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance() const override;
    public: void GetDependencies(bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> &) override;
    public: eCVisualAnimation_PS * Clone(eCEntity *) const override;
    protected: void OnEnterProcessingRange() override;
    protected: void OnExitProcessingRange() override;
    public: void GetOnScreenDebugLines(GEU32, bTObjArray<eSPropertySetDebugLine> &) const override;
    protected: void OnUpdateInternals() override;
    protected: void OnPostUpdateInternals() override;
    public: void OnCacheIn() override;
    public: void OnCacheOut() override;
    public: void GetBoundary(bCBox &, GEBool) override;
    public: void OnProcess() override;
    public: void OnPreProcess() override;
    public: void OnPostRead() override;
    public: void OnDeinitialize() override;
    public: void OnChildrenAvailable(GEU32, GEU32, eCTemplateEntity *) override;
    public: GEBool IntersectsRay(eSRayIntersectionDesc &, bCMatrix const &, eCCollisionDesc **) const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCVisualAnimation_PS, eCEntityPropertySet)
    GE_PROPERTY(bCAnimationResourceString, ResourceFilePath, m_strResourceFilePath)
    GE_PROPERTY(bCAnimationResourceString, FacialAnimFilePath, m_strFacialAnimFilePath)
    GE_PROPERTY(GEBool, PhysicsControled, m_bIsPhysicsControled)
    GE_PROPERTY(GEBool, ConstrainRootToWorld, m_bConstrainRootToWorld)
    GE_PROPERTY(GEBool, InterBoneCollision, m_bInterBoneCollision)
    GE_PROPERTY(GEBool, SkeletonCollisionEnabled, m_bSkeletonCollisionEnabled)
    GE_PROPERTY(GEBool, BoneRaycastsEnabled, m_bBoneRaycastsEnabled)
    GE_PROPERTY(GEBool, BonesAreBreakable, m_bBonesAreBreakable)
    GE_PADDING(2)
    GE_PROPERTY(GEFloat, BonesBreakMaxForce, m_fBonesBreakMaxForce)
    GE_PROPERTY(GEFloat, BonesBreakMaxTorque, m_fBonesBreakMaxTorque)
    GE_PROPERTY(GEFloat, BoneLinearDamping, m_fBoneLinearDamping)
    GE_PROPERTY(GEFloat, BoneAngularDamping, m_fBoneAngularDamping)
    GE_PROPERTY(GEBool, BoneTwistSpringEnabled, m_bBoneTwistSpringEnabled)
    GE_PADDING(3)
    GE_PROPERTY(GEFloat, BoneTwistSpring, m_fBoneTwistSpring)
    GE_PROPERTY(GEFloat, BoneTwistSpringDamping, m_fBoneTwistSpringDamping)
    GE_PROPERTY(GEBool, BoneSwingSpringEnabled, m_bBoneSwingSpringEnabled)
    GE_PADDING(3)
    GE_PROPERTY(GEFloat, BoneSwingSpring, m_fBoneSwingSpring)
    GE_PROPERTY(GEFloat, BoneSwingSpringDamping, m_fBoneSwingSpringDamping)
    GE_PROPERTY(GEBool, BoneJointSpringEnabled, m_bBoneJointSpringEnabled)
    GE_PADDING(3)
    GE_PROPERTY(GEFloat, BoneJointSpring, m_fBoneJointSpring)
    GE_PROPERTY(GEFloat, BoneJointSpringDamping, m_fBoneJointSpringDamping)
    GE_PROPERTY(GEFloat, BoneProjectionDistance, m_fBoneProjectionDistance)
    GE_ENUMPROP(eEShapeGroup, BoneShapeGroup, m_enuBoneShapeGroup)
    GE_ENUMPROP(eEShapeMaterial, BoneShapeMaterial, m_enuBoneShapeMaterial)
    GE_ENUMPROP(eECollisionGroup, SkeletonShapeGroup, m_enuSkeletonShapeGroup)
    GE_PROPERTY(GEBool, SpringParentNodesOnly, m_bSpringParentNodesOnly)
    GE_PADDING(3)
    GE_PROPERTY(GEFloat, SpringParentNodesScale, m_fSpringParentNodeScale)
    GE_PROPERTY(GEBool, CreateSpringMassCloth, m_bCreateSpringMassCloth)
    GE_PROPERTY(GEBool, DisablePhysicLodding, m_bDisablePhysicLodding)
    GE_PADDING(2)
    GE_OBJECTPROP(eCSpringAndDamperEffector, eCEffector, ClothEffector, m_poClothEffector)
    GE_PROPERTY(GEInt, MaterialSwitch, m_iMaterialSwitch)

  public:
    GEBool AddAttachment(eCEntity *, bCString const &, bCMatrix const *, GEU32, GEBool);
    GEBool AddBodyPart(eCEntity *, bCString const &, GEBool);
    void AddForceAtPos(bCVector, bCVector);
    GEBool AddOnceAttachment(eCEntity *, bCString const &);
    GEBool ClearAttachments();
    GEBool ClearLookAtConstraints();
    GEBool ClearOnceAttachments();
    GEU32 CountSubSkeletons(bTPtrArray<EMotionFX::Node *> *);
    void CreatePhysicsController(GEBool, eCVisualAnimation_PS *);
    void DestroyPhysicsController();
    void DisablePhysicsController(GEBool);
    void EnableAutoAiming(GEBool, eCEntity *, bCString &);
    void EnableSkeletonCollision(GEBool);
    void EnableSkeletonCollisionWith(eCEntity *, GEBool);
    eCWrapper_emfx2Actor *GetActor();
    eCWrapper_emfx2Actor const *GetActor() const;
    eCVisualAnimationFactory &GetAnimationFactory();
    eCVisualAnimationFactory const &GetAnimationFactory() const;
    GEBool GetBoneMatrix(bCString const &, bCMatrix &);
    GEBool GetBoneMatrix(GEInt, bCMatrix &);
    eCVisualAnimation_PS *GetChildByActor(NxActor *);
    GEU16 GetCurrentLoDLevel() const;
    GEBool GetDebugMode();
    GEFloat GetLastAutoAimAngle();
    GEFloat GetLocalTimeScale() const;
    GEBool GetLookAtConstraintAt(GEInt, bCString &, bCVector &, bCVector &, GEFloat &) const;
    GEInt GetLookAtConstraintCount() const;
    eCWrapper_emfx2Motion &GetMotion(eCWrapper_emfx2Actor::eEMotionType);
    eSMotionDesc const &GetMotionDesc(eCWrapper_emfx2Actor::eEMotionType);
    eSMotionDesc::eEMotionOwner GetMotionOwner(eCWrapper_emfx2Actor::eEMotionType) const;
    GEU32 GetNumAttachments();
    EMotionFX::eCNovodexPhysicsController *GetRagDollController();
    GEBool GetRagDollEnabled() const;
    GEBool GetShowSkeleton();
    bCBox const &GetSkeletonBoundary() const;
    bTObjArray<eSSubSkeleton> *GetSubSkeletons();
    GEBool HasActor() const;
    GEBool HasMotion(eCWrapper_emfx2Actor::eEMotionType) const;
    GEInt IntersectPhysicsRayNearestHit(bCUnitedRay const &, GEFloat &, bCString *) const;
    GEBool IsAutoAimingEnabled() const;
    GEBool IsBodyPartVisible(bCString const &);
    void PausePhysicsController(GEBool, GEFloat);
    GEBool PlayFacialMotion(eCResourceAnimationMotion_PS *, eCVisualAnimationLipSync *);
    void PlayMotion(eCWrapper_emfx2Actor::eEMotionType, eCWrapper_emfx2Motion::eSMotionDesc *);
    void ProcessPhysicsLOD();
    GEBool RelinkAttachments();
    GEBool RelinkLookAtConstraints();
    GEBool RemoveAttachment(eCEntity *);
    GEBool RemoveBodyPart(eCEntity *, bCString const &);
    GEBool RemoveLookAtConstraint(bCString const &);
    GEBool RemoveOnceAttachment(eCEntity *);
    GEBool SetBodyPartVisible(bCString const &, GEBool);
    void SetDebugMode(GEBool);
    void SetForceAlwaysVisible(GEBool);
    void SetLocalTimeScale(GEFloat);
    GEBool SetLookAtConstraint(bCString const &, bCVector const &, bCVector const &, GEFloat);
    void SetLookAtTarget(eCEntity *);
    void SetLookAtTarget(eCEntity *, bCString const &);
    void SetMotion(eCWrapper_emfx2Actor::eEMotionType, eCResourceAnimationMotion_PS *);
    void SetMotion(eCWrapper_emfx2Actor::eEMotionType, eCResourceDataEntity *);
    void SetMotionOwner(eCWrapper_emfx2Actor::eEMotionType, eSMotionDesc::eEMotionOwner);
    void SetRagDollEnabled(GEBool, GEFloat, GEBool);
    void SetShowSkeleton(GEBool);
    void StopAtLoopEnd(eCWrapper_emfx2Actor::eEMotionType);
    GEBool StopFacialMotion();
    void StopMotion(eCWrapper_emfx2Actor::eEMotionType, GEFloat);
    void StopRagDoll();
    void UpdateAim();
    void UpdateLoD(eSEntityLoDInfoDesc const *);

  protected:
    void DrawSkeleton();
    void GameReset();
    void GetStatus(SStatus &);
    void Invalidate();
    void PlayAni_Debug(bCString, bCString, GEFloat);
    void ShowDebug();
    void StopAni_Debug();
    void UpdateFrameEffects();

  public:
    eCVisualAnimationFactory m_AnimationFactory;
    GE_UNIMPL_MEMBERS(0xe4)
};

GE_ASSERT_SIZEOF(eCVisualAnimation_PS, 0x1a8)

GE_ASSERT_PROPERTY(eCVisualAnimation_PS, m_strResourceFilePath, 0x14, 4)
GE_ASSERT_PROPERTY(eCVisualAnimation_PS, m_strFacialAnimFilePath, 0x18, 4)
GE_ASSERT_PROPERTY(eCVisualAnimation_PS, m_bIsPhysicsControled, 0x1c, 1)
GE_ASSERT_PROPERTY(eCVisualAnimation_PS, m_bConstrainRootToWorld, 0x1d, 1)
GE_ASSERT_PROPERTY(eCVisualAnimation_PS, m_bInterBoneCollision, 0x1e, 1)
GE_ASSERT_PROPERTY(eCVisualAnimation_PS, m_bSkeletonCollisionEnabled, 0x1f, 1)
GE_ASSERT_PROPERTY(eCVisualAnimation_PS, m_bBoneRaycastsEnabled, 0x20, 1)
GE_ASSERT_PROPERTY(eCVisualAnimation_PS, m_bBonesAreBreakable, 0x21, 1)
GE_ASSERT_PROPERTY(eCVisualAnimation_PS, m_fBonesBreakMaxForce, 0x24, 4)
GE_ASSERT_PROPERTY(eCVisualAnimation_PS, m_fBonesBreakMaxTorque, 0x28, 4)
GE_ASSERT_PROPERTY(eCVisualAnimation_PS, m_fBoneLinearDamping, 0x2c, 4)
GE_ASSERT_PROPERTY(eCVisualAnimation_PS, m_fBoneAngularDamping, 0x30, 4)
GE_ASSERT_PROPERTY(eCVisualAnimation_PS, m_bBoneTwistSpringEnabled, 0x34, 1)
GE_ASSERT_PROPERTY(eCVisualAnimation_PS, m_fBoneTwistSpring, 0x38, 4)
GE_ASSERT_PROPERTY(eCVisualAnimation_PS, m_fBoneTwistSpringDamping, 0x3c, 4)
GE_ASSERT_PROPERTY(eCVisualAnimation_PS, m_bBoneSwingSpringEnabled, 0x40, 1)
GE_ASSERT_PROPERTY(eCVisualAnimation_PS, m_fBoneSwingSpring, 0x44, 4)
GE_ASSERT_PROPERTY(eCVisualAnimation_PS, m_fBoneSwingSpringDamping, 0x48, 4)
GE_ASSERT_PROPERTY(eCVisualAnimation_PS, m_bBoneJointSpringEnabled, 0x4c, 1)
GE_ASSERT_PROPERTY(eCVisualAnimation_PS, m_fBoneJointSpring, 0x50, 4)
GE_ASSERT_PROPERTY(eCVisualAnimation_PS, m_fBoneJointSpringDamping, 0x54, 4)
GE_ASSERT_PROPERTY(eCVisualAnimation_PS, m_fBoneProjectionDistance, 0x58, 4)
GE_ASSERT_PROPERTY(eCVisualAnimation_PS, m_enuBoneShapeGroup, 0x5c, 8)
GE_ASSERT_PROPERTY(eCVisualAnimation_PS, m_enuBoneShapeMaterial, 0x64, 8)
GE_ASSERT_PROPERTY(eCVisualAnimation_PS, m_enuSkeletonShapeGroup, 0x6c, 8)
GE_ASSERT_PROPERTY(eCVisualAnimation_PS, m_bSpringParentNodesOnly, 0x74, 1)
GE_ASSERT_PROPERTY(eCVisualAnimation_PS, m_fSpringParentNodeScale, 0x78, 4)
GE_ASSERT_PROPERTY(eCVisualAnimation_PS, m_bCreateSpringMassCloth, 0x7c, 1)
GE_ASSERT_PROPERTY(eCVisualAnimation_PS, m_bDisablePhysicLodding, 0x7d, 1)
GE_ASSERT_PROPERTY(eCVisualAnimation_PS, m_poClothEffector, 0x80, 16)
GE_ASSERT_PROPERTY(eCVisualAnimation_PS, m_iMaterialSwitch, 0x90, 4)
