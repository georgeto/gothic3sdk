#pragma once

#include <Game/GameEnum.h>

#include <Engine.h>

class GE_DLLIMPORT gCRecipe_PS : public eCEntityPropertySet
{
    // clang-format off
    public: GEU16 GetVersion() const override;
    public: bEResult Write(bCOStream &) override;
    public: bEResult Read(bCIStream &) override;
    public: void Destroy() override;
    public: bEResult Create() override;
    public: bEResult CopyFrom(bCObjectBase const &) override;
    public: ~gCRecipe_PS() override;
    public: bEResult PostInitializeProperties() override;
    public: eEPropertySetType GetPropertySetType() const override;
    public: GEBool IsEditorRelevant() const override;
    // clang-format on

  public:
    GE_PROPERTY_SET(gCRecipe_PS, eCEntityPropertySet)
    GE_ENUMPROP(gESkillCategory, Craft, m_enuCraft)
    GE_PROPERTY(eCTemplateEntityProxy, Ingredient1Item, m_entIngredient1Item)
    GE_PROPERTY(GEU32, Ingredient1Amount, m_u32Ingredient1Amount)
    GE_PROPERTY(eCTemplateEntityProxy, Ingredient2Item, m_entIngredient2Item)
    GE_PROPERTY(GEU32, Ingredient2Amount, m_u32Ingredient2Amount)
    GE_PROPERTY(eCTemplateEntityProxy, Ingredient3Item, m_entIngredient3Item)
    GE_PROPERTY(GEU32, Ingredient3Amount, m_u32Ingredient3Amount)
    GE_PROPERTY(eCTemplateEntityProxy, Ingredient4Item, m_entIngredient4Item)
    GE_PROPERTY(GEU32, Ingredient4Amount, m_u32Ingredient4Amount)
    GE_PROPERTY(eCTemplateEntityProxy, ReqSkill1, m_entReqSkill1)
    GE_PROPERTY(bCString, ReqAttrib1Tag, m_entReqAttrib1Tag)
    GE_PROPERTY(GEU32, ReqAttrib1Value, m_u32ReqAttrib1Value)
    GE_PROPERTY(eCTemplateEntityProxy, ResultItem, m_entResultItem)
    GE_PROPERTY(GEU32, ResultQuality, m_u32ResultQuality)
    GE_PROPERTY(GEU32, ResultAmount, m_u32ResultAmount)

  public:
    GEInt CompareTo(gCRecipe_PS const &) const;

  protected:
    void Invalidate();
};

GE_ASSERT_SIZEOF(gCRecipe_PS, 0x84)

GE_ASSERT_PROPERTY(gCRecipe_PS, m_enuCraft, 0x14, 8)
GE_ASSERT_PROPERTY(gCRecipe_PS, m_entIngredient1Item, 0x1c, 12)
GE_ASSERT_PROPERTY(gCRecipe_PS, m_u32Ingredient1Amount, 0x28, 4)
GE_ASSERT_PROPERTY(gCRecipe_PS, m_entIngredient2Item, 0x2c, 12)
GE_ASSERT_PROPERTY(gCRecipe_PS, m_u32Ingredient2Amount, 0x38, 4)
GE_ASSERT_PROPERTY(gCRecipe_PS, m_entIngredient3Item, 0x3c, 12)
GE_ASSERT_PROPERTY(gCRecipe_PS, m_u32Ingredient3Amount, 0x48, 4)
GE_ASSERT_PROPERTY(gCRecipe_PS, m_entIngredient4Item, 0x4c, 12)
GE_ASSERT_PROPERTY(gCRecipe_PS, m_u32Ingredient4Amount, 0x58, 4)
GE_ASSERT_PROPERTY(gCRecipe_PS, m_entReqSkill1, 0x5c, 12)
GE_ASSERT_PROPERTY(gCRecipe_PS, m_entReqAttrib1Tag, 0x68, 4)
GE_ASSERT_PROPERTY(gCRecipe_PS, m_u32ReqAttrib1Value, 0x6c, 4)
GE_ASSERT_PROPERTY(gCRecipe_PS, m_entResultItem, 0x70, 12)
GE_ASSERT_PROPERTY(gCRecipe_PS, m_u32ResultQuality, 0x7c, 4)
GE_ASSERT_PROPERTY(gCRecipe_PS, m_u32ResultAmount, 0x80, 4)
