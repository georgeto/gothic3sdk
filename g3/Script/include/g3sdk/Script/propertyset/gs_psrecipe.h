#pragma once

#include "gs_propertymacros.h"

#include <Game.h>

class GE_DLLIMPORT PSRecipe : public EntityPropertySet
{
  public:
    GS_PROPERTY_SET(PSRecipe, gCRecipe_PS)
    GS_PROPERTY(gESkillCategory, Craft)
    GS_PROPERTY(GEU32, Ingredient1Amount)
    GS_PROPERTY(GEU32, Ingredient2Amount)
    GS_PROPERTY(GEU32, Ingredient3Amount)
    GS_PROPERTY(GEU32, Ingredient4Amount)
    GS_PROPERTY(bCString, ReqAttrib1Tag)
    GS_PROPERTY(GEU32, ReqAttrib1Value)
    GS_PROPERTY(GEU32, ResultAmount)
    GS_PROPERTY(GEU32, ResultQuality)

  public:
    Entity GetIngredient1Item() const;
    Entity GetIngredient2Item() const;
    Entity GetIngredient3Item() const;
    Entity GetIngredient4Item() const;
    Entity GetReqSkill1() const;
    Entity GetResultItem() const;
};
