#pragma once

#include <Game/GameEnum.h>
#include <Game/ge_eventscript_ps.h>

#include <Engine.h>

class GE_DLLIMPORT gCDistanceTrigger_PS : public gCEventScript_PS
{
    // clang-format off
    protected: virtual void TriggerDistance(GEFloat, eCEntity *, eCContactIterator &);
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCDistanceTrigger_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    public: eEPropertySetType GetPropertySetType() const override;
    protected: GEBool IsProcessable() const override;
    public: GEBool IsEditorRelevant() const override;
    protected: void OnEnterProcessingRange() override;
    protected: void OnCacheIn() override;
    protected: void OnProcess() override;
    protected: void OnPostRead() override;
    protected: void TriggerTarget(eCEntity *, eCEntity *, eCContactIterator &) override;
    protected: void UntriggerTarget(eCEntity *, eCEntity *, eCContactIterator &) override;
    protected: GEBool CanBeActivatedNow(eCEntity *, eCContactIterator &) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCDistanceTrigger_PS, gCEventScript_PS)
    GE_ENUMPROP(gEMaxDistType, MaxDistType, m_enuMaxDistType)
    GE_PROPERTY(GEFloat, MinDistance, m_fMinDistance)
    GE_PROPERTY(GEFloat, MaxDistance, m_fMaxDistance)

  protected:
    GEFloat CalcMaxDistance() const;
    void CreateShape();
    void Invalidate();
};

GE_ASSERT_SIZEOF(gCDistanceTrigger_PS, 0x100)

GE_ASSERT_PROPERTY(gCDistanceTrigger_PS, m_enuMaxDistType, 0xf0, 8)
GE_ASSERT_PROPERTY(gCDistanceTrigger_PS, m_fMinDistance, 0xf8, 4)
GE_ASSERT_PROPERTY(gCDistanceTrigger_PS, m_fMaxDistance, 0xfc, 4)
