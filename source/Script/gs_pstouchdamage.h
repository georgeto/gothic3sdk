#ifndef GS_PSTOUCHDAMAGE_H_INCLUDED
#define GS_PSTOUCHDAMAGE_H_INCLUDED

class gCTouchDamage_PS;

GS_DECLARE_PROPERTYSET( PSTouchDamage, gCTouchDamage_PS )
public:
    GS_DECLARE_PROPERTY( ResetOnUntouch, GEBool )

public:
    void   ClearTriggeredList( void );
    Entity GetInflictor( void );
    GEBool IsValid( void ) const;

};

#endif
