#pragma once

#include <Engine/ge_triggerbase_ps.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCTriggerCombiner_PS : public eCTriggerBase_PS
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCTriggerCombiner_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsEditorRelevant() const override;
    protected: void OnTrigger(eCEntity *, eCEntity *) override;
    protected: void OnUntrigger(eCEntity *, eCEntity *) override;
    protected: void OnTouch(eCEntity *, eCContactIterator &) override;
    protected: void OnIntersect(eCEntity *, eCContactIterator &) override;
    protected: void OnUntouch(eCEntity *, eCContactIterator &) override;
    protected: void OnDamage(eCEntity *, eCEntity *, GEInt, GEInt, eCContactIterator &) override;
    protected: void GetBoundary(bCBox &, GEBool) override;
    protected: void OnProcess() override;
    public: bCString const & GetTriggerTarget(GEInt) const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(eCTriggerCombiner_PS, eCTriggerBase_PS)
    GE_PROPERTY(bCString, SlaveEntityName1, m_strSlaveEntityName1)
    GE_PROPERTY(bCString, SlaveEntityName2, m_strSlaveEntityName2)
    GE_PROPERTY(bCString, SlaveEntityName3, m_strSlaveEntityName3)
    GE_PROPERTY(bCString, SlaveEntityName4, m_strSlaveEntityName4)
    GE_PROPERTY(bCString, SlaveEntityName5, m_strSlaveEntityName5)
    GE_PROPERTY(bCString, SlaveEntityName6, m_strSlaveEntityName6)
    GE_PROPERTY(bCString, SlaveEntityName7, m_strSlaveEntityName7)
    GE_PROPERTY(bCString, SlaveEntityName8, m_strSlaveEntityName8)
    GE_PROPERTY(bCString, SlaveEntityName9, m_strSlaveEntityName9)
    GE_PROPERTY(bCString, SlaveEntityName10, m_strSlaveEntityName10)
    GE_PROPERTY(bCString, FailureTriggerTarget, m_strFailureTriggerTarget)
    GE_PROPERTY(GEBool, OrderIsRelevant, m_bOrderIsRelevant)
    GE_PROPERTY(GEBool, UntriggerCancels, m_bUntriggerCancels)
    GE_PROPERTY(GEBool, FirstFalseIsFailure, m_bFirstFalseIsFailure)
    GE_PADDING(1)

  protected:
    void FireTriggerFailure(eCEntity *);
    void FireTriggerSuccess(eCEntity *);
    GEInt GetSlaveNr(eCEntity *);
    void Invalidate();
    void Reset();

  private:
    GE_UNIMPL_MEMBERS(16)
};

GE_ASSERT_SIZEOF(eCTriggerCombiner_PS, 0x5c)

GE_ASSERT_PROPERTY(eCTriggerCombiner_PS, m_strSlaveEntityName1, 0x1c, 4)
GE_ASSERT_PROPERTY(eCTriggerCombiner_PS, m_strSlaveEntityName2, 0x20, 4)
GE_ASSERT_PROPERTY(eCTriggerCombiner_PS, m_strSlaveEntityName3, 0x24, 4)
GE_ASSERT_PROPERTY(eCTriggerCombiner_PS, m_strSlaveEntityName4, 0x28, 4)
GE_ASSERT_PROPERTY(eCTriggerCombiner_PS, m_strSlaveEntityName5, 0x2c, 4)
GE_ASSERT_PROPERTY(eCTriggerCombiner_PS, m_strSlaveEntityName6, 0x30, 4)
GE_ASSERT_PROPERTY(eCTriggerCombiner_PS, m_strSlaveEntityName7, 0x34, 4)
GE_ASSERT_PROPERTY(eCTriggerCombiner_PS, m_strSlaveEntityName8, 0x38, 4)
GE_ASSERT_PROPERTY(eCTriggerCombiner_PS, m_strSlaveEntityName9, 0x3c, 4)
GE_ASSERT_PROPERTY(eCTriggerCombiner_PS, m_strSlaveEntityName10, 0x40, 4)
GE_ASSERT_PROPERTY(eCTriggerCombiner_PS, m_strFailureTriggerTarget, 0x44, 4)
GE_ASSERT_PROPERTY(eCTriggerCombiner_PS, m_bOrderIsRelevant, 0x48, 1)
GE_ASSERT_PROPERTY(eCTriggerCombiner_PS, m_bUntriggerCancels, 0x49, 1)
GE_ASSERT_PROPERTY(eCTriggerCombiner_PS, m_bFirstFalseIsFailure, 0x4a, 1)
