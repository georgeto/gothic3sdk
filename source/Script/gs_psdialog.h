#ifndef GS_PSDIALOG_H_INCLUDED
#define GS_PSDIALOG_H_INCLUDED

class gCDialog_PS;

GS_DECLARE_PROPERTYSET( PSDialog, gCDialog_PS )
public:
    GS_DECLARE_PROPERTY( EndDialogTimestamp, GEFloat )
    GS_DECLARE_PROPERTY( MobEnabled,         GEBool )
    GS_DECLARE_PROPERTY( PartyEnabled,       GEBool )
    GS_DECLARE_PROPERTY( PickedPocket,       GEBool )
    GS_DECLARE_PROPERTY( SlaveryEnabled,     GEBool )
    GS_DECLARE_PROPERTY( TalkedToPlayer,     GEBool )
    GS_DECLARE_PROPERTY( TeachEnabled,       GEBool )
    GS_DECLARE_PROPERTY( TradeCategory,      gETradeCategory )
    GS_DECLARE_PROPERTY( TradeEnabled,       GEBool )

public:
    void   BeginTalkedToBy( Entity const & );
    void   BeginTalkingTo( Entity const & );
    void   EndTalkedToBy( Entity const & );
    void   EndTalkingTo( Entity const & );
    GEBool IsBeingTalkedTo( void ) const;
    GEBool IsTalking( void ) const;
    GEBool IsValid( void ) const;

};

#endif
