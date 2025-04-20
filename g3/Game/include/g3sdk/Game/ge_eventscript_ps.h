#pragma once

#include <Engine.h>

class GE_DLLIMPORT gCEventScript_PS : public eCTrigger_PS
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCEventScript_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: eEPropertySetType GetPropertySetType() const override;
    protected: void GetBoundary(bCBox &, GEBool) override;
    protected: void OnProcess() override;
    public: bCString const & GetTriggerTarget(GEInt) const override;
    protected: void TriggerTarget(eCEntity *, eCEntity *, eCContactIterator &) override;
    protected: void UntriggerTarget(eCEntity *, eCEntity *, eCContactIterator &) override;
    protected: GEBool CanBeActivatedNow(eCEntity *, eCContactIterator &) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCEventScript_PS, eCTrigger_PS)
    GE_PROPERTY(bCString, ScriptConditionFunc, m_strScriptConditionFunc)
    GE_PROPERTY(bCString, ScriptTriggerFunc, m_strScriptTriggerFunc)
    GE_PROPERTY(bCString, ScriptUntriggerFunc, m_strScriptUntriggerFunc)

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(gCEventScript_PS, 0xf0)

GE_ASSERT_PROPERTY(gCEventScript_PS, m_strScriptConditionFunc, 0xe4, 4)
GE_ASSERT_PROPERTY(gCEventScript_PS, m_strScriptTriggerFunc, 0xe8, 4)
GE_ASSERT_PROPERTY(gCEventScript_PS, m_strScriptUntriggerFunc, 0xec, 4)
