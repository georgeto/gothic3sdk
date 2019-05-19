#ifndef GS_PSFOCUS_H_INCLUDED
#define GS_PSFOCUS_H_INCLUDED

class gCFocus_PS;
enum gECombatMode;

GS_DECLARE_PROPERTYSET( PSFocus, gCFocus_PS )
public:
    GS_DECLARE_PROPERTY( CurrentMode,               gEFocus )
    GS_DECLARE_PROPERTY( EnableRangeRating,         GEBool )
    GS_DECLARE_PROPERTY( FocusLookAtKeysFOR,        gEFocusLookAtKeysFOR )
    GS_DECLARE_PROPERTY( FocusLookAtMode,           gEFocusLookAt )
    GS_DECLARE_PROPERTY( OverrideCharacterPriority, GEFloat )
    GS_DECLARE_PROPERTY( OverrideInteractPriority,  GEFloat )
    GS_DECLARE_PROPERTY( OverrideItemPriority,      GEFloat )
    GS_DECLARE_PROPERTY( OverrideRange,             GEFloat )

public:
    Entity FindFocusEntity( void ) const;
    Entity GetCrossHairEntity( void ) const;
    Entity GetFocusEntity( gECombatMode, gEDirection ) const;
    Entity GetFocusEntity( void ) const;
    GEBool IsValid( void ) const;
    void   SetFocusEntity( Entity const & );

};

#endif
