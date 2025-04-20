#pragma once

#include <Game/GameEnum.h>

#include <Engine.h>

class GE_DLLIMPORT gCInteraction_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCInteraction_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: GEBool OnNotifyPropertyValueChangedExitEx(GELPCChar, GEBool) override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsReferencedByTemplate() const override;
    public: GEBool IsVisual() const override;
    public: bEResult ReadSaveGame(bCIStream &) override;
    public: bEResult WriteSaveGame(bCOStream &) override;
    public: eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance() const override;
    public: void GetDependencies(bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> &) override;
    protected: void OnEnterProcessingRange() override;
    protected: void OnExitProcessingRange() override;
    public: void OnRender(GEI16) override;
    public: void OnPropertySetAdded() override;
    public: void OnPropertySetRemoved() override;
    public: void OnCustomPatch(eCEntityPropertySet const *) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCInteraction_PS, eCEntityPropertySet)
    GE_ENUMPROP(gEFocusPriority, FocusPriority, m_enuFocusPri)
    GE_PROPERTY(eCEntityProxy, Owner, m_Owner) // Read only
    GE_PROPERTY(eCEntityProxy, User, m_User)   // Read only
    GE_ENUMPROP(gEUseType, UseType, m_enuUseType)
    GE_PROPERTY(bCString, ScriptUseFunc, m_strScriptUseFunc)
    GE_PROPERTY(eCEntityProxy, AnchorPoint, m_AnchorPoint) // Read only
    GE_ENUMPROP(gEFocusNameType, FocusNameType, m_enuFocusNameType)
    GE_PROPERTY(bCString, FocusNameBone, m_strFocusNameBone)
    GE_PROPERTY(bCVector, FocusViewOffset, m_vecFocusViewOffset)
    GE_PROPERTY(bCVector, FocusWorldOffset, m_vecFocusWorldOffset)
    GE_PROPERTY(GEBool, UsedByPlayer, m_bUsedByPlayer) // Read only
    GE_PADDING(3)
    GE_PROPERTY(bCString, EnterROIScript, m_strEnterROIScript)
    GE_PROPERTY(bCString, ExitROIScript, m_strExitROIScript)
    GE_PROPERTY(eCTemplateEntityProxy, Spell, m_entSpell)

  public:
    bCString &AccessUseFunc();
    eCPropertySetProxy &GetAccessToZoneProxy();
    bCString const &GetUseFunc() const;
    eCEntity const *GetZoneEntity();
    eCPropertySetProxy const &GetZoneProxy() const;
    GEBool IsZoneProxyValid() const;
    void SetUseFunc(bCString const &);

  protected:
    void Invalidate();

  private:
    eCPropertySetProxy m_NavZone;
    GEBool m_bZoneProxyValid;
    GE_PADDING(3)
};

GE_ASSERT_SIZEOF(gCInteraction_PS, 0xe0)

GE_ASSERT_PROPERTY(gCInteraction_PS, m_enuFocusPri, 0x14, 8)
GE_ASSERT_PROPERTY(gCInteraction_PS, m_Owner, 0x1c, 28)
GE_ASSERT_PROPERTY(gCInteraction_PS, m_User, 0x38, 28)
GE_ASSERT_PROPERTY(gCInteraction_PS, m_enuUseType, 0x54, 8)
GE_ASSERT_PROPERTY(gCInteraction_PS, m_strScriptUseFunc, 0x5c, 4)
GE_ASSERT_PROPERTY(gCInteraction_PS, m_AnchorPoint, 0x60, 28)
GE_ASSERT_PROPERTY(gCInteraction_PS, m_enuFocusNameType, 0x7c, 8)
GE_ASSERT_PROPERTY(gCInteraction_PS, m_strFocusNameBone, 0x84, 4)
GE_ASSERT_PROPERTY(gCInteraction_PS, m_vecFocusViewOffset, 0x88, 12)
GE_ASSERT_PROPERTY(gCInteraction_PS, m_vecFocusWorldOffset, 0x94, 12)
GE_ASSERT_PROPERTY(gCInteraction_PS, m_bUsedByPlayer, 0xa0, 1)
GE_ASSERT_PROPERTY(gCInteraction_PS, m_strEnterROIScript, 0xa4, 4)
GE_ASSERT_PROPERTY(gCInteraction_PS, m_strExitROIScript, 0xa8, 4)
GE_ASSERT_PROPERTY(gCInteraction_PS, m_entSpell, 0xac, 12)
