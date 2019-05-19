#ifndef GS_PSMAGIC_H_INCLUDED
#define GS_PSMAGIC_H_INCLUDED

class gCMagic_PS;

GS_DECLARE_PROPERTYSET( PSMagic, gCMagic_PS )
public:
    GS_DECLARE_PROPERTY( AnimActionCast,      bCString )
    GS_DECLARE_PROPERTY( AnimActionPowerCast, bCString )
    GS_DECLARE_PROPERTY( AutoReload,          GEBool )
    GS_DECLARE_PROPERTY( CastType,            gECastType )
    GS_DECLARE_PROPERTY( EffectCasterCast,    bCString )
    GS_DECLARE_PROPERTY( EffectCasterHold,    bCString )
    GS_DECLARE_PROPERTY( EffectCasterLoad,    bCString )
    GS_DECLARE_PROPERTY( EffectCasterPower,   bCString )
    GS_DECLARE_PROPERTY( EffectItemCast,      bCString )
    GS_DECLARE_PROPERTY( EffectItemHold,      bCString )
    GS_DECLARE_PROPERTY( EffectItemLoad,      bCString )
    GS_DECLARE_PROPERTY( EffectItemPower,     bCString )
    GS_DECLARE_PROPERTY( EffectTargetCast,    bCString )
    GS_DECLARE_PROPERTY( EffectTargetLoad,    bCString )
    GS_DECLARE_PROPERTY( EffectTargetPower,   bCString )
    GS_DECLARE_PROPERTY( FuncOnCast,          bCString )
    GS_DECLARE_PROPERTY( FuncOnTargetHit,     bCString )
    GS_DECLARE_PROPERTY( MaxManaCost,         GEInt )
    GS_DECLARE_PROPERTY( MinManaCost,         GEInt )
    GS_DECLARE_PROPERTY( ReloadDelaySeconds,  GEFloat )
    GS_DECLARE_PROPERTY( SpellDeity,          gESpellDeity )
    GS_DECLARE_PROPERTY( SpellTarget,         gESpellTarget )
    GS_DECLARE_PROPERTY( SpellType,           gESpellType )

public:
    GEU32  GetReloadDelay( void ) const;
    Entity GetSpawn( void ) const;
    GEBool IsAutoReload( void ) const;
    GEBool IsQuickCast( void ) const;
    GEBool IsValid( void ) const;

};

#endif
