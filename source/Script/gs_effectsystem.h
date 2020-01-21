#ifndef GS_EFFECTSYSTEM_H_INCLUDED
#define GS_EFFECTSYSTEM_H_INCLUDED

class GE_DLLIMPORT EffectSystem
{
    public:
        static GEBool GE_STDCALL ExistsEffect( bCString const & );
        static Effect GE_STDCALL StartEffect( bCString const &, Entity const &, Entity const & );
        static Effect GE_STDCALL StartEffect( bCString const &, Entity const & );
        static Effect GE_STDCALL StartEffect( bCString const &, bCMatrix const & );
        static Effect GE_STDCALL StartEffect( bCString const &, bCMatrix const &, Entity const & );
        static Effect GE_STDCALL StartEffect( bCString const &, bCVector const & );
        static Effect GE_STDCALL StartEffect( bCString const &, bCVector const &, Entity const & );
        static GEBool GE_STDCALL StopEffect( Effect const &, GEBool a_bDecay );

    public:
         EffectSystem( void );
        ~EffectSystem( void );

    public:
        EffectSystem & operator = ( EffectSystem const & );

};

#endif
