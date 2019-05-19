#ifndef GS_PSITEM_H_INCLUDED
#define GS_PSITEM_H_INCLUDED

class gCItem_PS;

GS_DECLARE_PROPERTYSET( PSItem, gCItem_PS )
public:
    GEBool         ExecuteScript( void ) const;
    GEU32          GetAmount( void ) const;
    gEItemCategory GetCategory( void ) const;
    GEInt          GetGoldValue( void ) const;
    GEU32          GetQuality( void ) const;
    Entity         GetSkill( void ) const;
    Entity         GetSpell( void ) const;
    GEBool         IsDropped( void ) const;
    GEBool         IsEquipped( void ) const;
    GEBool         IsFullBody( void ) const;
    GEBool         IsMissionItem( void ) const;
    GEBool         IsRobe( void ) const;
    GEBool         IsValid( void ) const;
    void           ModifyQuality( GEU32, GEU32 );
    void           SetAmount( GEU32 );
};

#endif
