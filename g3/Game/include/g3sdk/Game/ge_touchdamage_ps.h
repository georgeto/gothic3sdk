#pragma once

#include <Engine.h>

class GE_DLLIMPORT gCTouchDamage_PS : public eCTrigger_PS
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCTouchDamage_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance() const override;
    protected: void OnUntouch(eCEntity *, eCContactIterator &) override;
    protected: void TriggerTarget(eCEntity *, eCEntity *, eCContactIterator &) override;
    protected: GEBool CanBeActivatedNow(eCEntity *, eCContactIterator &) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCTouchDamage_PS, eCTrigger_PS)
    GE_PROPERTY(bCString, ScriptTouchFunc, m_strScriptTouchFunc)
    GE_PROPERTY(GEBool, ResetOnUntouch, m_bResetOnUntouch)
    GE_PROPERTY(GEBool, DamageDisabled, m_bDamageDisabled)
    GE_PADDING(1)

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(gCTouchDamage_PS, 0xec)

GE_ASSERT_PROPERTY(gCTouchDamage_PS, m_strScriptTouchFunc, 0xe4, 4)
GE_ASSERT_PROPERTY(gCTouchDamage_PS, m_bResetOnUntouch, 0xe8, 1)
GE_ASSERT_PROPERTY(gCTouchDamage_PS, m_bDamageDisabled, 0xe9, 1)
