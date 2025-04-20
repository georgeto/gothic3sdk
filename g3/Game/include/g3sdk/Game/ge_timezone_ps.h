#pragma once

#include <Game/ge_distancetrigger_ps.h>

#include <Engine.h>

class GE_DLLIMPORT gCTimeZone_PS : public gCDistanceTrigger_PS
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCTimeZone_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsEditorRelevant() const override;
    protected: void Decay() override;
    protected: void OnProcess() override;
    protected: void TriggerTarget(eCEntity *, eCEntity *, eCContactIterator &) override;
    protected: void UntriggerTarget(eCEntity *, eCEntity *, eCContactIterator &) override;
    protected: GEBool CanBeActivatedNow(eCEntity *, eCContactIterator &) override;
    protected: void TriggerDistance(GEFloat, eCEntity *, eCContactIterator &) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCTimeZone_PS, gCDistanceTrigger_PS)
    GE_PROPERTY(GEFloat, TimeScale, m_fTimeScale)

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(32)
};

GE_ASSERT_SIZEOF(gCTimeZone_PS, 0x124)

GE_ASSERT_PROPERTY(gCTimeZone_PS, m_fTimeScale, 0x100, 4)
