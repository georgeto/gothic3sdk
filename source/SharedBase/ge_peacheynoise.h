#ifndef GE_PEACHEYNOISE_H_INCLUDED
#define GE_PEACHEYNOISE_H_INCLUDED

enum bEAlgorithm;

class GE_DLLIMPORT bCPeacheyNoise :
    public bCNoise
{
    public: virtual void    SetSeed( GEInt );
    public: virtual GEFloat GetNoise( GEFloat ) const;
    public: virtual GEFloat GetNoise( GEFloat, GEFloat ) const;
    public: virtual GEFloat GetNoise( GEFloat, GEFloat, GEFloat ) const;
    public: virtual        ~bCPeacheyNoise( void );

    protected:
        static GELPByte ms_pu8Permutations;

    public:
        static bCPeacheyNoise & GE_STDCALL GetPeacheyNoise( void );

    public:
        GEFloat     GNoise( GEFloat, GEFloat, GEFloat ) const;
        GEFloat     GVNoise( GEFloat, GEFloat, GEFloat, GEFloat ) const;
        bEAlgorithm GetAlgorithm( void ) const;
        GEFloat     SCNoise( GEFloat, GEFloat, GEFloat ) const;
        void        SetAlgorithm( bEAlgorithm );
        GEFloat     VCNoise( GEFloat, GEFloat, GEFloat ) const;
        GEFloat     VNoise( GEFloat, GEFloat, GEFloat ) const;

    protected:
        bCPeacheyNoise( bCPeacheyNoise const & );
        bCPeacheyNoise( void );

    protected:
        bCPeacheyNoise & operator =  ( bCPeacheyNoise const & );
        bCOStream &      operator >> ( bCOStream & ) const;
        bCIStream &      operator << ( bCIStream & );

    protected:
        GEFloat CatRom2( GEFloat ) const;
        void    CopyFrom( bCPeacheyNoise const & );
        void    CopyTo( bCPeacheyNoise & ) const;
        GEFloat GLattice( GEInt, GEInt, GEInt, GEFloat, GEFloat, GEFloat ) const;
        void    Initialize( GEInt );
        void    Invalidate( void );
        GEBool  Read( bCIStream & );
        GEFloat Spline( GEFloat, GEInt, GEFloat const * ) const;
        GEFloat VLattice( GEInt, GEInt, GEInt ) const;
        void    Write( bCOStream & ) const;

};

#endif
