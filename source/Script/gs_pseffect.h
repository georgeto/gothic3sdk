#ifndef GS_PSEFFECT_H_INCLUDED
#define GS_PSEFFECT_H_INCLUDED

class gCEffect_PS;

GS_DECLARE_PROPERTYSET( PSEffect, gCEffect_PS )
public:
    GEBool IsRuntimeEffectStarted( bCString const & );
    GEBool IsValid( void ) const;
    GEBool StartEffect( bCString const &, GEBool );
    GEBool StartRuntimeEffect( bCString const & );
    GEBool StopAllRuntimeEffects( GEBool );
    void   StopEffect( GEBool );
    GEBool StopRuntimeEffect( bCString const &, GEBool );

};

#endif
