#ifndef GE_NOISE_H_INCLUDED
#define GE_NOISE_H_INCLUDED

enum bENoiseAmplitude;

class GE_DLLIMPORT bCNoise
{
    public: virtual void    SetSeed( GEInt )                            = 0;
    public: virtual GEFloat GetNoise( GEFloat ) const                   = 0;
    public: virtual GEFloat GetNoise( GEFloat, GEFloat ) const          = 0;
    public: virtual GEFloat GetNoise( GEFloat, GEFloat, GEFloat ) const = 0;
    public: virtual        ~bCNoise( void );

    public:
        GEFloat GetNoise( bCVector2 const & ) const;
        GEFloat GetNoise( bCVector const & ) const;
        GEFloat GetTurbulence( bCVector2 const &, GEInt, GEInt, bENoiseTurbulence, bENoiseAmplitude, GEFloat ) const;
        GEFloat GetTurbulence( bCVector const &, GEInt, GEInt, bENoiseTurbulence, bENoiseAmplitude, GEFloat ) const;
        GEFloat GetTurbulence( GEFloat, GEInt, GEInt, bENoiseTurbulence, bENoiseAmplitude, GEFloat ) const;
        GEFloat GetTurbulence( GEFloat, GEFloat, GEInt, GEInt, bENoiseTurbulence, bENoiseAmplitude, GEFloat ) const;
        GEFloat GetTurbulence( GEFloat, GEFloat, GEFloat, GEInt, GEInt, bENoiseTurbulence, bENoiseAmplitude, GEFloat ) const;
        void    SetTimedSeed( void );

    protected:
        bCNoise( bCNoise const & );
        bCNoise( void );

    protected:
        bCNoise & operator = ( bCNoise const & );

    protected:
        void CopyFrom( bCNoise const & );
        void CopyTo( bCNoise & ) const;

};

#endif
