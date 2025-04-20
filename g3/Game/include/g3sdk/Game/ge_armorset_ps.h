#pragma once

#include <Game/GameEnum.h>

#include <Engine.h>

class GE_DLLIMPORT gCArmorSet_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCArmorSet_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsEditorRelevant() const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCArmorSet_PS, eCEntityPropertySet)
    GE_PROPERTY(eCTemplateEntityProxy, Head, m_entHead)
    GE_PROPERTY(eCTemplateEntityProxy, Body, m_entBody)
    GE_PROPERTY(eCTemplateEntityProxy, Hand1, m_entHand1)
    GE_PROPERTY(eCTemplateEntityProxy, Hand2, m_entHand2)
    GE_PROPERTY(eCTemplateEntityProxy, Ring1, m_entRing1)
    GE_PROPERTY(eCTemplateEntityProxy, Ring2, m_entRing2)
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

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(gCArmorSet_PS, 0xd4)

GE_ASSERT_PROPERTY(gCArmorSet_PS, m_entHead, 0x14, 12)
GE_ASSERT_PROPERTY(gCArmorSet_PS, m_entBody, 0x20, 12)
GE_ASSERT_PROPERTY(gCArmorSet_PS, m_entHand1, 0x2c, 12)
GE_ASSERT_PROPERTY(gCArmorSet_PS, m_entHand2, 0x38, 12)
GE_ASSERT_PROPERTY(gCArmorSet_PS, m_entRing1, 0x44, 12)
GE_ASSERT_PROPERTY(gCArmorSet_PS, m_entRing2, 0x50, 12)
GE_ASSERT_PROPERTY(gCArmorSet_PS, m_strModAttrib1, 0x5c, 4)
GE_ASSERT_PROPERTY(gCArmorSet_PS, m_enuModAttrib1, 0x60, 8)
GE_ASSERT_PROPERTY(gCArmorSet_PS, m_iModAttrib1, 0x68, 4)
GE_ASSERT_PROPERTY(gCArmorSet_PS, m_strModAttrib2, 0x6c, 4)
GE_ASSERT_PROPERTY(gCArmorSet_PS, m_enuModAttrib2, 0x70, 8)
GE_ASSERT_PROPERTY(gCArmorSet_PS, m_iModAttrib2, 0x78, 4)
GE_ASSERT_PROPERTY(gCArmorSet_PS, m_strModAttrib3, 0x7c, 4)
GE_ASSERT_PROPERTY(gCArmorSet_PS, m_enuModAttrib3, 0x80, 8)
GE_ASSERT_PROPERTY(gCArmorSet_PS, m_iModAttrib3, 0x88, 4)
GE_ASSERT_PROPERTY(gCArmorSet_PS, m_strModAttrib4, 0x8c, 4)
GE_ASSERT_PROPERTY(gCArmorSet_PS, m_enuModAttrib4, 0x90, 8)
GE_ASSERT_PROPERTY(gCArmorSet_PS, m_iModAttrib4, 0x98, 4)
GE_ASSERT_PROPERTY(gCArmorSet_PS, m_strModAttrib5, 0x9c, 4)
GE_ASSERT_PROPERTY(gCArmorSet_PS, m_enuModAttrib5, 0xa0, 8)
GE_ASSERT_PROPERTY(gCArmorSet_PS, m_iModAttrib5, 0xa8, 4)
GE_ASSERT_PROPERTY(gCArmorSet_PS, m_strModAttrib6, 0xac, 4)
GE_ASSERT_PROPERTY(gCArmorSet_PS, m_enuModAttrib6, 0xb0, 8)
GE_ASSERT_PROPERTY(gCArmorSet_PS, m_iModAttrib6, 0xb8, 4)
GE_ASSERT_PROPERTY(gCArmorSet_PS, m_entActivateSkill1, 0xbc, 12)
GE_ASSERT_PROPERTY(gCArmorSet_PS, m_entActivateSkill2, 0xc8, 12)
