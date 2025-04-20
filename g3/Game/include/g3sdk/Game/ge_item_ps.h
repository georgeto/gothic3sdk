#pragma once

#include <Game/GameEnum.h>

#include <Engine.h>

class gCInventory_PS;

class GE_DLLIMPORT gCItem_PS : public eCEntityPropertySet
{
  public:
    struct SScriptLine
    {
        bCString Command;
        bCString Entity1;
        bCString Entity2;
        bCString ID1;
        bCString ID2;
    };

    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCItem_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsReferencedByTemplate() const override;
    public: eCEntityPropertySet::eEPSSaveGameRelevance GetSaveGameRelevance() const override;
    public: void GetDependencies(bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> &) override;
    protected: void OnTouch(eCEntity *, eCContactIterator &) override;
    protected: void OnPostRead() override;
    public: void OnCustomPatch(eCEntityPropertySet const *) override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCItem_PS, eCEntityPropertySet)
    GE_PROPERTY(GEU32, Amount, m_u32Amount)
    GE_PROPERTY(GEU32, Quality, m_u32Quality)
    GE_PROPERTY(GEI32, GoldValue, m_iGoldValue)
    GE_PROPERTY(GEBool, MissionItem, m_bMissionItem)
    GE_PROPERTY(GEBool, Permanent, m_bPermanent)
    GE_PADDING(2)
    GE_ENUMPROP(gEItemCategory, Category, m_enuCategory)
    GE_PROPERTY(bCString, Texture, m_strTexture)
    GE_PROPERTY(GEBool, Dropped, m_bDropped)
    GE_PADDING(3)
    GE_PROPERTY(eCTemplateEntityProxy, ItemWorld, m_itemWorld)
    GE_PROPERTY(eCTemplateEntityProxy, ItemInventory, m_itemInventory)
    GE_PROPERTY(eCTemplateEntityProxy, ArmorSet, m_entArmorSet)
    GE_PROPERTY(eCTemplateEntityProxy, Spell, m_entSpell)
    GE_PROPERTY(eCTemplateEntityProxy, Skill, m_entSkill)
    GE_PROPERTY(GEBool, Robe, m_bRobe)
    GE_PROPERTY(GEBool, FullBody, m_bFullBody)
    GE_PADDING(2)
    GE_PROPERTY(bCString, ReqAttrib1Tag, m_strReqAttrib1)
    GE_ENUMPROP(EAttribReqOperation, ReqAttrib1Op, m_enuReqAttrib1)
    GE_PROPERTY(GEInt, ReqAttrib1Value, m_iReqAttrib1)
    GE_PROPERTY(bCString, ReqAttrib2Tag, m_strReqAttrib2)
    // NOTE: Incorrectly named "ReqAttrib1Op" in property meta data.
    GE_ENUMPROP(EAttribReqOperation, ReqAttrib2Op, m_enuReqAttrib2)
    GE_PROPERTY(GEInt, ReqAttrib2Value, m_iReqAttrib2)
    GE_PROPERTY(bCString, ReqAttrib3Tag, m_strReqAttrib3)
    // NOTE: Incorrectly named "ReqAttrib1Op" in property meta data.
    GE_ENUMPROP(EAttribReqOperation, ReqAttrib3Op, m_enuReqAttrib3)
    GE_PROPERTY(GEInt, ReqAttrib3Value, m_iReqAttrib3)
    GE_PROPERTY(bCString, ReqAttrib4Tag, m_strReqAttrib4)
    // NOTE: Incorrectly named "ReqAttrib1Op" in property meta data.
    GE_ENUMPROP(EAttribReqOperation, ReqAttrib4Op, m_enuReqAttrib4)
    GE_PROPERTY(GEInt, ReqAttrib4Value, m_iReqAttrib4)
    GE_PROPERTY(eCTemplateEntityProxy, RequiredSkill1, m_entRequiredSkill1)
    GE_PROPERTY(eCTemplateEntityProxy, RequiredSkill2, m_entRequiredSkill2)
    GE_PROPERTY(bCString, ModAttrib1Tag, m_strModAttrib1)
    GE_ENUMPROP(EAttribModOperation, ModAttrib1Op, m_enuModAttrib1)
    GE_PROPERTY(GEInt, ModAttrib1Value, m_iModAttrib1)
    GE_PROPERTY(bCString, ModAttrib2Tag, m_strModAttrib2)
    GE_ENUMPROP(EAttribModOperation, ModAttrib2Op, m_enuModAttrib2)
    GE_PROPERTY(GEInt, ModAttrib2Value, m_iModAttrib2)
    GE_PROPERTY(bCString, ModAttrib3Tag, m_strModAttrib3)
    GE_ENUMPROP(EAttribModOperation, ModAttrib3Op, m_enuModAttrib3)
    GE_PROPERTY(GEInt, ModAttrib3Value, m_iModAttrib3)
    GE_PROPERTY(bCString, ModAttrib4Tag, m_strModAttrib4)
    GE_ENUMPROP(EAttribModOperation, ModAttrib4Op, m_enuModAttrib4)
    GE_PROPERTY(GEInt, ModAttrib4Value, m_iModAttrib4)
    GE_PROPERTY(bCString, ModAttrib5Tag, m_strModAttrib5)
    GE_ENUMPROP(EAttribModOperation, ModAttrib5Op, m_enuModAttrib5)
    GE_PROPERTY(GEInt, ModAttrib5Value, m_iModAttrib5)
    GE_PROPERTY(bCString, ModAttrib6Tag, m_strModAttrib6)
    GE_ENUMPROP(EAttribModOperation, ModAttrib6Op, m_enuModAttrib6)
    GE_PROPERTY(GEInt, ModAttrib6Value, m_iModAttrib6)
    GE_PROPERTY(eCTemplateEntityProxy, ActivateSkill1, m_entActivateSkill1)
    GE_PROPERTY(eCTemplateEntityProxy, ActivateSkill2, m_entActivateSkill2)

  public:
    GEInt Compare(gCItem_PS const &, gCInventory_PS const &) const;
    GEBool ExecuteScript() const;
    bCString GetImage() const;
    GEInt GetModValue(bCString const &) const;
    bTObjArray<SScriptLine> &GetScript();
    bTObjArray<SScriptLine> const &GetScript() const;
    gESlot GetSlot() const;
    GEBool IsEquipped() const;
    GEBool IsVisible() const;
    void SetSlot(gESlot);
    void SetVisible(GEBool);

  protected:
    void Invalidate();

  private:
    GE_UNIMPL_MEMBERS(24)
};

GE_ASSERT_SIZEOF(gCItem_PS, 0x15c)

GE_ASSERT_PROPERTY(gCItem_PS, m_u32Amount, 0x14, 4)
GE_ASSERT_PROPERTY(gCItem_PS, m_u32Quality, 0x18, 4)
GE_ASSERT_PROPERTY(gCItem_PS, m_iGoldValue, 0x1c, 4)
GE_ASSERT_PROPERTY(gCItem_PS, m_bMissionItem, 0x20, 1)
GE_ASSERT_PROPERTY(gCItem_PS, m_bPermanent, 0x21, 1)
GE_ASSERT_PROPERTY(gCItem_PS, m_enuCategory, 0x24, 8)
GE_ASSERT_PROPERTY(gCItem_PS, m_strTexture, 0x2c, 4)
GE_ASSERT_PROPERTY(gCItem_PS, m_bDropped, 0x30, 1)
GE_ASSERT_PROPERTY(gCItem_PS, m_itemWorld, 0x34, 12)
GE_ASSERT_PROPERTY(gCItem_PS, m_itemInventory, 0x40, 12)
GE_ASSERT_PROPERTY(gCItem_PS, m_entArmorSet, 0x4c, 12)
GE_ASSERT_PROPERTY(gCItem_PS, m_entSpell, 0x58, 12)
GE_ASSERT_PROPERTY(gCItem_PS, m_entSkill, 0x64, 12)
GE_ASSERT_PROPERTY(gCItem_PS, m_bRobe, 0x70, 1)
GE_ASSERT_PROPERTY(gCItem_PS, m_bFullBody, 0x71, 1)
GE_ASSERT_PROPERTY(gCItem_PS, m_strReqAttrib1, 0x74, 4)
GE_ASSERT_PROPERTY(gCItem_PS, m_enuReqAttrib1, 0x78, 8)
GE_ASSERT_PROPERTY(gCItem_PS, m_iReqAttrib1, 0x80, 4)
GE_ASSERT_PROPERTY(gCItem_PS, m_strReqAttrib2, 0x84, 4)
GE_ASSERT_PROPERTY(gCItem_PS, m_enuReqAttrib2, 0x88, 8)
GE_ASSERT_PROPERTY(gCItem_PS, m_iReqAttrib2, 0x90, 4)
GE_ASSERT_PROPERTY(gCItem_PS, m_strReqAttrib3, 0x94, 4)
GE_ASSERT_PROPERTY(gCItem_PS, m_enuReqAttrib3, 0x98, 8)
GE_ASSERT_PROPERTY(gCItem_PS, m_iReqAttrib3, 0xa0, 4)
GE_ASSERT_PROPERTY(gCItem_PS, m_strReqAttrib4, 0xa4, 4)
GE_ASSERT_PROPERTY(gCItem_PS, m_enuReqAttrib4, 0xa8, 8)
GE_ASSERT_PROPERTY(gCItem_PS, m_iReqAttrib4, 0xb0, 4)
GE_ASSERT_PROPERTY(gCItem_PS, m_entRequiredSkill1, 0xb4, 12)
GE_ASSERT_PROPERTY(gCItem_PS, m_entRequiredSkill2, 0xc0, 12)
GE_ASSERT_PROPERTY(gCItem_PS, m_strModAttrib1, 0xcc, 4)
GE_ASSERT_PROPERTY(gCItem_PS, m_enuModAttrib1, 0xd0, 8)
GE_ASSERT_PROPERTY(gCItem_PS, m_iModAttrib1, 0xd8, 4)
GE_ASSERT_PROPERTY(gCItem_PS, m_strModAttrib2, 0xdc, 4)
GE_ASSERT_PROPERTY(gCItem_PS, m_enuModAttrib2, 0xe0, 8)
GE_ASSERT_PROPERTY(gCItem_PS, m_iModAttrib2, 0xe8, 4)
GE_ASSERT_PROPERTY(gCItem_PS, m_strModAttrib3, 0xec, 4)
GE_ASSERT_PROPERTY(gCItem_PS, m_enuModAttrib3, 0xf0, 8)
GE_ASSERT_PROPERTY(gCItem_PS, m_iModAttrib3, 0xf8, 4)
GE_ASSERT_PROPERTY(gCItem_PS, m_strModAttrib4, 0xfc, 4)
GE_ASSERT_PROPERTY(gCItem_PS, m_enuModAttrib4, 0x100, 8)
GE_ASSERT_PROPERTY(gCItem_PS, m_iModAttrib4, 0x108, 4)
GE_ASSERT_PROPERTY(gCItem_PS, m_strModAttrib5, 0x10c, 4)
GE_ASSERT_PROPERTY(gCItem_PS, m_enuModAttrib5, 0x110, 8)
GE_ASSERT_PROPERTY(gCItem_PS, m_iModAttrib5, 0x118, 4)
GE_ASSERT_PROPERTY(gCItem_PS, m_strModAttrib6, 0x11c, 4)
GE_ASSERT_PROPERTY(gCItem_PS, m_enuModAttrib6, 0x120, 8)
GE_ASSERT_PROPERTY(gCItem_PS, m_iModAttrib6, 0x128, 4)
GE_ASSERT_PROPERTY(gCItem_PS, m_entActivateSkill1, 0x12c, 12)
GE_ASSERT_PROPERTY(gCItem_PS, m_entActivateSkill2, 0x138, 12)
