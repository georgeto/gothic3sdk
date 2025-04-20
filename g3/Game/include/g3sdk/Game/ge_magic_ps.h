#pragma once

#include <Game/GameEnum.h>

#include <Engine.h>

class GE_DLLIMPORT gCMagic_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCMagic_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsEditorRelevant() const override;
    public: GEBool SupportsRenderDebugOutput() const override;
    public: void GetDependencies(bTValArray<bCString> &, bTValArray<bCString> &, bTObjArray<eCTemplateEntityProxy> &) override;
    public: void GetOnScreenDebugLines(GEU32, bTObjArray<eSPropertySetDebugLine> &) const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCMagic_PS, eCEntityPropertySet)
    GE_ENUMPROP(gESpellDeity, SpellDeity, m_enuSpellDeity)
    GE_ENUMPROP(gESpellType, SpellType, m_enuSpellType)
    GE_PROPERTY(GEInt, MinManaCost, m_iMinManaCost)
    GE_PROPERTY(GEInt, MaxManaCost, m_iMaxManaCost)
    GE_ENUMPROP(gESpellTarget, SpellTarget, m_enuSpellTarget)
    GE_ENUMPROP(gECastType, CastType, m_enuCastType)
    GE_PROPERTY(GEBool, AutoReload, m_bAutoReload)
    GE_PADDING(3)
    GE_PROPERTY(GEFloat, ReloadDelaySeconds, m_fReloadDelaySeconds)
    GE_PROPERTY(bCString, AnimActionCast, m_strAnimActionCast)
    GE_PROPERTY(bCString, AnimActionPowerCast, m_strAnimActionPowerCast)
    GE_PROPERTY(eCTemplateEntityProxy, Spawn, m_entSpawn)
    GE_PROPERTY(bCString, EffectItemHold, m_strEffectItemHold)
    GE_PROPERTY(bCString, EffectItemLoad, m_strEffectItemLoad)
    GE_PROPERTY(bCString, EffectItemPower, m_strEffectItemPower)
    GE_PROPERTY(bCString, EffectItemCast, m_strEffectItemCast)
    GE_PROPERTY(bCString, EffectCasterHold, m_strEffectCasterHold)
    GE_PROPERTY(bCString, EffectCasterLoad, m_strEffectCasterLoad)
    GE_PROPERTY(bCString, EffectCasterPower, m_strEffectCasterPower)
    GE_PROPERTY(bCString, EffectCasterCast, m_strEffectCasterCast)
    GE_PROPERTY(bCString, EffectTargetLoad, m_strEffectTargetLoad)
    GE_PROPERTY(bCString, EffectTargetPower, m_strEffectTargetPower)
    GE_PROPERTY(bCString, EffectTargetCast, m_strEffectTargetCast)
    GE_PROPERTY(bCString, FuncOnCast, m_strScriptOnCast)
    GE_PROPERTY(bCString, FuncOnTargetHit, m_strScriptOnTargetHit)
    GE_PROPERTY(GEInt, LearnPoints, m_iLearnPoints)
    GE_PROPERTY(bCString, ReqAttrib1Tag, m_strReqAttrib1)
    GE_PROPERTY(GEInt, ReqAttrib1Value, m_iReqAttrib1)
    GE_PROPERTY(bCString, ReqAttrib2Tag, m_strReqAttrib2)
    GE_PROPERTY(GEInt, ReqAttrib2Value, m_iReqAttrib2)
    GE_PROPERTY(bCString, ReqAttrib3Tag, m_strReqAttrib3)
    GE_PROPERTY(GEInt, ReqAttrib3Value, m_iReqAttrib3)
    GE_PROPERTY(bCString, ReqAttrib4Tag, m_strReqAttrib4)
    GE_PROPERTY(GEInt, ReqAttrib4Value, m_iReqAttrib4)
    GE_PROPERTY(eCTemplateEntityProxy, ReqSkill1, m_entReqSkill1)

  public:
    GEInt CompareTo(gCMagic_PS const &) const;
    GEInt GetReqINT() const;

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(gCMagic_PS, 0xbc)

GE_ASSERT_PROPERTY(gCMagic_PS, m_enuSpellDeity, 0x14, 8)
GE_ASSERT_PROPERTY(gCMagic_PS, m_enuSpellType, 0x1c, 8)
GE_ASSERT_PROPERTY(gCMagic_PS, m_iMinManaCost, 0x24, 4)
GE_ASSERT_PROPERTY(gCMagic_PS, m_iMaxManaCost, 0x28, 4)
GE_ASSERT_PROPERTY(gCMagic_PS, m_enuSpellTarget, 0x2c, 8)
GE_ASSERT_PROPERTY(gCMagic_PS, m_enuCastType, 0x34, 8)
GE_ASSERT_PROPERTY(gCMagic_PS, m_bAutoReload, 0x3c, 1)
GE_ASSERT_PROPERTY(gCMagic_PS, m_fReloadDelaySeconds, 0x40, 4)
GE_ASSERT_PROPERTY(gCMagic_PS, m_strAnimActionCast, 0x44, 4)
GE_ASSERT_PROPERTY(gCMagic_PS, m_strAnimActionPowerCast, 0x48, 4)
GE_ASSERT_PROPERTY(gCMagic_PS, m_entSpawn, 0x4c, 12)
GE_ASSERT_PROPERTY(gCMagic_PS, m_strEffectItemHold, 0x58, 4)
GE_ASSERT_PROPERTY(gCMagic_PS, m_strEffectItemLoad, 0x5c, 4)
GE_ASSERT_PROPERTY(gCMagic_PS, m_strEffectItemPower, 0x60, 4)
GE_ASSERT_PROPERTY(gCMagic_PS, m_strEffectItemCast, 0x64, 4)
GE_ASSERT_PROPERTY(gCMagic_PS, m_strEffectCasterHold, 0x68, 4)
GE_ASSERT_PROPERTY(gCMagic_PS, m_strEffectCasterLoad, 0x6c, 4)
GE_ASSERT_PROPERTY(gCMagic_PS, m_strEffectCasterPower, 0x70, 4)
GE_ASSERT_PROPERTY(gCMagic_PS, m_strEffectCasterCast, 0x74, 4)
GE_ASSERT_PROPERTY(gCMagic_PS, m_strEffectTargetLoad, 0x78, 4)
GE_ASSERT_PROPERTY(gCMagic_PS, m_strEffectTargetPower, 0x7c, 4)
GE_ASSERT_PROPERTY(gCMagic_PS, m_strEffectTargetCast, 0x80, 4)
GE_ASSERT_PROPERTY(gCMagic_PS, m_strScriptOnCast, 0x84, 4)
GE_ASSERT_PROPERTY(gCMagic_PS, m_strScriptOnTargetHit, 0x88, 4)
GE_ASSERT_PROPERTY(gCMagic_PS, m_iLearnPoints, 0x8c, 4)
GE_ASSERT_PROPERTY(gCMagic_PS, m_strReqAttrib1, 0x90, 4)
GE_ASSERT_PROPERTY(gCMagic_PS, m_iReqAttrib1, 0x94, 4)
GE_ASSERT_PROPERTY(gCMagic_PS, m_strReqAttrib2, 0x98, 4)
GE_ASSERT_PROPERTY(gCMagic_PS, m_iReqAttrib2, 0x9c, 4)
GE_ASSERT_PROPERTY(gCMagic_PS, m_strReqAttrib3, 0xa0, 4)
GE_ASSERT_PROPERTY(gCMagic_PS, m_iReqAttrib3, 0xa4, 4)
GE_ASSERT_PROPERTY(gCMagic_PS, m_strReqAttrib4, 0xa8, 4)
GE_ASSERT_PROPERTY(gCMagic_PS, m_iReqAttrib4, 0xac, 4)
GE_ASSERT_PROPERTY(gCMagic_PS, m_entReqSkill1, 0xb0, 12)
