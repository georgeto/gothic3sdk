#ifndef GE_EBERTNOISE_H_INCLUDED
#define GE_EBERTNOISE_H_INCLUDED

class GE_DLLIMPORT bCEbertNoise :
    public bCNoise
{
    public: virtual void    SetSeed( GEInt );
    public: virtual GEFloat GetNoise( GEFloat ) const;
    public: virtual GEFloat GetNoise( GEFloat, GEFloat ) const;
    public: virtual GEFloat GetNoise( GEFloat, GEFloat, GEFloat ) const;
    public: virtual        ~bCEbertNoise( void );

    public:
        static bCEbertNoise & GE_STDCALL GetEbertNoise( void );

    protected:
        bCEbertNoise( bCEbertNoise const & );
        bCEbertNoise( void );

    protected:
        bCEbertNoise & operator =  ( bCEbertNoise const & );
        bCOStream &    operator >> ( bCOStream & ) const;
        bCIStream &    operator << ( bCIStream & );

    protected:
        void   CopyFrom( bCEbertNoise const & );
        void   CopyTo( bCEbertNoise & ) const;
        void   Initialize( GEInt );
        void   Invalidate( void );
        GEBool Read( bCIStream & );
        void   Write( bCOStream & ) const;

};

#endif
