#pragma once

#include <Game/GameEnum.h>
#include <Game/ge_touchdamage_ps.h>

#include <Engine.h>

class GE_DLLIMPORT gCMover_PS : public gCTouchDamage_PS
{
    // clang-format off
    public: virtual void Open(GEBool);
    public: virtual void Close(GEBool);
    public: virtual void SetIsOpen(GEBool);
    public: virtual void Stop();
    public: virtual void Toggle();
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCMover_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsProcessable() const override;
    public: eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance() const override;
    public: void OnCacheIn() override;
    public: void OnCacheOut() override;
    public: void OnProcess() override;
    public: void OnPostRead() override;
    protected: void TriggerTarget(eCEntity *, eCEntity *, eCContactIterator &) override;
    protected: void UntriggerTarget(eCEntity *, eCEntity *, eCContactIterator &) override;
    protected: GEBool CanBeActivatedNow(eCEntity *, eCContactIterator &) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCMover_PS, gCTouchDamage_PS)
    GE_ENUMPROP(gEMoverState, MoverState, m_enuMoverState)
    GE_ENUMPROP(gEMoverBehavior, MoverBehavior, m_enuMoverBehavior)
    GE_ENUMPROP(gEMoverTouchBehavior, MoverTouchBehavior, m_enuMoverTouchBehavior)
    GE_PROPERTY(bCAnimationResourceString, OpenAni, m_strOpenAni)
    GE_PROPERTY(bCAnimationResourceString, CloseAni, m_strCloseAni)
    GE_PROPERTY(GEBool, LoopAni, m_bLoopAni)
    GE_PROPERTY(GEBool, IgnoreOpenTouches, m_bIgnoreOpenTouches)
    GE_PROPERTY(GEBool, ForceAlwaysVisible, m_bForceAlwaysVisible)
    GE_PADDING(1)

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(4)
};

GE_ASSERT_SIZEOF(gCMover_PS, 0x114)

GE_ASSERT_PROPERTY(gCMover_PS, m_enuMoverState, 0xec, 8)
GE_ASSERT_PROPERTY(gCMover_PS, m_enuMoverBehavior, 0xf4, 8)
GE_ASSERT_PROPERTY(gCMover_PS, m_enuMoverTouchBehavior, 0xfc, 8)
GE_ASSERT_PROPERTY(gCMover_PS, m_strOpenAni, 0x104, 4)
GE_ASSERT_PROPERTY(gCMover_PS, m_strCloseAni, 0x108, 4)
GE_ASSERT_PROPERTY(gCMover_PS, m_bLoopAni, 0x10c, 1)
GE_ASSERT_PROPERTY(gCMover_PS, m_bIgnoreOpenTouches, 0x10d, 1)
GE_ASSERT_PROPERTY(gCMover_PS, m_bForceAlwaysVisible, 0x10e, 1)
