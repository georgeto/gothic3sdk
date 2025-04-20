#pragma once

#include <Engine/ge_propertylogic.h>
#include <Engine/ge_trigger_ps.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCEventLogic_PS : public eCTrigger_PS
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCEventLogic_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: eEPropertySetType GetPropertySetType() const override;
    protected: void GetBoundary(bCBox &, GEBool) override;
    protected: void OnProcess() override;
    public: bCString const & GetTriggerTarget(GEInt) const override;
    protected: void TriggerTarget(eCEntity *, eCEntity *, eCContactIterator &) override;
    protected: void UntriggerTarget(eCEntity *, eCEntity *, eCContactIterator &) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCEventLogic_PS, eCTrigger_PS)
    GE_PROPERTY(GEBool, ReverseLogicOnUntrigger, m_bReverseLogicOnUntrigger)
    GE_PADDING(3)
    GE_PROPERTY(bTObjArray<bTAutoPOSmartPtr<eCPropertyLogic>>, PropertyLogic, m_arrPropertyLogic)

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(eCEventLogic_PS, 0xf4)

GE_ASSERT_PROPERTY(eCEventLogic_PS, m_bReverseLogicOnUntrigger, 0xe4, 1)
GE_ASSERT_PROPERTY(eCEventLogic_PS, m_arrPropertyLogic, 0xe8, 12)
