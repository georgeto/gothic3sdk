#pragma once

#include <Engine/EngineEnum.h>
#include <Engine/ge_trigger_ps.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCTriggerList_PS : public eCTrigger_PS
{
    // clang-format off
    protected: virtual void TriggerActTarget(eCEntity *);
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCTriggerList_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: eEPropertySetType GetPropertySetType() const override;
    protected: GEBool IsProcessable() const override;
    protected: void GetBoundary(bCBox &, GEBool) override;
    protected: void OnProcess() override;
    public: bCString const & GetTriggerTarget(GEInt) const override;
    protected: void OnTimer() override;
    protected: void TriggerTarget(eCEntity *, eCEntity *, eCContactIterator &) override;
    protected: void UntriggerTarget(eCEntity *, eCEntity *, eCContactIterator &) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCTriggerList_PS, eCTrigger_PS)
    GE_PROPERTY(bCString, TriggerTarget1, m_strTriggerTarget1)
    GE_PROPERTY(bCString, TriggerTarget2, m_strTriggerTarget2)
    GE_PROPERTY(bCString, TriggerTarget3, m_strTriggerTarget3)
    GE_PROPERTY(bCString, TriggerTarget4, m_strTriggerTarget4)
    GE_PROPERTY(bCString, TriggerTarget5, m_strTriggerTarget5)
    GE_PROPERTY(bCString, TriggerTarget6, m_strTriggerTarget6)
    GE_PROPERTY(bCString, TriggerTarget7, m_strTriggerTarget7)
    GE_PROPERTY(bCString, TriggerTarget8, m_strTriggerTarget8)
    GE_PROPERTY(bCString, TriggerTarget9, m_strTriggerTarget9)
    GE_PROPERTY(bCString, TriggerTarget10, m_strTriggerTarget10)
    GE_PROPERTY(GEFloat, FireDelayTarget1, m_fFireDelayTarget1)
    GE_PROPERTY(GEFloat, FireDelayTarget2, m_fFireDelayTarget2)
    GE_PROPERTY(GEFloat, FireDelayTarget3, m_fFireDelayTarget3)
    GE_PROPERTY(GEFloat, FireDelayTarget4, m_fFireDelayTarget4)
    GE_PROPERTY(GEFloat, FireDelayTarget5, m_fFireDelayTarget5)
    GE_PROPERTY(GEFloat, FireDelayTarget6, m_fFireDelayTarget6)
    GE_PROPERTY(GEFloat, FireDelayTarget7, m_fFireDelayTarget7)
    GE_PROPERTY(GEFloat, FireDelayTarget8, m_fFireDelayTarget8)
    GE_PROPERTY(GEFloat, FireDelayTarget9, m_fFireDelayTarget9)
    GE_PROPERTY(GEFloat, FireDelayTarget10, m_fFireDelayTarget10)
    GE_ENUMPROP(eETriggerListProcessType, ProcessType, m_enuProcessType)

  protected:
    void DoTriggering(eCEntity *);
    void FinishActivation();
    void Invalidate();
    GEBool ProcessActTarget(eCEntity *);

  private:
    GE_UNIMPL_MEMBERS(8)
};

GE_ASSERT_SIZEOF(eCTriggerList_PS, 0x144)

GE_ASSERT_PROPERTY(eCTriggerList_PS, m_strTriggerTarget1, 0xe4, 4)
GE_ASSERT_PROPERTY(eCTriggerList_PS, m_strTriggerTarget2, 0xe8, 4)
GE_ASSERT_PROPERTY(eCTriggerList_PS, m_strTriggerTarget3, 0xec, 4)
GE_ASSERT_PROPERTY(eCTriggerList_PS, m_strTriggerTarget4, 0xf0, 4)
GE_ASSERT_PROPERTY(eCTriggerList_PS, m_strTriggerTarget5, 0xf4, 4)
GE_ASSERT_PROPERTY(eCTriggerList_PS, m_strTriggerTarget6, 0xf8, 4)
GE_ASSERT_PROPERTY(eCTriggerList_PS, m_strTriggerTarget7, 0xfc, 4)
GE_ASSERT_PROPERTY(eCTriggerList_PS, m_strTriggerTarget8, 0x100, 4)
GE_ASSERT_PROPERTY(eCTriggerList_PS, m_strTriggerTarget9, 0x104, 4)
GE_ASSERT_PROPERTY(eCTriggerList_PS, m_strTriggerTarget10, 0x108, 4)
GE_ASSERT_PROPERTY(eCTriggerList_PS, m_fFireDelayTarget1, 0x10c, 4)
GE_ASSERT_PROPERTY(eCTriggerList_PS, m_fFireDelayTarget2, 0x110, 4)
GE_ASSERT_PROPERTY(eCTriggerList_PS, m_fFireDelayTarget3, 0x114, 4)
GE_ASSERT_PROPERTY(eCTriggerList_PS, m_fFireDelayTarget4, 0x118, 4)
GE_ASSERT_PROPERTY(eCTriggerList_PS, m_fFireDelayTarget5, 0x11c, 4)
GE_ASSERT_PROPERTY(eCTriggerList_PS, m_fFireDelayTarget6, 0x120, 4)
GE_ASSERT_PROPERTY(eCTriggerList_PS, m_fFireDelayTarget7, 0x124, 4)
GE_ASSERT_PROPERTY(eCTriggerList_PS, m_fFireDelayTarget8, 0x128, 4)
GE_ASSERT_PROPERTY(eCTriggerList_PS, m_fFireDelayTarget9, 0x12c, 4)
GE_ASSERT_PROPERTY(eCTriggerList_PS, m_fFireDelayTarget10, 0x130, 4)
GE_ASSERT_PROPERTY(eCTriggerList_PS, m_enuProcessType, 0x134, 8)
