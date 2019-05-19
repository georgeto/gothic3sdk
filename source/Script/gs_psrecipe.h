#ifndef GS_PSRECIPE_H_INCLUDED
#define GS_PSRECIPE_H_INCLUDED

class gCRecipe_PS;

GS_DECLARE_PROPERTYSET( PSRecipe, gCRecipe_PS )
public:
    GS_DECLARE_PROPERTY( Craft,             gESkillCategory )
    GS_DECLARE_PROPERTY( Ingredient1Amount, GEU32 )
    GS_DECLARE_PROPERTY( Ingredient2Amount, GEU32 )
    GS_DECLARE_PROPERTY( Ingredient3Amount, GEU32 )
    GS_DECLARE_PROPERTY( Ingredient4Amount, GEU32 )
    GS_DECLARE_PROPERTY( ReqAttrib1Tag,     bCString )
    GS_DECLARE_PROPERTY( ReqAttrib1Value,   GEU32 )
    GS_DECLARE_PROPERTY( ResultAmount,      GEU32 )
    GS_DECLARE_PROPERTY( ResultQuality,     GEU32 )

public:
    Entity GetIngredient1Item( void ) const;
    Entity GetIngredient2Item( void ) const;
    Entity GetIngredient3Item( void ) const;
    Entity GetIngredient4Item( void ) const;
    Entity GetReqSkill1( void ) const;
    Entity GetResultItem( void ) const;
    GEBool IsValid( void ) const;

};

#endif