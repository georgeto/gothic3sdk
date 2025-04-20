#pragma once

#include <Engine/EngineEnum.h>
#include <Engine/entity/ge_entitypropertyset.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCRigidBodyBase_PS : public eCEntityPropertySet
{
    // clang-format off
    public: virtual void StopMotion();
    public: virtual void StopRotation();
    public: virtual void StopMovement();
    public: virtual void SetPosition(bCVector const &);
    public: virtual void SetPose(bCMatrix const &);
    public: virtual void SetRotation(bCMatrix3 const &);
    public: virtual void SetRotation(bCQuaternion const &);
    public: virtual void SetLinearVelocity(bCVector const &);
    public: virtual void SetAngularVelocity(bCVector const &);
    public: virtual void SetLinearMomentum(bCVector const &);
    public: virtual void SetAngularMomentum(bCVector const &);
    public: virtual bCVector GetPosition() const;
    public: virtual bCMatrix GetPose() const;
    public: virtual bCMatrix3 GetRotation() const;
    public: virtual bCQuaternion GetRotationQuat() const;
    public: virtual bCVector GetLinearVelocity() const;
    public: virtual bCVector GetAngularVelocity() const;
    public: virtual bCVector GetLinearMomentum() const;
    public: virtual bCVector GetAngularMomentum() const;
    public: virtual void SetMass(GEFloat const &);
    public: virtual GEFloat GetMass() const;
    public: virtual void SetCenterOfGravity(bCVector const &);
    public: virtual bCVector GetCenterOfGravity() const;
    public: virtual void SetMassSpaceInertiaTensor(bCVector const &);
    public: virtual bCVector GetMassSpaceInertiaTensor() const;
    public: virtual void AddForce(bCVector const &, eEForceMode);
    public: virtual void AddTorque(bCVector const &, eEForceMode);
    public: virtual void AddRelForce(bCVector const &, eEForceMode);
    public: virtual void AddRelTorque(bCVector const &, eEForceMode);
    public: virtual void AddForceAtPos(bCVector const &, bCVector const &, eEForceMode);
    public: virtual void AddForceAtRelPos(bCVector const &, bCVector const &, eEForceMode);
    public: virtual void AddRelForceAtPos(bCVector const &, bCVector const &, eEForceMode);
    public: virtual void AddRelForceAtRelPos(bCVector const &, bCVector const &, eEForceMode);
    public: virtual void SetGravityEnabled(GEBool);
    public: virtual GEBool GetGravityEnabled() const;
    public: virtual void SetIsSleeping(GEBool);
    public: virtual GEBool GetIsSleeping() const;
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCRigidBodyBase_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsEditorRelevant() const override;
    protected: void OnProcess() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCRigidBodyBase_PS, eCEntityPropertySet)
    GE_PROPERTY(GEBool, PhysicsEnabled, m_bPhysicsEnabled)
    GE_PADDING(1)

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(eCRigidBodyBase_PS, 0x18)

GE_ASSERT_PROPERTY(eCRigidBodyBase_PS, m_bPhysicsEnabled, 0x14, 1)
