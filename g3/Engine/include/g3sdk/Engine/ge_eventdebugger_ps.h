#pragma once

#include <Engine/ge_triggerbase_ps.h>

#include <SharedBase.h>

class GE_DLLIMPORT eCEventDebugger_PS : public eCTriggerBase_PS
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~eCEventDebugger_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: eEPropertySetType GetPropertySetType() const override;
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
    GE_PROPERTY_SET(eCEventDebugger_PS, eCTriggerBase_PS)
    GE_PROPERTY(GEBool, WatchTriggerEvents, m_bWatchTriggerEvents)
    GE_PROPERTY(GEBool, WatchUntriggerEvents, m_bWatchUntriggerEvents)
    GE_PROPERTY(GEBool, WatchTouchEvents, m_bWatchTouchEvents)
    GE_PROPERTY(GEBool, WatchUntouchEvents, m_bWatchUntouchEvents)
    GE_PROPERTY(GEBool, WatchIntersectEvents, m_bWatchIntersectEvents)
    GE_PROPERTY(GEBool, WatchDamageEvents, m_bWatchDamageEvents)
    GE_PADDING(1)

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(eCEventDebugger_PS, 0x24)

GE_ASSERT_PROPERTY(eCEventDebugger_PS, m_bWatchTriggerEvents, 0x1c, 1)
GE_ASSERT_PROPERTY(eCEventDebugger_PS, m_bWatchUntriggerEvents, 0x1d, 1)
GE_ASSERT_PROPERTY(eCEventDebugger_PS, m_bWatchTouchEvents, 0x1e, 1)
GE_ASSERT_PROPERTY(eCEventDebugger_PS, m_bWatchUntouchEvents, 0x1f, 1)
GE_ASSERT_PROPERTY(eCEventDebugger_PS, m_bWatchIntersectEvents, 0x20, 1)
GE_ASSERT_PROPERTY(eCEventDebugger_PS, m_bWatchDamageEvents, 0x21, 1)
