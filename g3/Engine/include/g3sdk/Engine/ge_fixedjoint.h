#pragma once

#include <Engine/ge_fixedjointdesc.h>
#include <Engine/ge_joint.h>
#include <Engine/ge_jointdesc.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCFixedJoint : public eCJoint
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    protected: ~eCFixedJoint() override;
    public: bEResult PostInitializeProperties() override;
    public: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    public: eEJointType GetType() const override;
    public: void SetDescriptor(eCJointDesc &, GEBool) override;
    protected: NxJointDesc & GetDescriptorInternal() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCFixedJoint, eCJoint)
    GE_OBJECTPROP(eCFixedJointDesc, eCJointDesc, FixedJointDesc, m_poFixedJointDesc)

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(108)
};

GE_ASSERT_SIZEOF(eCFixedJoint, 0xc4)

GE_ASSERT_PROPERTY(eCFixedJoint, m_poFixedJointDesc, 0x48, 16)
