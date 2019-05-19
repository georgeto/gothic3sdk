#ifndef GE_PERLINNOISE_H_INCLUDED
#define GE_PERLINNOISE_H_INCLUDED

class GE_DLLIMPORT bCPerlinNoise :
    public bCNoise
{
    public: virtual void    SetSeed( GEInt );
    public: virtual GEFloat GetNoise( GEFloat ) const;
    public: virtual GEFloat GetNoise( GEFloat, GEFloat ) const;
    public: virtual GEFloat GetNoise( GEFloat, GEFloat, GEFloat ) const;
    public: virtual        ~bCPerlinNoise( void );

    protected:
        static GEInt * ms_piPermutations;

    public:
        static bCPerlinNoise & GE_STDCALL GetPerlinNoise( void );

    public:
        bEAlgorithm GetAlgorithm( void ) const;
        GEFloat     ImprovedNoise( GEFloat ) const;
        GEFloat     ImprovedNoise( GEFloat, GEFloat ) const;
        GEFloat     ImprovedNoise( GEFloat, GEFloat, GEFloat ) const;
        GEFloat     Noise( GEFloat ) const;
        GEFloat     Noise( GEFloat, GEFloat ) const;
        GEFloat     Noise( GEFloat, GEFloat, GEFloat ) const;
        void        SetAlgorithm( bEAlgorithm );

    protected:
        bCPerlinNoise( bCPerlinNoise const & );
        bCPerlinNoise( void );

    protected:
        bCPerlinNoise & operator =  ( bCPerlinNoise const & );
        bCOStream &     operator >> ( bCOStream & ) const;
        bCIStream &     operator << ( bCIStream & );

    protected:
        void   CopyFrom( bCPerlinNoise const & );
        void   CopyTo( bCPerlinNoise & ) const;
        void   Initialize( GEInt );
        void   Invalidate( void );
        GEBool Read( bCIStream & );
        void   Write( bCOStream & ) const;

};

#endif
