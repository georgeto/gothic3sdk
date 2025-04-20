#pragma once

#include <Engine/EngineEnum.h>

#include <SharedBase.h>

class eCEntity;

enum eEJointType
{
    // TODO: Enumerator values
};

class GE_DLLIMPORT eCJointDesc : public bCObjectRefBase
{
    // clang-format off
    public: virtual void SetToDefault();
    public: GEBool IsValid() const override;
    public: ~eCJointDesc() override;
    public: bEResult PostInitializeProperties() override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCJointDesc, bCObjectRefBase)
    GE_ENUMPROP(eEJointFlag, Flag, m_eFlag)
    GE_PROPERTY(GEFloat, MaxForce, m_fMaxForce)
    GE_PROPERTY(GEFloat, MaxTorque, m_fMaxTorque)

  public:
    eEJointType GetType() const;
    void SetGlobalAnchor(eCEntity *, eCEntity *, bCVector const &);
    void SetGlobalAxis(eCEntity *, eCEntity *, bCVector const &);

  protected:
    explicit eCJointDesc(eEJointType);

  private:
    GE_UNIMPL_MEMBERS(76)
};

GE_ASSERT_SIZEOF(eCJointDesc, 0x68)

GE_ASSERT_PROPERTY(eCJointDesc, m_eFlag, 0xc, 8)
GE_ASSERT_PROPERTY(eCJointDesc, m_fMaxForce, 0x14, 4)
GE_ASSERT_PROPERTY(eCJointDesc, m_fMaxTorque, 0x18, 4)
