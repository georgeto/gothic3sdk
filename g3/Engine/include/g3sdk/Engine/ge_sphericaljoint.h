#pragma once

#include <Engine/ge_joint.h>
#include <Engine/ge_jointdesc.h>
#include <Engine/ge_sphericaljointdesc.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCSphericalJoint : public eCJoint
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    protected: ~eCSphericalJoint() override;
    public: bEResult PostInitializeProperties() override;
    public: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    public: eEJointType GetType() const override;
    public: void SetDescriptor(eCJointDesc &, GEBool) override;
    protected: NxJointDesc & GetDescriptorInternal() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCSphericalJoint, eCJoint)
    GE_OBJECTPROP(eCSphericalJointDesc, eCJointDesc, SphericalJointDesc, m_poSphericalJointDesc)

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(204)
};

GE_ASSERT_SIZEOF(eCSphericalJoint, 0x124)

GE_ASSERT_PROPERTY(eCSphericalJoint, m_poSphericalJointDesc, 0x48, 16)
