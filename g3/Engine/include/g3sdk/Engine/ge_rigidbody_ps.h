#pragma once

#include <Engine/EngineEnum.h>
#include <Engine/ge_rigidbodybase_ps.h>

#include <SharedBase.h>

class NxActor;

class GE_DLLIMPORT eCRigidBody_PS : public eCRigidBodyBase_PS
{
    // clang-format off
    public: virtual bCVector GetPivotVelocity() const;
    public: virtual bCVector GetPointVelocity(bCVector const &) const;
    public: virtual bCVector GetLocalPointVelocity(bCVector const &) const;
    public: virtual void AddBodyFlag(eERigidbody_Flag);
    public: virtual void RemoveBodyFlag(eERigidbody_Flag);
    public: virtual GEBool ContainsBodyFlag(eERigidbody_Flag) const;
    public: virtual void EnableMovementControlByAI(GEBool, GEBool, GEBool);
    public: virtual GEBool IsMovementControledByAI() const;
    public: virtual GEBool UpdateEntityIfControlledByAI() const;
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: ~eCRigidBody_PS() override;
    public: bEResult PostInitializeProperties() override;
    protected: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    public: GEBool IsPhysicRelevant() const override;
    public: GEBool IsEditorRelevant() const override;
    public: void SetEntity(eCEntity *) override;
    protected: void OnEnterProcessingRange() override;
    protected: void OnExitProcessingRange() override;
    protected: void OnUpdatedWorldMatrix() override;
    public: void GetBoundary(bCBox &, GEBool) override;
    protected: void OnPostRead() override;
    protected: void OnPropertySetAdded() override;
    public: void StopMotion() override;
    public: void StopRotation() override;
    public: void StopMovement() override;
    public: void SetPosition(bCVector const &) override;
    public: void SetPose(bCMatrix const &) override;
    public: void SetRotation(bCMatrix3 const &) override;
    public: void SetRotation(bCQuaternion const &) override;
    public: void SetLinearVelocity(bCVector const &) override;
    public: void SetAngularVelocity(bCVector const &) override;
    public: void SetLinearMomentum(bCVector const &) override;
    public: void SetAngularMomentum(bCVector const &) override;
    public: bCVector GetPosition() const override;
    public: bCMatrix GetPose() const override;
    public: bCMatrix3 GetRotation() const override;
    public: bCQuaternion GetRotationQuat() const override;
    public: bCVector GetLinearVelocity() const override;
    public: bCVector GetAngularVelocity() const override;
    public: bCVector GetLinearMomentum() const override;
    public: bCVector GetAngularMomentum() const override;
    public: void SetMass(GEFloat const &) override;
    public: GEFloat GetMass() const override;
    public: void SetCenterOfGravity(bCVector const &) override;
    public: bCVector GetCenterOfGravity() const override;
    public: void SetMassSpaceInertiaTensor(bCVector const &) override;
    public: bCVector GetMassSpaceInertiaTensor() const override;
    public: void AddForce(bCVector const &, eEForceMode) override;
    public: void AddTorque(bCVector const &, eEForceMode) override;
    public: void AddRelForce(bCVector const &, eEForceMode) override;
    public: void AddRelTorque(bCVector const &, eEForceMode) override;
    public: void AddForceAtPos(bCVector const &, bCVector const &, eEForceMode) override;
    public: void AddForceAtRelPos(bCVector const &, bCVector const &, eEForceMode) override;
    public: void AddRelForceAtPos(bCVector const &, bCVector const &, eEForceMode) override;
    public: void AddRelForceAtRelPos(bCVector const &, bCVector const &, eEForceMode) override;
    public: void SetGravityEnabled(GEBool) override;
    public: GEBool GetGravityEnabled() const override;
    public: void SetIsSleeping(GEBool) override;
    public: GEBool GetIsSleeping() const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCRigidBody_PS, eCRigidBodyBase_PS)
    GE_PROPERTY(GEFloat, TotalMass, m_fMass)
    GE_PROPERTY(bCVector, StartVelocity, m_vecLinearVelocityStart)
    GE_PROPERTY(bCVector, StartAngularVelocity, m_vecAngularVelocityStart)
    GE_PROPERTY(bCVector, StartForce, m_vecInitialForce)
    GE_PROPERTY(bCVector, StartTorque, m_vecInitialTorque)
    GE_PROPERTY(GEFloat, WakeUpCounter, m_fWakeUpCounter)
    GE_PROPERTY(GEFloat, LinearDamping, m_fLinearDamping)
    GE_PROPERTY(GEFloat, AngularDamping, m_fAngularDamping)
    GE_PROPERTY(GEFloat, MaxAngularVelocity, m_fMaxAngularVelocity)
    GE_PROPERTY(bCVector, MassSpaceInertia, m_vecMassSpaceInertia)
    GE_PROPERTY(bCVector, CenterOfMass, m_vecCenterOfMass)
    GE_PROPERTY(GEFloat, CCDMotionTreshold, m_fCCDMotionTreshold)
    GE_ENUMPROP(eERigidbody_Flag, BodyFlag, m_enuBodyFlag)

  public:
    GEFloat GetLocalTimeScale() const;
    void SetFixedStepTranslation(bCVector const &);
    void SetFixedYStep(GEFloat);
    void SetLocalTimeScale(GEFloat);
    void SetMoverGoal(bCVector const &, GEFloat);

  protected:
    GEBool GetIsSleepingToggled() const;
    GEBool GetMoverGoalReached() const;
    bCQuaternion GetStepRotation(GEFloat);
    bCVector GetStepTranslation(GEFloat);
    void Invalidate();
    void ProcessMovement();
    void SaveStep();
    void SetActor(NxActor *);
    void SetIsSleepingToggled(GEBool);

  private:
    GE_UNIMPL_MEMBERS(120)
};

GE_ASSERT_SIZEOF(eCRigidBody_PS, 0xf8)

GE_ASSERT_PROPERTY(eCRigidBody_PS, m_fMass, 0x18, 4)
GE_ASSERT_PROPERTY(eCRigidBody_PS, m_vecLinearVelocityStart, 0x1c, 12)
GE_ASSERT_PROPERTY(eCRigidBody_PS, m_vecAngularVelocityStart, 0x28, 12)
GE_ASSERT_PROPERTY(eCRigidBody_PS, m_vecInitialForce, 0x34, 12)
GE_ASSERT_PROPERTY(eCRigidBody_PS, m_vecInitialTorque, 0x40, 12)
GE_ASSERT_PROPERTY(eCRigidBody_PS, m_fWakeUpCounter, 0x4c, 4)
GE_ASSERT_PROPERTY(eCRigidBody_PS, m_fLinearDamping, 0x50, 4)
GE_ASSERT_PROPERTY(eCRigidBody_PS, m_fAngularDamping, 0x54, 4)
GE_ASSERT_PROPERTY(eCRigidBody_PS, m_fMaxAngularVelocity, 0x58, 4)
GE_ASSERT_PROPERTY(eCRigidBody_PS, m_vecMassSpaceInertia, 0x5c, 12)
GE_ASSERT_PROPERTY(eCRigidBody_PS, m_vecCenterOfMass, 0x68, 12)
GE_ASSERT_PROPERTY(eCRigidBody_PS, m_fCCDMotionTreshold, 0x74, 4)
GE_ASSERT_PROPERTY(eCRigidBody_PS, m_enuBodyFlag, 0x78, 8)
