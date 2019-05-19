#ifndef GE_RANDOM_H_INCLUDED
#define GE_RANDOM_H_INCLUDED

class GE_DLLIMPORT bCRandom
{

    public:
        static bCRandom const & GE_STDCALL GetRandom( void );

    public:
        ~bCRandom( void );

    public:
        GEDouble DRand48( GEDouble, GEDouble ) const;
        GEDouble DRand48( void ) const;
        GEFloat  FRand48( GEFloat, GEFloat ) const;
        GEFloat  FRand48( void ) const;
        GEInt    GetValue( GEInt, GEInt ) const;
        GEInt    GetValue( void ) const;
        GEFloat  GetValue( GEFloat, GEFloat ) const;
        void     SetSeed( GEInt ) const;
        void     SetTimedSeed( void ) const;

    protected:
        bCRandom( bCRandom const & );
        bCRandom( void );

    protected:
        bCRandom & operator = ( bCRandom const & );

    protected:
        void Invalidate( void );

};

#endif
